#include "queen.h"

#include <cmath>

Queen::Queen(Piece::Side side) : Piece(side, 9) {}

std::string Queen::getName() const {
  switch (this->getSide()) {
    case Side::B:
      return "QB";
    case Side::W:
      return "QW";
    default:
      return "";
  }
}

bool Queen::isValidMove(const Position& piece, const Position& dest) const {
  // Prevent the piece from moving to the same position
  if (piece.column == dest.column && piece.row == dest.row) {
    return false;
  }

  // Diagonal Moves
  if (abs(int(dest.column) - int(piece.column)) ==
      abs(int(dest.row) - int(piece.row))) {
    return true;
  }

  // Horizontal/Vertical Moves
  if ((dest.column == piece.column) || (dest.row == piece.row)) {
    return true;
  }

  return false;
}
