#include "position.h"

#include <sstream>

bool Position::operator==(const Position& other) const {
  return ((this->row == other.row) && (this->column == other.column));
}
bool Position::operator!=(const Position& other) const {
  return ((this->row != other.row) || (this->column != other.column));
}
