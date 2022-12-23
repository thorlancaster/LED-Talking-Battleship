// Place ships on a player's board. Only valid for letter/number 1-10
// Ship positions equal original 1989 game
void placeShipsInstant(byte player, byte letter, byte number) {
  if (letter == 1) {
    if (number == 1) {
      placeShip(7, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(9, 2, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 4, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 5, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(7, 4, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(7, 7, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 10, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(10, 5, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 5, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 1, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(4, 1, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 3, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 10, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 7, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(7, 2, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 7, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 3, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 2, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(9, 7, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 3, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(3, 7, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(10, 7, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 7, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 2, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(7, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 7, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 6, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 8, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(10, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(9, 7, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 2, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 7, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(10, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(6, 7, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 2, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(9, 8, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 8, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(3, 1, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 6, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(7, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }

  if (letter == 2) {
    if (number == 1) {
      placeShip(2, 2, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 8, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 5, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(10, 3, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(8, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 10, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 1, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 7, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 4, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(6, 9, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(10, 8, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(3, 10, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 7, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(3, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(7, 6, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 2, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 10, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 3, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(1, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 4, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 9, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 10, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 8, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(2, 7, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(9, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 10, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 2, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(5, 5, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 7, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 3, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 10, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(8, 1, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(9, 6, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 6, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 10, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(5, 3, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(2, 10, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 5, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(3, 7, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(2, 9, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 2, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(9, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 3, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }

  if (letter == 3) {
    if (number == 1) {
      placeShip(4, 5, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 8, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 7, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 6, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(8, 4, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(5, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 6, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 2, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 10, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(5, 9, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 2, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 1, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 10, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(7, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 6, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 5, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 4, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(5, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 10, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(10, 7, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 3, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 4, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(6, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 4, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 6, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 3, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(3, 7, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 5, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 1, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(7, 2, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(3, 1, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(2, 7, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(10, 6, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 2, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 9, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(8, 8, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 2, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 5, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 5, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(4, 3, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(10, 7, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 2, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 6, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }


  if (letter == 4) {
    if (number == 1) {
      placeShip(3, 3, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 7, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 2, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 4, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(7, 4, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 8, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 8, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 3, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(3, 1, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 8, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 10, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(5, 7, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(10, 2, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 5, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 1, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(1, 9, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 7, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 4, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 6, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(5, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(9, 6, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 1, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 7, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(9, 3, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 2, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 7, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 10, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 1, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(9, 9, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 10, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 6, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(8, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(3, 8, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 6, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 4, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 5, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(10, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(2, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 4, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 6, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(8, 1, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 9, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }

  if (letter == 5) {
    if (number == 1) {
      placeShip(5, 5, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 1, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(9, 5, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(7, 3, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 3, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 1, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 7, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 2, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(6, 1, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 4, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 2, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 7, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 3, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(3, 4, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(10, 4, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 1, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(10, 4, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(9, 1, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 1, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(8, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(9, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(3, 5, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 4, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(7, 1, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 6, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 4, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 4, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(10, 8, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 4, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 2, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(10, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(3, 1, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 7, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 3, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 6, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(5, 2, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 8, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 7, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 3, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }

  if (letter == 6) {
    if (number == 1) {
      placeShip(6, 6, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(9, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 1, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 1, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(4, 7, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 3, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 3, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 5, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 10, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(2, 6, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 7, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 1, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(7, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(7, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 3, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 7, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(9, 7, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 1, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(3, 9, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 5, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 5, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(9, 5, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 3, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 5, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(8, 1, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(5, 5, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 8, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 1, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(9, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(10, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(4, 2, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 6, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 6, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 7, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(8, 4, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 9, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 5, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 1, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(2, 6, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 2, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 9, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 3, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(3, 10, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }

  if (letter == 7) {
    if (number == 1) {
      placeShip(7, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 6, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 6, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 5, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 2, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(1, 7, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 2, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(10, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 6, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(2, 8, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 10, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 9, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(8, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(1, 3, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 4, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 6, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 2, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 1, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(9, 4, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 7, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 6, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 5, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(4, 7, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(2, 6, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 5, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 4, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 6, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(8, 1, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(10, 3, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 1, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(10, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 9, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 6, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 3, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 6, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(9, 6, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(8, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(3, 2, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 1, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 3, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(2, 3, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 2, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 4, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 6, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }

  if (letter == 8) {
    if (number == 1) {
      placeShip(9, 8, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 3, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 6, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 10, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(5, 9, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 3, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 1, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 6, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(10, 2, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 6, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 7, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(9, 7, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 4, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(4, 3, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(2, 3, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(9, 6, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 6, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 5, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(6, 5, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 6, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(10, 1, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(10, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(3, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 7, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 6, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(4, 4, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(7, 4, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 7, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 2, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 7, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 8, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(6, 6, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(5, 4, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 6, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 1, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(1, 1, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(9, 1, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(3, 9, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 8, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 7, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(3, 9, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 8, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 9, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 5, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(3, 4, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }

  if (letter == 9) {
    if (number == 1) {
      placeShip(9, 4, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 4, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(5, 3, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(8, 4, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(5, 8, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 10, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(8, 5, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(10, 1, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(7, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 1, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 6, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 10, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(2, 3, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(9, 6, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 10, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(3, 4, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(8, 5, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 4, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(9, 4, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(3, 6, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 10, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 5, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 6, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 3, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(6, 10, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(9, 3, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(10, 5, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 3, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(8, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(4, 1, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(2, 5, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 7, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 3, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(1, 4, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(6, 9, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 5, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(7, 3, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(9, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(4, 6, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 8, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(6, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 7, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 4, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }


  if (letter == 10) {
    if (number == 1) {
      placeShip(8, 6, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(7, 4, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(4, 3, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(6, 10, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 2) {
      placeShip(10, 8, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(2, 7, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(7, 3, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 5, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 4, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 3) {
      placeShip(1, 4, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(2, 7, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 4, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(6, 1, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 1, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 4) {
      placeShip(4, 1, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 10, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(2, 9, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(3, 5, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(8, 1, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 5) {
      placeShip(3, 1, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(10, 8, DIR_EAST, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(5, 8, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(2, 6, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(2, 4, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 6) {
      placeShip(10, 4, DIR_EAST, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(3, 8, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(1, 10, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 2, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(8, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 7) {
      placeShip(3, 6, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(1, 7, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(9, 7, DIR_EAST, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(9, 3, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 6, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 8) {
      placeShip(7, 2, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 8, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 6, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 3, DIR_SOUTH, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 9) {
      placeShip(1, 1, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(4, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(8, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(4, 9, DIR_SOUTH, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(1, 4, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
    if (number == 10) {
      placeShip(9, 1, DIR_SOUTH, player, getBoatLength(TYPE_PATROL_BOAT), TYPE_PATROL_BOAT);
      placeShip(2, 1, DIR_SOUTH, player, getBoatLength(TYPE_DESTROYER), TYPE_DESTROYER);
      placeShip(3, 3, DIR_SOUTH, player, getBoatLength(TYPE_SUBMARINE), TYPE_SUBMARINE);
      placeShip(1, 5, DIR_EAST, player, getBoatLength(TYPE_BATTLESHIP), TYPE_BATTLESHIP);
      placeShip(5, 5, DIR_EAST, player, getBoatLength(TYPE_CARRIER), TYPE_CARRIER);
    }
  }
}
