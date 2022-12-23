void chargeMode() {
  while (1) {
    int lvl = map(getBattLevel() / BATT_CAL_VALUE, BATT_LVC_REFUSE, BATT_HVC_EMPTY, 0, 12);
    if(lvl < 0)
      lvl = 0;
    if (!isCharging()) // Ensure bar graph is full once full
    {
      for (int x = 0; x < 12; x++) {
        setLED(BOARD_TF1_OFFENSE, 0, x, B010101);
        setLED(BOARD_TF2_OFFENSE, 0, x, B010101);
      }
      setSMPS((Millis() & 511) > 256);
    }
    else {
      setSMPS(true);
      if ((Millis() % 1000) > 500)
        lvl++;
      for (int x = 0; x < 12; x++) { // x+1 to adjust for board, battery resistance
        setLED(BOARD_TF1_OFFENSE, 0, x, x+1 < lvl ? B001100 : B110000);
        setLED(BOARD_TF2_OFFENSE, 0, x, x+1 < lvl ? B001100 : B110000);
      }
    }
    delay(100);
  }
}
