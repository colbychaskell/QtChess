#ifndef ROOK_H
#define ROOK_H

#include <string>

#include "piece.h"

class Rook : public Piece {
 public:
  explicit Rook(Piece::Side side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;
};

#endif
