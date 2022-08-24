#include "rook.h"

Rook::Rook(Piece::Side side) : Piece(side, 5) {}

std::string Rook::getName() const {
  switch (this->getSide()) {
    case Side::B:
      return "RB";
    case Side::W:
      return "RW";
    default:
      return "";
  }
}

bool Rook::isValidMove(const Position& piece, const Position& dest) const {
  if ((dest.column == piece.column) ^
      (dest.row == piece.row)) {  // Horizontal/Vertical Moves
    return true;
  } else {
    return false;
  }
}
