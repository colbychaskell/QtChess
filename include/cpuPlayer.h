#ifndef CPUPLAYER_H
#define CPUPLAYER_H

#include "board.h"
#include "piece.h"

class CPUPlayer {
 public:
  explicit CPUPlayer(Piece::Side side)
      : n_move(0), side(side), score(0), checkmate(false), stalemate(false) {}
  void makeMove(Board& board);
  void makeRandomMove(Board& board);
  bool inCheckmate() const;
  bool inStalemate() const;
  Piece::Side getSide() const;

 private:
  size_t n_move;  // Current move #
  Piece::Side side;
  size_t score;
  bool checkmate;
  bool stalemate;
};

#endif
