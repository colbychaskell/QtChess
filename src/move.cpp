#include "move.h"

#include "position.h"

Move::Move(const std::string& moveString) {
  char tempChar = moveString[0];
  if (tempChar > 64 && tempChar < 73) {  // Capital letter
    this->to = Position((tempChar - 65), moveString[1])
  } else if (tempChar > 96 && tempChar < 105) {  // Lowercase Letter

  } else {  // Illegal letter
    // THROW EXCEPTION ILLEGALMOVE
  }
}
