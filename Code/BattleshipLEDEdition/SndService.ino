static uint16_t sndStartPageNum = 2;
static uint16_t sndPageNum = 0;
static uint16_t sndEndPageNum = 134;

// Update the user-mode sound service
// This function must be called often enough to fill the buffer when playing sound or glitching will result.
void sndService() {
  //      setMainLED((!digitalRead(8)) * 255, 0, 0, 0);
  int readPtr = getSndPtr();
  if ((readPtr > 0 && readPtr < 256 && sndWritePtr == 256) || (readPtr > 256 && sndWritePtr == 0)) {
    if (sndPageNum <= sndEndPageNum)
      sndWritePtr += sndReadPage(sndPageNum++, &sndBuf[sndWritePtr], sndEndPageNum - sndPageNum);
    else
      SNDEN = false;
    sndWritePtr &= 511;
  }
}
int getSndPtr() {
  noInterrupts();
  int rtn = sndReadPtr;
  interrupts();
  return rtn;
}

void sndPlay(byte sndId) {
  SNDEN = false;
  SFReadPage(0, sndBuf);
  for (int x = 0; x < 256; x += 5) {
    if (sndBuf[x] == sndId) {
      // Position the indices to select the sound
      sndStartPageNum = (sndBuf[x + 1] << 8) + sndBuf[x + 2];
      sndEndPageNum = (sndBuf[x + 3] << 8) + sndBuf[x + 4] + 1; // Add space for step-down ramp
      // TODO xxx Bandaid
      if(sndId == SND_MISSILE_FIRED)
        sndStartPageNum = (((sndEndPageNum * 3) + sndStartPageNum) / 4); //TODO XXX Cut off first half of SND_MISSILE_FIRED
      sndPageNum = sndStartPageNum;

      // Used to load the first page of sound
      //   SFReadPage(sndPageNum++, sndBuf);
      // Now loads first page of step-upramp to prevent clicks
      for (byte x = 0; x < 255; x++) {
        sndBuf[x] = x / 2;
      }
      sndBuf[255] = 127;
      sndWritePtr = 256;
      sndReadPtr = 0;

      // Play the sound
      SNDEN = true;
    }
  }
}

inline int sndReadPage(word page_number, byte *page_buffer, uint16_t remaining) {
  if (remaining > 1)
    return SFReadPage(page_number, page_buffer);
  if(remaining == 1)
    return sndRampPage(page_number, page_buffer);
  return sndZeroPage(page_buffer);
}

inline int sndZeroPage(byte *page_buffer) {
  for (int i = 0; i < 256; ++i) {
    page_buffer[i] = 0;
  }
  return 256;
}

inline int sndRampPage(word page_number, byte *page_buffer) {
  for (int i = 0; i < 256; ++i) {
    page_buffer[i] = 127 - (i / 2);
    //        page_buffer[i] = (i&3) == 0 ? 255 : 0;
  }
  return 256;
}

// Return the (estimated) loudness of the audio currently playing
// 0 = silent
// 32768 = Max loudness sine wave
uint16_t sndLoudness() {
  if(sndPageNum > sndEndPageNum - 1) // Don't count the down-ramp
    return 0;
  uint16_t rtn = 0;
  byte cnt = 0;
  do {
    rtn += abs(sndBuf[cnt * 2] - 128);
    cnt += 4;
  } while (cnt != 0);
  return rtn * 4;
}

byte sndProgress() {
  return map(sndPageNum, sndStartPageNum, sndEndPageNum, 0, 255);
}

void sndPlaySynchronous(byte sndId) {
  sndPlay(sndId);
  while (SNDEN)
    sndService();
}
