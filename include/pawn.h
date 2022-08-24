#ifndef PAWN_H
#define PAWN_H

#include <string>

#include "piece.h"
#include "position.h"

class Pawn : public Piece {
 public:
  explicit Pawn(Piece::Side Side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;
};

#endif
