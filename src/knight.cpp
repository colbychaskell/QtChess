#include "knight.h"

Knight::Knight(const Piece::Side& side) : Piece(side, 3) {}

std::string Knight::getName() const {
  switch(this->getSide()) {
    case Side::B :
      return "NB";
    case Side::W :
      return "NW";
    default :
      return "";
  }
}

bool Knight::isValidMove(const Position& piece, const Position& dest) const {
  if((dest.row == piece.row+1) || (dest.row == piece.row-1)) {
    if((dest.column == piece.column+2) || (dest.column == piece.column-2)) {
      return true;
    }
    else {
      return false;
    }
  }
  else if((dest.row == piece.row+2) || (dest.row == piece.row-2)) {
    if((dest.column == piece.column+1) || (dest.column == piece.column-1)) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}
