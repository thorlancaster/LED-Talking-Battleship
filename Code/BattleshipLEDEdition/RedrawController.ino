
//#define GFX_TYPE_CROSSHAIR 0
//#define GFX_TYPE_HIT 1
//#define GFX_TYPE_TWINKLE 2
//#define GFX_TYPE_KABOOM 8

byte GFXDRAWTYPE = 0; // 0 = Crosshair, 1 = hit, 2 = Twinkle...
byte GFXCROSSHAIR = 0xFF; // B XXXX YYYY for ship entry / hit crosshair
byte GFXDIRECTION = 0; // B LLLLL (Length)  NNN (NONE NORTH SOUTH EAST WEST NONE NONE NONE)
byte GFXBOARDSIZE = 255; // Overlay indicating playable game size. Set to 255 to hide
byte GFXDRAWFLAGS = 0; // // B 0000 000P // P=1 disables task force 2 for 1 player mode

void gfxRedrawAll() {
  gfxRedraw(0);
  gfxRedraw(1);
  gfxRedraw(2);
  gfxRedraw(3);
}

void gfxRedraw(byte board) {
  if (DBG_FLASH_REDRAW) {
    for (byte x = 0; x < 12; x++) {
      for (byte y = 0; y < 12; y++) {
        setLED(board, x, y, B111111);
      }
    }
    Delay(20);
  }

  if (board == BOARD_TF1_DEFENSE || board == BOARD_TF2_DEFENSE) {
    for (byte x = 0; x < 12; x++) {
      for (byte y = 0; y < 12; y++) {
        setLED(board, x, y, gfxShader(board, x, y, true));
      }
    }
  }
  else if (board == BOARD_TF1_OFFENSE || board == BOARD_TF2_OFFENSE) {
    for (byte x = 0; x < 12; x++) {
      for (byte y = 0; y < 12; y++) {
        setLED(board, x, y, gfxShader(board, x, y, false));
      }
    }
  }
}

inline byte gfxShader(byte board, byte x, byte y, bool drawShips) {
  // Blocker layer (always on top)
  if(GFXDRAWFLAGS & 1 && (board == BOARD_TF2_OFFENSE || board == BOARD_TF2_DEFENSE)){
    return 0;
  }
  // Crosshair layer
  byte crossX = (GFXCROSSHAIR & 0x0F);
  byte crossY = ((GFXCROSSHAIR & 0xF0) >> 4);
  byte kaboomClose = 0;
  if (GFXDRAWTYPE == GFX_TYPE_KABOOM) {
    kaboomClose = (GFXDIRECTION >> 3) - (abs(x - crossX) + abs(y - crossY) + max(abs(x - crossX), abs(y - crossY))) / 2 + ((x + y) & 1);
  }

  if (GFXBOARDSIZE != 255 && ((x == GFXBOARDSIZE && y <= GFXBOARDSIZE) || (y == GFXBOARDSIZE && x <= GFXBOARDSIZE))) {
    return B010101; // Board size layer
  }

  else if (GFXBOARDSIZE != 255 && (x > GFXBOARDSIZE || y > GFXBOARDSIZE)) {
    return B000000; // Board size mask
  }

  if (GFXDRAWTYPE == GFX_TYPE_KABOOM && kaboomClose < 127) { // AKA greater than 0 signed   // KABOOM! Layer
    if (kaboomClose < 1)
      return B010000;
    if (kaboomClose < 3)
      return B110000;
    if (kaboomClose < 4)
      return B110100;
    if (kaboomClose < 6)
      return B111100;
    return B111111;
  }

  else if (x == crossX && y == crossY) {
    if (GFXDRAWTYPE == GFX_TYPE_TWINKLE)
      return Millis() & 1 ? B001101 : B000111;
    else
      return B111111;
  }

  else if (GFXDRAWTYPE == GFX_TYPE_CROSSHAIR && (x == crossX || y == crossY)) {
    byte dir = (GFXDIRECTION & 7);
    byte dirLen = (GFXDIRECTION >> 3);
    if ((dir == DIR_NORTH && (x < crossX && x > crossX - dirLen)) ||
        (dir == DIR_SOUTH && (x > crossX && x < crossX + dirLen)) ||
        (dir == DIR_WEST && (y < crossY && y > crossY - dirLen)) ||
        (dir == DIR_EAST && (y > crossY && y < crossY + dirLen)))
      return B111111;
    else if (crossX == 15 || crossY == 15)
      return B000101;
  }

  // Ships/Shots layer if not returned already
  byte res = readRam(getRamPtr(x + 1, y + 1, (board == BOARD_TF1_DEFENSE || board == BOARD_TF2_OFFENSE ? 0 : 1)));
  switch (res) {
    case TYPE_PATROL_BOAT: return drawShips ? B000011 : 0; break;
    case TYPE_DESTROYER: return drawShips ? B0000111 : 0; break;
    case TYPE_SUBMARINE: return drawShips ? B001101 : 0; break;
    case TYPE_BATTLESHIP: return drawShips ? B001100 : 0; break;
    case TYPE_CARRIER: return drawShips ? B011100 : 0; break;
    case TYPE_WHITEPEG: return B010101; break;
    case TYPE_REDPEG: return B110000; break;
    default: return B000000;
  }
}

#define TYPE_PATROL_BOAT 1
#define TYPE_DESTROYER 2
#define TYPE_SUBMARINE 3
#define TYPE_BATTLESHIP 4
#define TYPE_CARRIER 5
#define TYPE_WHITEPEG 6
#define TYPE_REDPEG 7

inline void gfxDisableTf2(bool blk){
  bitWrite(GFXDRAWFLAGS, 0, blk);
}

inline void gfxSetCrosshair(byte x, byte y) {
  GFXCROSSHAIR = ((x & 15) << 4) | (y & 15);
}

inline void gfxSetDirection(byte dir, byte len) {
  GFXDIRECTION = (dir & 7) | ((len & 31) << 3);
}

inline void gfxSetType(byte type) {
  GFXDRAWTYPE = type;
}

inline void gfxSetBoardSize(byte sz) {
  GFXBOARDSIZE = sz;
}
