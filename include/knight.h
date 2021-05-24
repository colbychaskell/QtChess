#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "position.h"
#include <string>

class Knight : public Piece {
public:
  explicit Knight(const Piece::Side& side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;
};

#endif
