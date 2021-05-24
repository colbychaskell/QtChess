#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "position.h"
#include <string>

class Bishop : public Piece {

public:
  explicit Bishop(Piece::Side Side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;
};

#endif
