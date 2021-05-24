#include "emptyPiece.h"

EmptyPiece::EmptyPiece() : Piece(Piece::Side::E, 0) {}

std::string EmptyPiece::getName() const {
  return "EE";
}

bool EmptyPiece::isValidMove(const Position& piece, const Position& dest) const {
  return false;
}
