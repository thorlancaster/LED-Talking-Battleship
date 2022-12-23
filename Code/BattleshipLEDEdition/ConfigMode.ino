void configMode() {
  char cmd[32];
  byte cmdPtr = 0;
  SNDEN = false; // So we can use the SND buffer for writing the flash
  Serial.print(F("Command Mode"));
  while (true) {
    while (Serial.available()) {
      char c = Serial.read();
      if (c == '\n') {
        cmd[cmdPtr] = 0;
        Serial.print(F("Command: "));
        Serial.println(cmd);
        cmdPtr = 0;
        if (cmd[0] == 'u' && cmd[1] == 'p' && cmd[2] == 'l' && cmd[3] == 'o' && cmd[4] == 'a' && cmd[5] == 'd' && cmd[6] == 0) {
          configModeUpload();
        }
        if (cmd[0] == 'r' && cmd[1] == 'e' && cmd[2] == 'a' && cmd[3] == 'd' && cmd[4] == 0) {
          configModeRead();
        }
        if (cmd[0] == 't' && cmd[1] == 'e' && cmd[2] == 's' && cmd[3] == 't' && cmd[4] == 0) {
          configModeTest();
        }
      }
      else {
        if (cmdPtr < sizeof(cmd) - 1)
          cmd[cmdPtr++] = c;
      }

    }
  }
}

void configModeTest() {
  for (int x = 0; x < 288; x++) {
    writeRam(x, x & 7);
    Serial.print(F("Wrote ram at "));
    Serial.print(x);
    Serial.print(',');
    Serial.println((x) & 7);
  }
  for (int x = 0; x < 288; x++) {
    byte res = readRam(x);
    byte goodRes = x & 7;
    Serial.print(F("Read ram at "));
    Serial.print(x);
    Serial.print(',');
    Serial.println(res);
    if (res != goodRes) {
      Serial.print(F("BAD READ: Correct= "));
      Serial.println(goodRes);
    }
  }
}

void configModeRead() {
  Serial.println(F("Writing Flash to Serial console"));
  uint16_t pageNbr = 0;
  while (true) {
    SFReadPage(pageNbr++, sndBuf);
    if (pageNbr == 0)
      Serial.println(F("End of address space, done"));
    for (int x = 0; x < 256; x++) {
      if (sndBuf[x] != 0xFF)
        break;
      if (x == 255) {
        Serial.println(F("Read entire page of 0xFFs, done"));
        return;
      }
    }
    for (int x = 0; x < 256; x++) {
      Serial.write(sndBuf[x]);
    }
  }
}

void configModeUpload() {
  Serial.println(F("Upload mode\nErasing flash..."));
  SFChipErase();
  while (Serial.available()) // Ensure Serial buffer is empty
    Serial.read();
  Serial.println(F("Done.\nUpload file and then reboot"));
  uint16_t pageNbr = 0;
  uint16_t pagePtr = 0;
  uint32_t lastMs = 0;
  bool dropSwitch = false;
  while (true) {
    if (Serial.available()) {
      if (dropSwitch)
        Serial.read();
      else
        sndBuf[pagePtr++] = Serial.read();
      //      dropSwitch = !dropSwitch; // Uncomment to skip every other byte
      lastMs = Millis();
    }
    if (pagePtr == 256) {
      pagePtr = 0;
      SFWritePage(pageNbr++, sndBuf);
    }
    if (lastMs > 0 && Millis() - lastMs > 1000) {
      Serial.println(F("Data stream stopped for 1000ms, done"));
      for (uint16_t x = pagePtr; x < 256; x++)
        sndBuf[x] = 0xFF;
      SFWritePage(pageNbr++, sndBuf);
      return;
    }
  }
}
