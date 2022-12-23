
byte TF1DBNC[13];
byte TF2DBNC[13];

/** I/O buffer structure
    Bit 0: Main peripherals
    Bit 1: Task Force 1 offense
    Bit 2: Task Force 1 defense
    Bit 3: Task force 2 offense
    Bit 4: Task force 3 defense

    Byte 0-8: LED K5 K6 K7 K8 K9 K10 K11 K12
    Byte 9-16: LED B9 B10 B11 B12 K1 K2 K3 K4
    Byte 17-24: LED B1 B2 B3 B4 B5 B6 B7 B8
    Byte 25-32: LED G5 G6 G7 G8 G9 G10 G11 G12
    Byte 33-40: LED R9 R10 R11 R12 G1 G2 G3 G4
    Byte 41-47: LED R1 R2 R3 R4 R5 R6 R7 R8

    MAIN PERIPHERALS: SPEN BTNA1 BTNA2 BTNA3 BTNA4 BTNA5 BTNA6 BTNA7 SPEN  BLU GRN RED TF1LEDEN TF2LEDEN PWRCTL CHGEN -
*/

void initIoBuf() {
  for (int x = 0; x < 13; x++) {
    TF1DBNC[x] = 127;
    TF2DBNC[x] = 127;
  }
  int i = 0;
  for (byte x = 0; x < 2; x++) { // 2 color bits
    for (byte y = 0; y < 12; y++) { // 12 rows
      for (byte z = 0; z < 48; z++) { // 48 physical bits
        if (z >= 33 && z < 40 && y < 7) { // Button drive wave
          ioBuf[i] = ((39 - z) == y) ? 1 : 0;
        }
        else if (z == 43 && !(y & 1) || (z == 44 & (y & 1))) { // Main LED drive wave
          ioBuf[i] = 1;
        }
        else if (z == 42) {
          ioBuf[i] = 1; // SMPS enable (PWRCTL)
        }
        else {
          ioBuf[i] = 0;
        }
        if (z == 11 - y) { // Cathode drive wave
          ioBuf[i] |= 30;
        }
        i++;
      }
    }
  }
}


uint16_t TF1BTN = 0;
uint16_t TF2BTN = 0;
uint16_t RSTCTR = 0;
uint16_t PWRCTR = 0;
volatile uint16_t BATTLVL = 0; // 0 - 8192 reading of battery voltage
volatile uint16_t USBVLVL = 0; // 0 - 8192 reading of USB voltage

inline void MPIsr() {
  static byte pRow = 255;
  static byte row = 0;
  static byte bit = 0;
  static byte frame = 0;
  static bool usbAnalogTurn = false;
  static bool battFullHyst = false;


  // Input
  if ((frame & 63) == 1) { // Battery voltage reading
    if (BattVoltage.ready()) {
      if (usbAnalogTurn) {
        USBVLVL = ((USBVLVL + USBVoltage.value()) / 9 ) * 8;
        BattVoltage.start();
      }
      else {
        BATTLVL = ((BATTLVL + BattVoltage.value()) / 9 ) * 8;
        USBVoltage.start();
        if (LVCEN && BATTLVL < BATT_LVC_SHUTDOWN * BATT_CAL_VALUE && BATTLVL > BATT_LVC_IGNORE * BATT_CAL_VALUE) {
          clearLEDs();
          shiftLed(ioBuf, 48); // Just to blank the display
          // TODO announce that the battery is depleted
          off(50);
        }
      }
      usbAnalogTurn = !usbAnalogTurn;
    }
  }

  if ((frame & 63) == 2) { // Handle battery charging
    if (BATTLVL > BATT_HVC_FULL * BATT_CAL_VALUE)
      battFullHyst = true;
    else if (BATTLVL < BATT_HVC_EMPTY * BATT_CAL_VALUE) // Charge set point hysteresis
      battFullHyst = false;

    if (USBVLVL > USB_VOLTAGE_CHARGE * VUSB_CAL_VALUE)
      PWRCTR = 0; // No power timeout if charging

    if (USBVLVL > USB_VOLTAGE_CHARGE * VUSB_CAL_VALUE && !battFullHyst) {
      setCharging(1);
    }
    else {
      setCharging(0);
    }
    //    setCharging(1);
  }

  if ((frame & 255) == 3) { // Handle power-off timeout
    if (!TF1BTN && !TF2BTN)
      PWRCTR++;
    else
      PWRCTR = 0;
    if (PWRCTR == 38400) // Warning tone after 10 minutes
      sndPlay(SND_TAPS);
    if (PWRCTR >= 42240) // Off after 11 minutes
      off();
  }

  if ((frame & 7) == 0) {
    if (pwrBtnPressed()) { // Reboot / Power off button hold counter
      RSTCTR++;
      if (RSTCTR >= 5000) {
        off();
      }
    }
    else {
      RSTCTR = 0;
    }
    if (pRow < 7) { // Read buttons into TFxBTNP variables
      bitWrite(TF1BTN, pRow, bitRead(BTNK_PORT, BTNK_11));
      bitWrite(TF1BTN, pRow + 7, bitRead(BTNK_PORT, BTNK_12));
      bitWrite(TF2BTN, pRow, bitRead(BTNK_PORT, BTNK_21));
      bitWrite(TF2BTN, pRow + 7, bitRead(BTNK_PORT, BTNK_22));
    }
    byte x = pRow;
    if (bitRead(TF1BTN, x)) {
      if (TF1DBNC[x] < 132)
        TF1DBNC[x]++;
      else
        bitWrite(TF1BTND, x, 1);
    }
    else {
      if (TF1DBNC[x] > 120)
        TF1DBNC[x]--;
      else
        bitWrite(TF1BTND, x, 0);
    }
    if (bitRead(TF2BTN, x)) {
      if (TF2DBNC[x] < 132)
        TF2DBNC[x]++;
      else
        bitWrite(TF2BTND, x, 1);
    }
    else {
      if (TF2DBNC[x] > 120)
        TF2DBNC[x]--;
      else
        bitWrite(TF2BTND, x, 0);
    }
    if (x == 10)
      bitWrite(TF1BTND, 12, bitRead(TF1BTN, 12));
    if (x == 11)
      bitWrite(TF2BTND, 12, bitRead(TF2BTN, 12));
  }

  // Output
  int idx = row * 48;
  if (bit != 0)
    idx += (48 * 12);
  byte* ptr = &ioBuf[idx];
  shiftLed(ptr, 48);

  // Update state
  pRow = row;
  row++;
  if (row > 11) {
    row = 0;
    bit++;
    frame++;
    if (bit > 2)
      bit = 0;
  }
}

inline void shiftLed(byte * value, byte len) {
  bitWrite(SLT_LED_PORT, SLT_LED_PIN, 0);
  bitWrite(SCK_LED_PORT, SCK_LED_PIN, 0);
  byte lenm1 = len - 8;
  for (byte x = 0; x < len; x += 8) { // Loop unrolled for performance reasons
    SDA_PORT = value[x] & B00011111;
    bitWrite(SCK_LED_PORT, SCK_LED_PIN, 1);
    if (x == lenm1)
      bitWrite(SEN_LED_PORT, SEN_LED_PIN, 1);
    SDA_PORT = value[x + 1] & B00011111;
    bitWrite(SCK_LED_PORT, SCK_LED_PIN, 1);
    SDA_PORT = value[x + 2] & B00011111;
    bitWrite(SCK_LED_PORT, SCK_LED_PIN, 1);
    SDA_PORT = value[x + 3] & B00011111;
    bitWrite(SCK_LED_PORT, SCK_LED_PIN, 1);
    SDA_PORT = value[x + 4] & B00011111;
    bitWrite(SCK_LED_PORT, SCK_LED_PIN, 1);
    SDA_PORT = value[x + 5] & B00011111;
    bitWrite(SCK_LED_PORT, SCK_LED_PIN, 1);
    SDA_PORT = value[x + 6] & B00011111;
    bitWrite(SCK_LED_PORT, SCK_LED_PIN, 1);
    SDA_PORT = value[x + 7] & B00011111;
    bitWrite(SCK_LED_PORT, SCK_LED_PIN, 1);
  }
  bitWrite(SLT_LED_PORT, SLT_LED_PIN, 1);
  bitWrite(SEN_LED_PORT, SEN_LED_PIN, 0);
}

/**
   Set the color of the board LEDs
   The resolution of these LEDs is 2 bits per color, or 6 bits per pixel.
   Due to read-optimization of the internal data structure this function is slow
   @param boardId ID of LED board to set pixel on
   @param x, y Coordinates of LED
   @param color 6-bit color, as byte (00 RR GG BB)
*/
void setLED(byte boardId, byte y, byte x, byte color) {
  uint16_t baseAddr = y * 48 + (11 - x);
  boardId++;
  // Red low
  bitWrite(ioBuf[baseAddr + 12], boardId, (color >> 4) & 1);
  // Red high
  bitWrite(ioBuf[576 + baseAddr + 12], boardId, (color >> 5) & 1);

  // Green low
  bitWrite(ioBuf[baseAddr + 24], boardId, (color >> 2) & 1);
  // Green high
  bitWrite(ioBuf[576 + baseAddr + 24], boardId, (color >> 3) & 1);

  // Blue low
  bitWrite(ioBuf[baseAddr + 36], boardId, (color >> 0) & 1);
  // Blue high
  bitWrite(ioBuf[576 + baseAddr + 36], boardId, (color >> 1) & 1);
}


void clearLEDs() {
  clearLEDs(0x0F);
}
void clearLEDs(byte boardMask) {
  boardMask &= 0x0F;
  boardMask = boardMask << 1;
  boardMask = ~boardMask;
  for (uint16_t x = 0; x < 2 * 12 * 48; x++) {
    if (x % 48 >= 12)
      ioBuf[x] &= boardMask;
  }
}


/**
   Set the color of the main LEDs in the center of the board.
   The resolution is not a full 8 bits and will be rounded to fit the hardware.
   Due to read-optimization of the internal data structure these functions are slow.
*/
void setMainLEDs(byte r1, byte g1, byte b1, byte r2, byte g2, byte b2) {
  _setMainLEDs(r1, g1, b1, r2, g2, b2, 0x03);
}
void setMainLED(byte r, byte g, byte b, byte side) {
  _setMainLEDs(r, g, b, r, g, b, side ? 0x02 : 0x01);
}
void setMainLED1(byte r, byte g, byte b) {
  _setMainLEDs(r, g, b, 0, 0, 0, 0x01);
}
void setMainLED2(byte r, byte g, byte b) {
  _setMainLEDs(0, 0, 0, r, g, b, 0x02);
}
void clearMainLEDs() {
  _setMainLEDs(0, 0, 0, 0, 0, 0, 0x03);
}
void _setMainLEDs(byte r1, byte g1, byte b1, byte r2, byte g2, byte b2, byte mask) {
  for (byte x = 0; x < 24; x++) {
    byte bitVal = x >> 1;
    if (x >= 12)
      bitVal += x;
    bitVal *= 7;
    if (!(x & 1)) { // TF1
      if (mask & 1) {
        bitWrite(ioBuf[x * 48 + 45], 0, r1 > bitVal);
        bitWrite(ioBuf[x * 48 + 46], 0, g1 > bitVal);
        bitWrite(ioBuf[x * 48 + 47], 0, b1 > bitVal);
      }
    } else { // TF2
      if (mask & 2) {
        bitWrite(ioBuf[x * 48 + 45], 0, r2 > bitVal);
        bitWrite(ioBuf[x * 48 + 46], 0, g2 > bitVal);
        bitWrite(ioBuf[x * 48 + 47], 0, b2 > bitVal);
      }
    }
  }
}


inline void setCharging(bool enabled) {
  if (enabled == isCharging())
    return; // Avoid expensive, unnecessary operation
  for (uint16_t x = 0; x < sizeof(ioBuf); x += 48) {
    bitWrite(ioBuf[x + 41], 0, enabled);
  }
}

inline bool pwrBtnPressed() {
  return PINB & 1;
}

inline bool isCharging() {
  return bitRead(ioBuf[41], 0);
}

uint16_t getBattLevel() {
  noInterrupts();
  uint16_t rtn = BATTLVL;
  interrupts();
  return rtn;
}
uint16_t getVUsbLevel() {
  noInterrupts();
  uint16_t rtn = USBVLVL;
  interrupts();
  return rtn;
}
