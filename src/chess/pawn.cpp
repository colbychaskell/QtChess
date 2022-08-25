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
  if (this->getSide() == Side::W) {
    if (piece.row == 1) {
      if ((dest.column == piece.column) &&
          (dest.row == piece.row + 1 ||
           dest.row == piece.row + 2)) {  // Allow +2 on initial row
        return true;
      } else if ((abs(int(dest.column) - int(piece.column)) == 1) &&
                 (int(dest.row) - int(piece.row) == +1)) {
        return true;
      } else {
        return false;
      }
    } else if ((dest.column == piece.column) &&
               (dest.row ==
                piece.row + 1)) {  // After piece has left initial row
      return true;
    } else if ((abs(int(dest.column) - int(piece.column)) == 1) &&
               (dest.row - piece.row == 1)) {  // Diagonal attack
      return true;
    } else {
      return false;
    }
  } else {
    if (piece.row == 6) {
      if ((dest.column == piece.column) &&
          (dest.row == piece.row - 1 ||
           dest.row == piece.row - 2)) {  // Allow +2 on initial row
        return true;
      } else if ((abs(int(dest.column) - int(piece.column)) == 1) &&
                 (int(dest.row) - int(piece.row) == -1)) {
        return true;
      } else {
        return false;
      }
    } else if ((dest.column == piece.column) &&
               (dest.row ==
                piece.row - 1)) {  // After piece has left initial row
      return true;
    } else if ((abs(int(dest.column) - int(piece.column)) == 1) &&
               (int(dest.row) - int(piece.row) == -1)) {  // Diagonal attack
      return true;
    } else {
      return false;
    }
  }
}
