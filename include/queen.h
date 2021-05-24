#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "position.h"
#include <string>

class Queen : public Piece {
public:
  explicit Queen(Piece::Side side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;

};

#endif
