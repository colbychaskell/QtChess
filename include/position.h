#ifndef POSITION_H
#define POSITION_H

#include <string>

struct Position {
  size_t row;
  size_t column;

  Position(size_t row, size_t column);

  bool operator==(const Position& other) const;
  bool operator!=(const Position& other) const;
  bool operator<(const Position& other) const;
};

#endif
