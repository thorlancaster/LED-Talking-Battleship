#include <util/delay.h>

void hsv2rgb(byte h, byte s, byte v, byte& r, byte& g, byte& b) {
  int ih = h * 6;
  if (ih <= 255) { // R - Y
    r = 255;
    g = ih;
    b = 0;
  } else if (ih <= 511) { // Y - G
    r = 512 - ih;
    g = 255;
    b = 0;
  } else if (ih <= 767) { // G - C
    r = 0;
    g = 255;
    b = ih - 512;
  } else if (ih <= 1023) { // C - B
    r = 0;
    g = 1023 - ih;
    b = 255;
  } else if (ih <= 1279) { // B - P
    r = ih - 1024;
    g = 0;
    b = 255;
  } else { // P - R
    r = 255;
    g = 0;
    b = 1280 - ih;
  }
}

/**
   The leftover bits of the I/O Buffer are used to provide a 12x12x2 virtual 3-bit RAM
   for keeping track of game state (ships, missiles, etc)

*/
inline byte readRam(int x) {
  return ioBuf[x] >> 5;
}

inline void writeRam(int x, byte val) {
  ioBuf[x] = (ioBuf[x] & B00011111) | (val << 5);
}

inline void clearRam() {
  for (int x = 0; x < sizeof(ioBuf); x++) {
    writeRam(x, 0);
  }
}

void off() {
  off(0);
}
void off(byte beep) { // Beep = how many 10 ms to beep for
  noInterrupts();
  RSTCTR = 0;

  bitWrite(DDRD, 3, 1);
  for (int x = 0; x < beep * 10; x++) {
    OCR2B = 192;
    _delay_us(500);
    OCR2B = 64;
    _delay_us(500);
  }

  for (int x = 0; x < sizeof(ioBuf); x++) { // Power down all peripherals
    ioBuf[x] = 0;
  }
  MPIsr();
  // Wait for power to die and BEEEEP
  while (1) {
    OCR2B = 192;
    _delay_us(500);
    OCR2B = 64;
    _delay_us(500);
  }
}

void beep(){
  sndPlaySynchronous(SND_BUTTON);
  delay(INTER_SND_DELAY / 4);
}

inline byte countSetBits(byte num){
  byte rtn = 0;
  for(byte x = 0; x < 8; x++){
    rtn += (num >> x) & 1;
  }
  return rtn;
}

void setSMPS(bool en) {
  for (int i = 42; i < sizeof(ioBuf); i += 48) {
    bitWrite(ioBuf[i], 0, en);
  }
}
