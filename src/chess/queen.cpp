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
  if (abs(int(dest.column) - int(piece.column)) ==
      abs(int(dest.row) - int(piece.row))) {  // Diagonal Move if change in
                                              // column == change in row
    return true;
  } else if ((dest.column == piece.column) ^
             (dest.row == piece.row)) {  // Horizontal/Vertical Moves
    return true;
  } else {
    return false;
  }
}
