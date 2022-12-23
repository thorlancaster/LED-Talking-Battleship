# LED-Talking-Battleship
Talking Battleship implemented on a 12x12 LED grid with an ATMega328 processor

This project is composed of:
* A Control PCB that contains the main circuitry and power supplies
* A LED display PCB that drives an 12x12 grid of RGB LEDs. You'll need to make 4 of these.
* Code to run the above boards
* A compiled audio file you'll need to write to the SPI Flash chip for audio functionality
 (If you leave the flash chip blank, the game will not play audio)
