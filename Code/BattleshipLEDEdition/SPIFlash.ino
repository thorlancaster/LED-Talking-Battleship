/*
    Copyright 2014, Peter J. Torelli
    Modified 2020, Thor H. Lancaster

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>


  Revisions:
    rev 2 - 21-SEP-2014.
    User 'fiaskow' pointed out that driving the WEL instruction after
    program and erase w/o waiting for the op to finish may be corrupting
    execution. Removed this code (also not needed b/c the WEL is already
    cleared after page write or chip erase).
*/

// SS:   pin 10
// MOSI: pin 11
// MISO: pin 12
// SCK:  pin 13

// WinBond flash commands
#define WB_WRITE_ENABLE       0x06
#define WB_WRITE_DISABLE      0x04
#define WB_CHIP_ERASE         0xc7
#define WB_READ_STATUS_REG_1  0x05
#define WB_READ_DATA          0x03
#define WB_PAGE_PROGRAM       0x02
#define WB_JEDEC_ID           0x9f

/*
  ================================================================================
  Low-Level Device Routines
  The functions below perform the lowest-level interactions with the flash device.
  They match the timing diagrams of the datahsheet. They are called by wrapper
  functions which provide a little more feedback to the user. I made them stand-
  alone functions so they can be re-used. Each function corresponds to a flash
  instruction opcode.
  ================================================================================
*/

/*
   See the timing diagram in section 9.2.35 of the
   data sheet, "Read JEDEC ID (9Fh)".
*/
void SFGetJedecId(byte *b1, byte *b2, byte *b3) {
  SFWaitNotBusy();
  digitalWrite(SS, HIGH);
  digitalWrite(SS, LOW);
  SPI.transfer(WB_JEDEC_ID);
  *b1 = SPI.transfer(0); // manufacturer id
  *b2 = SPI.transfer(0); // memory type
  *b3 = SPI.transfer(0); // capacity
  digitalWrite(SS, HIGH);
}

/*
   See the timing diagram in section 9.2.26 of the
   data sheet, "Chip Erase (C7h / 06h)". (Note:
   either opcode works.)
*/
void SFChipErase(void) {
  SFWaitNotBusy();
  digitalWrite(SS, HIGH);
  digitalWrite(SS, LOW);
  SPI.transfer(WB_WRITE_ENABLE);
  digitalWrite(SS, HIGH);
  digitalWrite(SS, LOW);
  SPI.transfer(WB_CHIP_ERASE);
  digitalWrite(SS, HIGH);
  /* See notes on rev 2
    digitalWrite(SS, LOW);
    SPI.transfer(WB_WRITE_DISABLE);
    digitalWrite(SS, HIGH);
  */
  SFWaitNotBusy();
}

/*
   See the timing diagram in section 9.2.10 of the
   data sheet, "Read Data (03h)".
*/
inline int SFReadPage(word page_number, byte *page_buffer) {
  SFWaitNotBusy();
  digitalWrite(SS, HIGH);
  digitalWrite(SS, LOW);
  SPI.transfer(WB_READ_DATA);
  // Construct the 24-bit address from the 16-bit page
  // number and 0x00, since we will read 256 bytes (one
  // page).
  SPI.transfer((page_number >> 8) & 0xFF);
  SPI.transfer((page_number >> 0) & 0xFF);
  SPI.transfer(0);
  for (int i = 0; i < 256; ++i) {
    page_buffer[i] = SPI.transfer(0);
  }
  digitalWrite(SS, HIGH);
  return 256;
}

/*
   See the timing diagram in section 9.2.21 of the
   data sheet, "Page Program (02h)".
*/
inline void SFWritePage(word page_number, byte *page_buffer) {
  SFWaitNotBusy();
  digitalWrite(SS, HIGH);
  digitalWrite(SS, LOW);
  SPI.transfer(WB_WRITE_ENABLE);
  digitalWrite(SS, HIGH);
  digitalWrite(SS, LOW);
  SPI.transfer(WB_PAGE_PROGRAM);
  SPI.transfer((page_number >>  8) & 0xFF);
  SPI.transfer((page_number >>  0) & 0xFF);
  SPI.transfer(0);
  for (int i = 0; i < 256; ++i) {
    SPI.transfer(page_buffer[i]);
  }
  digitalWrite(SS, HIGH);
  /* See notes on rev 2
    digitalWrite(SS, LOW);
    SPI.transfer(WB_WRITE_DISABLE);
    digitalWrite(SS, HIGH);
  */
}

/*
   waitNotBusy() polls the status bit of the device until it
   completes the current operation. Most operations finish
   in a few hundred microseconds or less, but chip erase
   may take 500+ms. Finish all operations with this poll.

   See section 9.2.8 of the datasheet
*/
inline void SFWaitNotBusy(void) {
  digitalWrite(SS, HIGH);
  digitalWrite(SS, LOW);
  SPI.transfer(WB_READ_STATUS_REG_1);
  while (SPI.transfer(0) & 1) {};
  digitalWrite(SS, HIGH);
}
