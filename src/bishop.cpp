#include "bishop.h"

Bishop::Bishop(Piece::Side side) : Piece(side, 5) {}

std::string Bishop::getName() const {
  switch (this->getSide()) {
    case Side::B:
      return "BB";
    case Side::W:
      return "BW";
    default:
      return "";
  }
}

bool Bishop::isValidMove(const Position& piece, const Position& dest) const {
  if ((abs(int(dest.column) - int(piece.column)) ==
       abs(int(dest.row) - int(piece.row))) &&
      (dest.row !=
       piece.row)) {  // Diagonal Move if change in column == change in row
    return true;
  } else {
    return false;
  }
}
