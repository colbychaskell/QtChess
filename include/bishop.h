#ifndef BISHOP_H
#define BISHOP_H

#include <string>

#include "piece.h"
#include "position.h"

class Bishop : public Piece {
 public:
  explicit Bishop(Piece::Side Side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;
};

#endif
