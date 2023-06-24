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
  // Prevent the piece from moving to the same position
  if (piece.column == dest.column && piece.row == dest.row) {
    return false;
  }

  // Horizontal/Vertical Moves Only
  if ((dest.column == piece.column) || (dest.row == piece.row)) {
    return true;
  }

  return false;
}
