#ifndef PIECE_H
#define PIECE_H

#include <string>

#include "position.h"

/*
  Abstract Piece Class
*/
class Piece {
 public:
  enum Side {
    B,
    W,
    E,
  };

  Piece(Side side, size_t value);
  size_t getValue() const;
  Side getSide() const;

  virtual ~Piece();
  virtual std::string getName() const = 0;
  virtual bool isValidMove(const Position& piece,
                           const Position& dest) const = 0;

 private:
  Side side;
  size_t value;
};

#endif
