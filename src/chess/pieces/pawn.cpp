#include "pawn.h"

Pawn::Pawn(Piece::Side side) : Piece(side, 1) {}

std::string Pawn::getName() const {
  switch (this->getSide()) {
    case Side::B:
      return "PB";
    case Side::W:
      return "PW";
    default:
      return "";
  }
}

bool Pawn::isValidMove(const Position& piece, const Position& dest) const {
  // Prevent the piece from moving to the same position
  if (piece.column == dest.column && piece.row == dest.row) {
    return false;
  }

  // Prevent all horizontal moves
  if (piece.row == dest.row) {
    return false;
  }

  // Side specific checks
  if (this->getSide() == Side::W) {
    // Prevent backwards movement
    if (dest.row < piece.row) {
      return false;
    }

    // Allow +2 on initial row
    if ((piece.row == 1) && (dest.row == 3) && (piece.column == dest.column)) {
      return true;
    }
  } else {
    // Prevent backwards movement
    if (dest.row > piece.row) {
      return false;
    }

    // Allow +2 on initial row
    if ((piece.row == 6) && (dest.row == 4) && (piece.column == dest.column)) {
      return true;
    }
  }

  // Allow one square move forward or diagonal capture
  if ((abs(int(dest.column) - int(piece.column)) <= 1) &&
      (abs(int(dest.row) - int(piece.row)) <= 1)) {
    return true;
  }
}
