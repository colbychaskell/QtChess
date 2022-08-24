#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "board.h"
#include "piece.h"
#include "position.h"

class HumanPlayer {
 public:
  void makeMove(Board& board);  // Manipulates the board if move is legal
  explicit HumanPlayer(Piece::Side side) : side(side), score(0) {}

  void makeMove(Board& board, const Position& piece,
                const Position& dest);  // used for testing
  Piece::Side getSide() const;

 private:
  Piece::Side side;
  size_t score;
};

#endif
