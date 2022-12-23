void easterEggNyanCat() {
  delay(INTER_SND_DELAY);
  sndPlaySynchronous(SND_GAME);  // ---------------- ANNOUNCE GAME SELECTION
  delay(INTER_SND_DELAY / 2);
  if (true) {
    byte cnt = 0;
    while (!getTfxNum(0)) {
      if (!SNDEN)
        sndPlay(SND_NYAN);

      for (byte i = 0; i < 4; i++) {
        for (byte x = 0; x < 12; x++) {
          for (byte y = 0; y < 12; y++) {
            byte sum = ((i * 6) + x + y + cnt) % 9;
            if (sum == 0)
              setLED(i, x, y, B110000);
            if (sum == 1)
              setLED(i, x, y, B110100);
            if (sum == 2)
              setLED(i, x, y, B111100);
            if (sum == 3)
              setLED(i, x, y, B001100);
            if (sum == 4)
              setLED(i, x, y, B001110);
            if (sum == 5)
              setLED(i, x, y, B000011);
            if (sum == 6)
              setLED(i, x, y, B110011);
            if (sum == 7)
              setLED(i, x, y, B111111);
            if (sum == 8)
              setLED(i, x, y, B000000);
          }
        }
        sndService();
      }
      cnt = (cnt + 1) % 9;
      Delay(65);
    }
  }
  SNDEN = false;
  clearLEDs();
}

void easterEggDBG() { // Battery is red
  delay(INTER_SND_DELAY);
  sndPlaySynchronous(SND_GAME);  // ---------------- ANNOUNCE GAME SELECTION
  delay(INTER_SND_DELAY / 2);
  if (true) {
    byte cnt = 0;
    byte j = 0;
    while (!getTfxNum(0)) {
      j = getBattLevel() / 56;
      for(byte i = 0; i < 143; i++){
        setLED(0, i/12, i%12, i < j ? B110000 : B000000);
      }
      setLED(0, 11, 11, isCharging() ? B111111: B000000);
      sndService();
      Delay(10);
    }
  }
  SNDEN = false;
  clearLEDs();
}

void easterEggDBG2() { // USB is green
  delay(INTER_SND_DELAY);
  sndPlaySynchronous(SND_GAME);  // ---------------- ANNOUNCE GAME SELECTION
  delay(INTER_SND_DELAY / 2);
  if (true) {
    byte cnt = 0;
    byte j = 0;
    while (!getTfxNum(0)) {
      j = getVUsbLevel() / 56;
      for(byte i = 0; i < 143; i++){
        setLED(0, i/12, i%12, i < j ? B001100 : B000000);
      }
      setLED(0, 11, 11, isCharging() ? B111111: B000000);
      sndService();
      Delay(10);
    }
  }
  SNDEN = false;
  clearLEDs();
}
