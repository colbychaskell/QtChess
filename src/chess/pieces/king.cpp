#include "king.h"

#include <cmath>

King::King(Piece::Side side)
    : Piece(side, 0) {  // King has value of zero since it cant be captured
  this->canCastle = true;
}

std::string King::getName() const {
  switch (this->getSide()) {
    case Side::B:
      return "KB";
    case Side::W:
      return "KW";
    default:
      return "";
  }
}

bool King::isValidMove(const Position& piece, const Position& dest) const {
  // Prevent the piece from moving to the same position
  if (piece.column == dest.column && piece.row == dest.row) {
    return false;
  }

  // Moves one space in any direction
  if (abs(int(dest.column) - int(piece.column)) <= 1 &&
      abs(int(dest.row) - int(piece.row)) <= 1) {
    return true;
  }

  return false;
}
