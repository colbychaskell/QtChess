#include "king.h"

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
  bool rowUp = dest.row == piece.row + 1;
  bool rowDown = dest.row == piece.row - 1;
  bool colUp = dest.column == piece.column + 1;
  bool colDown = dest.column == piece.column - 1;
  bool col = dest.column == piece.column;
  bool row = dest.row == piece.row;

  if (((rowUp || rowDown) && (colUp || colDown || col)) ||
      ((colUp || colDown) && (rowUp || rowDown || row))) {
    return true;
  } else {
    return false;
  }
}
