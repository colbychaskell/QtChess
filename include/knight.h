#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>

#include "piece.h"
#include "position.h"

class Knight : public Piece {
 public:
  explicit Knight(const Piece::Side& side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;
};

#endif
