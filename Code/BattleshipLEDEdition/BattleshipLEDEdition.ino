#include <AsyncAnalog.h>

#include <SPI.h>
#define delay Delay
#define SERIAL_TX_BUFFER_SIZE 32
#define SERIAL_RX_BUFFER_SIZE 32 // 64 more bytes for us! We really need them.

#define DBG_FLASH_REDRAW 0

const int SPKR = 3;
#define BATT_CAL_VALUE 1.56923 // How many ticks of internal voltmeter per millivolt of battery
#define VUSB_CAL_VALUE 0.81769 // ... of USB voltage
#define BATT_LVC_WARN 3580 // Battery millivolts where game warns of low battery
#define BATT_LVC_REFUSE 3420 // Battery millivolts where game refuses to start
#define BATT_LVC_SHUTDOWN 3250 // Battery millivolts where game shuts off forcibly
#define BATT_LVC_IGNORE 1000 // Below this voltage, ignore battery
#define BATT_HVC_FULL 4100 // Battery stops charging at this voltage
#define BATT_HVC_EMPTY 4010 // Battery resumes charging at this voltage
#define USB_VOLTAGE_CHARGE 4000 // If USB at this level or more, attempt to charge battery
#define INSTANT_PROGRAMMING_BOARD_SIZE 10
bool LVCEN = false;

// Serial data bus for LEDs
#define SDA_PORT PORTC
const int SDA_INTERNAL = A0;
const int SDA_TF1_OFFENSE = A1;
const int SDA_TF1_DEFENSE = A2;
const int SDA_TF2_OFFENSE = A3;
const int SDA_TF2_DEFENSE = A4;
#define BOARD_TF1_OFFENSE 0
#define BOARD_TF1_DEFENSE 1
#define BOARD_TF2_OFFENSE 2
#define BOARD_TF2_DEFENSE 3
const int CHGEN = A5;
#define SEN_LED_PORT PORTB
#define SEN_LED_DDR DDRB
#define SLT_LED_PORT PORTD
#define SLT_LED_DDR DDRD
#define SCK_LED_PORT PORTC
#define SCK_LED_DDR PORTC
#define SEN_LED_PIN 1
#define SLT_LED_PIN 2
#define SCK_LED_PIN 5
#define BTNK_PORT PIND
#define BTNK_11 4
#define BTNK_12 5
#define BTNK_21 6
#define BTNK_22 7

#define INTER_SND_DELAY 250
#define SND_INIT 0
#define SND_PREPARE_FOR_BATTLE 1
#define SND_SELECT 2
#define SND_GAME 3
#define SND_ONE 4
#define SND_TWO 5
#define SND_THREE 6
#define SND_FOUR 7
#define SND_PLAYERS 8
#define SND_TASK_FORCE 9
#define SND_ENTER 10
#define SND_PATROL_BOAT 11
#define SND_LETTER 12
#define SND_NUMBER 13
#define SND_DIRECTION 14
#define SND_ARMED 15
#define SND_DESTROYER 16
#define SND_SUBMARINE 17
#define SND_BATTLESHIP 18
#define SND_CARRIER 19
#define SND_MISSILE_FIRED 20
#define SND_MISSILE_IMPACT 21
#define SND_SUNK 22
#define SND_HIT 23
#define SND_SIREN 24
#define SND_MAN_YOUR_BATTLE_STATIONS 25
#define SND_TAPS 26
#define SND_BUTTON 27
#define SND_FIRE 28
#define SND_SIZE 29
#define SND_SKILL 30
#define SND_NYAN 69
#define SND_BATTERY 31
#define SND_LOW 32
#define SND_DEPLETED 33

#define GFX_TYPE_CROSSHAIR 0
#define GFX_TYPE_HIT 1
#define GFX_TYPE_TWINKLE 2
#define GFX_TYPE_KABOOM 8

#define TYPE_PATROL_BOAT 1
#define TYPE_DESTROYER 2
#define TYPE_SUBMARINE 3
#define TYPE_BATTLESHIP 4
#define TYPE_CARRIER 5
#define TYPE_WHITEPEG 6
#define TYPE_REDPEG 7

#define DIR_NORTH 1
#define DIR_SOUTH 2
#define DIR_EAST 3
#define DIR_WEST 4

#define STATUS_FLEET_SUNK 2
#define STATUS_SHIP_SUNK 1


AsyncAnalog BattVoltage(A6);
AsyncAnalog USBVoltage(A7);
byte sndBuf[512];
byte ioBuf[48 * 12 * 2]; // 48 bytes * 12 rows * 2 bits of brightness
volatile uint16_t TF1BTND = 0;
volatile uint16_t TF2BTND = 0;
bool SNDEN = false;
bool SNDDIV = false;
volatile uint32_t MILLIS = 0;
volatile int sndReadPtr = 0;
volatile int sndWritePtr = 0;

void setup() {
  // Prevent bug where reboot occurred instead of shutdown due to capacitors not fully discharging
  _delay_ms(100);
  // Set pins
  pinMode(SPKR, OUTPUT);
  pinMode(SDA_INTERNAL, OUTPUT);
  pinMode(SDA_TF1_OFFENSE, OUTPUT);
  pinMode(SDA_TF1_DEFENSE, OUTPUT);
  pinMode(SDA_TF2_OFFENSE, OUTPUT);
  pinMode(SDA_TF2_DEFENSE, OUTPUT);
  pinMode(CHGEN, OUTPUT);
  // Set pins that aren't Arduino pins
  SEN_LED_DDR |= (1 << SEN_LED_PIN);
  SLT_LED_DDR |= (1 << SLT_LED_PIN);
  SCK_LED_DDR |= (1 << SCK_LED_PIN);

  // Set up speaker
  analogWrite(SPKR, 127);
  pinMode(3, OUTPUT);

  // Initialize I/O buffer
  initIoBuf();

  // Disable Timer2 so it doesn't cause jitter (flickering / distorted sound)
  noInterrupts();
  TCCR0A = 0;
  TCCR0B = 0;

  // Set Timer2 prescale to 0 for fast PWM
  // Timer2 is used to generate a class D speaker signal
  TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS20);
  OCR2A = 255; // 8 bit PWM
  OCR2B = 40; // 50% duty cycle to start

  // Set Timer1 for 16KHz system clock
  TCCR1A = TCCR1B = TCNT1 = 0;
  // Set compare match register
  OCR1A = 122;
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set bits for 8 prescaler
  TCCR1B |= (1 << CS11);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  interrupts();

  // Initialize SPI for interfacing with flash chip
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV2); // Full speed
  SPI.setDataMode(0);
  SPI.setBitOrder(MSBFIRST);

  // Check for on button pressed. If off and plugged in, go to charge mode
  bool onBtnDet = false;
  for (byte x = 0; x < 100; x++) {
    if (pwrBtnPressed())
      onBtnDet = true;
    delay(5);
  }
  if (!onBtnDet && getBattLevel() > BATT_LVC_IGNORE * BATT_CAL_VALUE) {
    chargeMode();
  }
  delay(500);
  // Display bar graph of battery
  int lvl = map(getBattLevel() / BATT_CAL_VALUE, BATT_LVC_REFUSE, BATT_HVC_EMPTY, 0, 12);
  for (int x = 0; x < 12; x++) {
    setLED(BOARD_TF1_OFFENSE, 0, x, x < lvl ? B001100 : B110000);
  }
  while (true) { // Hold down TF1/A1 button when power on to access serial config mode
    // TODO if ON button not detected, go to charging mode
    if (TF1BTND == 1) {
      Serial.begin(19200);
      configMode();
    }
    if (MILLIS > 2000)
      break;
  }

  if (getBattLevel() > BATT_LVC_IGNORE * BATT_CAL_VALUE) {
    // Warn if battery too low
    if (getBattLevel() < (BATT_LVC_REFUSE * BATT_CAL_VALUE)) {
      sndPlaySynchronous(SND_BATTERY);
      delay(INTER_SND_DELAY / 2);
      sndPlaySynchronous(SND_DEPLETED);
      delay(INTER_SND_DELAY / 2);
      off();
    }

    if (getBattLevel() < (BATT_LVC_WARN * BATT_CAL_VALUE)) {
      sndPlaySynchronous(SND_BATTERY);
      delay(INTER_SND_DELAY / 2);
      sndPlaySynchronous(SND_LOW);
      delay(INTER_SND_DELAY);
    }
  }

  LVCEN = true; // Enable low voltage shutoff
}

void loop() {
  byte game = 0;
  byte players = 0;
  byte boardSize = 0;
  // Clear the game
  clearRam();
  clearLEDs();

  //  game = 2;
  //  players = 2;
  //  placeShip(1, 1, DIR_SOUTH, 0, 2, TYPE_PATROL_BOAT);
  //  placeShip(7, 7, DIR_SOUTH, 0, 3, TYPE_DESTROYER);
  //  placeShip(1, 1, DIR_SOUTH, 1, 2, TYPE_PATROL_BOAT);
  //  placeShip(7, 7, DIR_SOUTH, 1, 3, TYPE_DESTROYER);
  //  gfxRedrawAll();
  //  goto XXX_SKIP_ENTRY;

  //  game = 2;
  //  players = 2;
  //  boardSize = 10;
  //  goto XXX_SKIP_INTRO;

  // TODO warn user if battery is low

  sndPlay(SND_INIT); // ---------------- PREPARE FOR BATTLE
  while (SNDEN)
    sndService();
  delay(INTER_SND_DELAY);


  sndPlay(SND_PREPARE_FOR_BATTLE);
  while (SNDEN)
    sndService();

  boardSize = 0;
  do { // ---------------- SELECT SIZE
    delay(INTER_SND_DELAY);
    sndPlaySynchronous(SND_SELECT);
    delay(INTER_SND_DELAY / 2);
    sndPlay(SND_SIZE);
    boardSize = getTfxNumBlocking(0);
    randomSeed(random() + Millis());
  }
  while (boardSize < 8 || boardSize == 13);
  gfxSetCrosshair(15, 15); // Show the game size
  gfxSetBoardSize(boardSize);
  gfxSetDirection(0, 0);
  gfxSetType(GFX_TYPE_CROSSHAIR);
  gfxRedraw(getDefensiveBoard(0)); // Draw onto TF1 DEFENSE
  while (SNDEN)
    sndService();
  delay(INTER_SND_DELAY);

  game = 0;
  do { // ---------------- SELECT GAME
    while (SNDEN)
      sndService();
    delay(INTER_SND_DELAY);
    sndPlaySynchronous(SND_SELECT);
    delay(INTER_SND_DELAY / 2);
    sndPlay(SND_GAME);
    game = getTfxNumBlocking(0);
    randomSeed(random() + Millis());
    if (game == 12)
      easterEggNyanCat();
    if (game == 11)
      easterEggDBG();
    if (game == 10)
      easterEggDBG2();
  }
  while (game == 0 || game > 4);
  while (SNDEN)
    sndService();
  delay(INTER_SND_DELAY);

  sndPlaySynchronous(SND_GAME);  // ---------------- ANNOUNCE GAME SELECTION
  delay(INTER_SND_DELAY / 2);
  sndPlaySynchronous(SND_ONE + (game - 1));
  delay(INTER_SND_DELAY);

  if (game == 4) { // Game 4 is for 2 players only. Players decide on their own firing rules
    players = 2;
  } else {
    players = 0;
    do { // ---------------- SELECT PLAYERS
      while (SNDEN)
        sndService();
      delay(INTER_SND_DELAY);
      sndPlaySynchronous(SND_SELECT);
      delay(INTER_SND_DELAY / 2);
      sndPlay(SND_PLAYERS);
      players = getTfxNumBlocking(0);
    }
    while (players == 0 || players > 2);
    while (SNDEN)
      sndService();
    delay(INTER_SND_DELAY / 2);
    sndPlaySynchronous(SND_ONE + (players - 1));
    delay(INTER_SND_DELAY);
  }


XXX_SKIP_INTRO:
  for (int x = 0; x < players; x++) { // ---------------- PROGRAMMING
    bool needsManual = true;
    if (boardSize == INSTANT_PROGRAMMING_BOARD_SIZE) { // Instant programming entry
      do {
        sndPlaySynchronous(SND_TASK_FORCE);
        delay(INTER_SND_DELAY / 4);
        sndPlaySynchronous(SND_ONE + x);
        delay(INTER_SND_DELAY / 4);
        sndPlaySynchronous(SND_ENTER);
        delay(INTER_SND_DELAY / 4);
        sndPlaySynchronous(SND_LETTER);
        delay(INTER_SND_DELAY / 4);
        sndPlay(SND_NUMBER);

        byte pLetter = boardSize == INSTANT_PROGRAMMING_BOARD_SIZE ? getTfxNumBlocking(x) : 13;
        if (pLetter <= 10) { // Instant programming
          byte pNumber = getTfxNumBlocking(x);
          if (getTfxNumBlocking(x) == 13) {
            if (pNumber <= 10) {
              needsManual = false;
              placeShipsInstant(x, pLetter, pNumber);
              gfxSetBoardSize(255);
              gfxSetCrosshair(15, 15); // Clear entry crosshairs and direction and display ships
              gfxSetDirection(0, 0);
              gfxRedraw(getDefensiveBoard(x));
              gfxSetBoardSize(boardSize);
              break;
            }
          }
        }
        else if (pLetter == 13) break; // Exit for manual programming
      } while (true);
    }

    if (needsManual) { // Manual programming
      sndPlaySynchronous(SND_TASK_FORCE);
      delay(INTER_SND_DELAY / 4);
      sndPlaySynchronous(SND_ONE + x);
      delay(INTER_SND_DELAY / 4);
      bool needsLND = true;
      for (int y = 0; y < 5; y++) {
        do {
          gfxSetCrosshair(15, 15); // Clear entry crosshairs and direction
          gfxSetDirection(0, 0);
          gfxSetBoardSize(boardSize);
          gfxSetType(GFX_TYPE_CROSSHAIR);
          gfxRedraw(getDefensiveBoard(x));

          sndPlaySynchronous(SND_ENTER);
          delay(INTER_SND_DELAY / 4);
          sndPlaySynchronous(getBoatSound(y));
          if (needsLND) {
            delay(INTER_SND_DELAY / 4);
            sndPlaySynchronous(SND_LETTER);
            delay(INTER_SND_DELAY / 4);
            sndPlaySynchronous(SND_NUMBER);
            delay(INTER_SND_DELAY / 4);
            sndPlaySynchronous(SND_DIRECTION);
            needsLND = false;
          }
          byte letter = getTfxNumBlocking(x);
          if (letter == 13) {
            needsLND = true;
            continue;
          }
          gfxSetCrosshair(15, letter - 1);
          gfxRedraw(getDefensiveBoard(x));
          byte number = getTfxNumBlocking(x);
          if (number == 13) {
            needsLND = true;
            continue;
          }
          gfxSetCrosshair(number - 1, letter - 1);
          gfxRedraw(getDefensiveBoard(x));
          byte direction = getTfxNumBlocking(x);
          if (direction == 13) {
            needsLND = true;
            continue;
          }
          gfxSetDirection(direction, getBoatLength(y + 1));
          gfxRedraw(getDefensiveBoard(x));
          byte enter = getTfxNumBlocking(x);
          delay(INTER_SND_DELAY);
          if (enter == 13 && placeShipConstrained(boardSize, letter, number, direction, x, getBoatLength(y + 1), y + 1)) {
            break;
          } else {
            needsLND = true;
          }
        }
        while (true);

        gfxSetCrosshair(15, 15); // Clear entry crosshairs and direction. This also displays new ship
        gfxSetDirection(0, 0);
        gfxRedraw(getDefensiveBoard(x));

        sndPlaySynchronous(getBoatSound(y));
        delay(INTER_SND_DELAY * 3 / 4);
        sndPlaySynchronous(SND_ARMED);
        delay(INTER_SND_DELAY);
      } // End ship entry loop

      // Clear the board size mask from the current player's entry field
      gfxSetBoardSize(255);
      gfxRedraw(getDefensiveBoard(x));
      gfxSetBoardSize(boardSize);

    } // End manual programming
    //    while (true) {
    //      sndService(); // TODO XXX
    //    }
    while (SNDEN) {
      sndService();
    }
    sndPlaySynchronous(SND_TASK_FORCE);
    delay(INTER_SND_DELAY / 4);
    sndPlaySynchronous(SND_ONE + x);
    delay(INTER_SND_DELAY * 3 / 4);
    sndPlaySynchronous(SND_ARMED);
    delay(INTER_SND_DELAY * 3 / 2);
  } // End programming
  sndPlaySynchronous(SND_SIREN);
  delay(INTER_SND_DELAY / 4);
  sndPlaySynchronous(SND_MAN_YOUR_BATTLE_STATIONS);
  delay(INTER_SND_DELAY * 3 / 2);

XXX_SKIP_ENTRY:
  gfxSetBoardSize(255);

  byte needsELNF = 0x03; // H = TaskForce2, L = TaskForce1
  byte turn = 0; // 0 for TF1, 1 for TF2
  bool omitFiringInstructions = false; // Works for the next firing only
  byte g3ShotsRemaining = 2; // Start with 3 shots instead of 5, for fairness. Number is (#shots - 1) because no turn check
  if (game == 4) { // Announce start of game 4, no instructions given otherwise
    sndPlaySynchronous(SND_FIRE);
  }
  while (true) { // ---------------- MAIN GAME
    gfxSetCrosshair(15, 15);
    gfxRedraw(getOffensiveBoard(turn));

    if (!omitFiringInstructions && game != 4) {
      sndPlaySynchronous(SND_TASK_FORCE);
      delay(INTER_SND_DELAY / 4);
      sndPlaySynchronous(SND_ONE + turn);
      delay(INTER_SND_DELAY / 4);
      if (bitRead(needsELNF, turn)) {
        bitWrite(needsELNF, turn, 0);
        delay(INTER_SND_DELAY / 4);
        sndPlaySynchronous(SND_ENTER);
        delay(INTER_SND_DELAY / 4);
        sndPlaySynchronous(SND_LETTER);
        delay(INTER_SND_DELAY / 4);
        sndPlaySynchronous(SND_NUMBER);
        delay(INTER_SND_DELAY / 4);
      }
      sndPlay(SND_FIRE);
    }
    byte letter, number;
    if (players == 1 && turn == 1) { // Computer turn
      byte res = computerTurn(
    }

    else { // Human turn with prompting and stuff
      omitFiringInstructions = false;
      letter = getTfANumBlocking();
      if (game == 4) { // On game 4, whoever pushes the button has the turn
        turn = (letter >> 7) & 1;
      }
      if (letter == 13 || ((letter >> 7) & 1) != turn) {
        bitWrite(needsELNF, turn, 1);
        continue;
      }
      letter &= 0x77; // Cut off the high bit, it represents turn, not number

      gfxSetType(GFX_TYPE_CROSSHAIR);
      gfxSetCrosshair(15, letter - 1);
      gfxRedraw(getOffensiveBoard(turn));

      number = getTfxNumBlocking(turn);
      if (number == 13) {
        bitWrite(needsELNF, turn, 1);
        continue;
      }
      gfxSetCrosshair(number - 1, letter - 1);
      gfxRedraw(getOffensiveBoard(turn));

      byte enter = getTfxNumBlocking(turn);
      if (enter != 13) {
        bitWrite(needsELNF, turn, 1);
        continue;
      }
      gfxSetCrosshair(15, 15);
      gfxRedraw(getOffensiveBoard(turn));
    }

    // Fire the missile
    while (SNDEN)
      sndService();
    delay(INTER_SND_DELAY / 2);
    byte shotResult = fire(letter, number, turn ? 0 : 1);
    sndPlay(SND_MISSILE_FIRED);
    gfxSetType(GFX_TYPE_TWINKLE);
    while (SNDEN) { // Missile lights
      gfxSetCrosshair(number - 1, letter - 1);
      gfxRedraw(getOffensiveBoard(turn));
      sndService();
      byte sndProg = sndProgress();
      setMainLED(0, random(0, 255 - sndProg) / 2, random(0, sndProg) / 2, turn);
    }
    gfxSetType(GFX_TYPE_CROSSHAIR);
    gfxSetCrosshair(15, 15);

    gfxRedraw(getOffensiveBoard(turn));
    if (!isShipType(shotResult)) // Only redraw on miss as to not prematurely show hit
      gfxRedraw(getDefensiveBoard(turn ? 0 : 1));
    clearMainLEDs();
    if (isShipType(shotResult)) {
      delay(INTER_SND_DELAY / 2);
      sndPlay(SND_MISSILE_IMPACT);
      while (SNDEN) { // Ship hit lights
        sndService();
        int loudVal = sndLoudness() / 50;
        byte r = min(loudVal, 255);
        byte g = constrain(loudVal - 255, 0, 180);
        byte b = constrain(loudVal - 265, 0, 103);
        setMainLED(r, g, b, turn);
        setMainLED(r, g, b, turn ? 0 : 1);
        gfxSetType(GFX_TYPE_KABOOM);
        gfxSetDirection(0, loudVal / 65);
        gfxSetCrosshair(number - 1, letter - 1);
        gfxRedraw(getOffensiveBoard(turn));
        sndService();
        gfxRedraw(getDefensiveBoard(turn ? 0 : 1));
      }
      setMainLEDs(0, 0, 0, 0, 0, 0);
      gfxSetCrosshair(15, 15);
      gfxSetType(GFX_TYPE_CROSSHAIR);
      gfxRedraw(getOffensiveBoard(turn));
      gfxRedraw(getDefensiveBoard(turn ? 0 : 1));
      delay(INTER_SND_DELAY);

      byte oppStatus = getTaskForceStatus(shotResult, turn ? 0 : 1);
      if (oppStatus == STATUS_FLEET_SUNK) {
        sndPlaySynchronous(getBoatSound(shotResult - 1));
        delay(INTER_SND_DELAY * 3 / 4);
        sndPlaySynchronous(SND_SUNK);
        delay(INTER_SND_DELAY);
        break; // End game
      }
      else {
        sndPlaySynchronous(getBoatSound(shotResult - 1));
        delay(INTER_SND_DELAY * 3 / 4);
        if (oppStatus == STATUS_SHIP_SUNK)
          sndPlaySynchronous(SND_SUNK);
        else
          sndPlaySynchronous(SND_HIT);
      }
      if (game == 2) {
        turn = (turn) ? 0 : 1; // Skip opponent turn when you are playing game 2 and hit a ship
        omitFiringInstructions = true; // And tell the other player...
      }
    }
    if (game == 3) {
      if (g3ShotsRemaining > 0) {
        g3ShotsRemaining--;
        turn = (turn) ? 0 : 1; // Skip opponent turn when you are playing game 3 and have shots remaining
        omitFiringInstructions = true; // And tell the other player...
      }
      else { // Out of shots. Calculate shots for next turn
        g3ShotsRemaining = countRemainingShips(turn ? 0 : 1) - 1;
      }
    }
    delay(INTER_SND_DELAY * 5 / 2);

    turn = (turn) ? 0 : 1;
  }
  // ---------------- Game over. Play taps for the loser
  sndPlaySynchronous(SND_SIREN);
  delay(INTER_SND_DELAY * 3 / 2);
  sndPlaySynchronous(SND_TASK_FORCE);
  delay(INTER_SND_DELAY / 4);
  sndPlaySynchronous(SND_ONE + (turn ? 0 : 1));
  delay(INTER_SND_DELAY / 4);
  sndPlaySynchronous(SND_SUNK);
  delay(INTER_SND_DELAY * 3 / 2);
  sndPlaySynchronous(SND_TAPS);

  while (!pwrBtnPressed()) {
    sndService();
  }
  off();
}

// Looks at the field and decides where to fire.
// Return a byte consisting of LLLLNNNN (letter, number)
// Storage - pointer to a byte array used for memory - must be 4 bytes in size
// BoardSize - self-explanatory
// Skill - How good the computer is
//  0 = always fires A1
//  1 = random guessing
//  2 = pattern with random start
//  3 = intelligent pattern with cheated start
//  4 = intelligent pattern with cheated start and cheated following
byte computerTurn(byte* storage, byte boardSize, byte skill) {
  if (skill == 0)
    return 17;
  return (random(1, boardSize + 1) << 4) + random(1, boardSize + 1);
}



/**
  Determine whether a hit sunk the fleet, a ship, or was just a hit
*/
byte getTaskForceStatus(byte shotResult, byte plyr) {
  bool anyShipFound = false;
  for (byte x = 1; x <= 12; x++) {
    for (byte y = 1; y <= 12; y++) {
      byte res = readRam(getRamPtr(x, y, plyr));
      if (res == shotResult)
        return 0;
      if (res >= TYPE_PATROL_BOAT && res <= TYPE_CARRIER) {
        anyShipFound = true;
      }
    }
  }
  return anyShipFound ? STATUS_SHIP_SUNK : STATUS_FLEET_SUNK;
}

byte countRemainingShips(byte plyr) {
  byte shipCntr = 0;
  for (byte x = 1; x <= 12; x++) {
    for (byte y = 1; y <= 12; y++) {
      byte res = readRam(getRamPtr(x, y, plyr));
      if (res >= TYPE_PATROL_BOAT && res <= TYPE_CARRIER) {
        shipCntr |= (1 << (res - TYPE_PATROL_BOAT));
      }
    }
  }
  return countSetBits(shipCntr);
}


void placeShipsRandom(byte boardSz, byte player) {
  for (int x = 0; x < 5; x++) {
    while (true) {
      byte letter = random(boardSz) + 1;
      byte number = random(boardSz) + 1;
      byte direction = random(4) + 1;
      bool res = placeShipConstrained(boardSz, letter, number, direction, player, getBoatLength(x + TYPE_PATROL_BOAT), x + TYPE_PATROL_BOAT);
      if (res) // On successful ship placement, go to next ship
        break;
    }
  }
}

bool placeShipConstrained(byte boardSz, byte letter, byte number, byte direction, byte player, byte length, byte type) {
  if (letter > boardSz || number > boardSz)
    return false; // Ship start coord out of bounds
  if (direction < 1 || direction > 4)
    return false; // Invalid direction

  for (byte i = 0; i < 2; i++) {
    // First pass verify, second pass place
    for (byte x = 0; x < length; x++) {
      byte effLetter = getLetter(letter, direction, x);
      byte effNumber = getNumber(number, direction, x);
      if (i == 0 && effLetter < 1 || effNumber < 1 || effLetter > boardSz || effNumber > boardSz)
        return false; // Ship hangs off board
      int ramPtr = getRamPtr(effLetter, effNumber, player);
      byte existing = readRam(ramPtr);
      if (i == 0 && existing != 0) {
        return false; // Peg not empty
      }
      if (i == 1) {
        writeRam(ramPtr, type);
      }
    }
  }
  return true;
}

bool placeShip(byte letter, byte number, byte direction, byte player, byte length, byte type) {
  return placeShipConstrained(12, letter, number, direction, player, length, type);
}

byte getLetter(byte oLetter, byte direction, byte distance) {
  if (direction == DIR_NORTH)
    return oLetter - distance;
  if (direction == DIR_SOUTH)
    return oLetter + distance;
  return oLetter;
}

byte getNumber(byte oNumber,  byte direction,  byte distance) {
  if (direction == DIR_WEST)
    return oNumber - distance;
  if (direction == DIR_EAST)
    return oNumber + distance;
  return oNumber;
}

// Given a player ID, return their defensive board ID
inline byte getDefensiveBoard(byte playerId) {
  return (1 + playerId * 2);
}

// Given a player ID, return their offensive board ID
inline byte getOffensiveBoard(byte playerId) {
  return (playerId * 2);
}

/**
  Fire a shot at the board, and return the old peg
  Letter and Number are 1-12
*/
byte fire(byte letter, byte number, byte targPlyr) {
  byte rtn = readRam(getRamPtr(letter, number, targPlyr));
  if (isShipType(rtn))
    writeRam(getRamPtr(letter, number, targPlyr), TYPE_REDPEG);
  if (rtn == 0)
    writeRam(getRamPtr(letter, number, targPlyr), TYPE_WHITEPEG);
  return rtn;
}

inline int getRamPtr(byte letter, byte number, byte player) {
  return player * 144 + (letter - 1) * 12 + (number - 1) * 1;
}

inline bool isShipType(byte type) {
  return type >= TYPE_PATROL_BOAT && type <= TYPE_CARRIER;
}

byte getBoatLength(byte bNum) {
  switch (bNum) {
    case TYPE_PATROL_BOAT: return 2;
    case TYPE_DESTROYER: return 3;
    case TYPE_SUBMARINE: return 3;
    case TYPE_BATTLESHIP: return 4;
    case TYPE_CARRIER: return 5;
  }
}

byte getBoatSound(byte bNum) {
  switch (bNum) {
    case 0: return SND_PATROL_BOAT;
    case 1: return SND_DESTROYER;
    case 2: return SND_SUBMARINE;
    case 3: return SND_BATTLESHIP;
    case 4: return SND_CARRIER;
  }
}

// Same as getTfxNumBlocking but either player can press buttons
// Highest bit of return byte represents who pressed the button
// 0 = TF1, 1 = TF2
byte getTfANumBlocking() {
  while (true) {
    sndService();
    byte rtn = getTfxNum(0);
    if (rtn != 0) {
      sndPlay(SND_BUTTON);
      while (getTfxNum(0))
        sndService();
      return rtn;
    }
    rtn = getTfxNum(1);
    if (rtn != 0) {
      sndPlay(SND_BUTTON);
      while (getTfxNum(1))
        sndService();
      return 0x80 | rtn;
    }
  }
}

byte getTfxNumBlocking(byte plyr) {
  while (true) {
    sndService();
    byte rtn = getTfxNum(plyr);
    if (rtn != 0) {
      sndPlay(SND_BUTTON);
      while (getTfxNum(plyr))
        sndService();
      return rtn;
    }
  }
}

byte getTfxNum(byte plyr) {
  noInterrupts();
  uint16_t n = plyr ? TF2BTND : TF1BTND;
  interrupts();
  return getNum(n);
}

byte getNum(uint16_t keys) {
  byte num = 0;
  for (byte x = 0; x < 16; x++) {
    if (bitRead(keys, x)) {
      if (num == 0)
        num = x + 1;
      else
        return 0;
    }
  }
  return num;
}

uint32_t Millis() {
  noInterrupts();
  uint32_t rtn = MILLIS;
  interrupts();
  return rtn;
}

void Delay(uint16_t ms) {
  uint32_t start = Millis();
  while (Millis() < start + ms) {
    sndService();
  }
}

// System clock ISR. Goes off at 16Khz
ISR(TIMER1_COMPA_vect) {
  static byte millisDiv = 0;
  // ---------------- Sound
  SNDIsr();
  // ---------------- Peripherals
  MPIsr();
  // ---------------- Timekeeping
  if ((millisDiv & 15) == 0)
    MILLIS++;
  millisDiv++;
}

inline void SNDIsr() {
  if (SNDEN) {
    bitWrite(DDRD, 3, 1);
    OCR2B = (sndBuf[sndReadPtr++]);
    sndReadPtr &= 511;
  }
  else {
    OCR2B = 0;
    bitWrite(DDRD, 3, 0); // Disable output to stop WHIIIINE... I whimper in the night...
  }
}
