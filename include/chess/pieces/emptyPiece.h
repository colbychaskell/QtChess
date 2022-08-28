#ifndef EMPTYPIECE_H
#define EMPTYPIECE_H

#include "piece.h"

class EmptyPiece : public Piece {
 public:
  EmptyPiece();
  std::string getName() const;
  size_t getValue() const;
  Piece::Side getSide() const;
  bool isValidMove(const Position& piece, const Position& dest) const;
};

#endif
