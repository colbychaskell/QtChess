#ifndef QUEEN_H
#define QUEEN_H

#include <string>

#include "piece.h"
#include "position.h"

class Queen : public Piece {
 public:
  explicit Queen(Piece::Side side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;
};

#endif
