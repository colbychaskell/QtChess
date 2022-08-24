#include "position.h"

#include <sstream>

Position::Position(size_t row, size_t column) : row(row), column(column){};

bool Position::operator==(const Position& other) const {
  return ((this->row == other.row) && (this->column == other.column));
}
bool Position::operator!=(const Position& other) const {
  return ((this->row != other.row) || (this->column != other.column));
}
bool Position::operator<(const Position& other) const {
  if (this->row < other.row) {
    return true;
  } else if (this->row == other.row) {
    if (this->column < other.column) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}