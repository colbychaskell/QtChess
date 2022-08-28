#ifndef KING_H
#define KING_H

#include <string>

#include "piece.h"
#include "position.h"

class King : public Piece {
 public:
  explicit King(Piece::Side side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;

 private:
  bool canCastle;
};

#endif
