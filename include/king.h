#ifndef KING_H
#define KING_H

#include "piece.h"
#include "position.h"
#include <string>

class King : public Piece {
public:
  explicit King(Piece::Side side);
  std::string getName() const;
  bool isValidMove(const Position& piece, const Position& dest) const;

private:
  bool canCastle;

};

#endif
