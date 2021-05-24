#include "piece.h"

Piece::Piece(Side side, size_t value) : side(side), value(value) {}

Piece::Side Piece::getSide() const {
    return this->side;
}

size_t Piece::getValue() const {
    return this->value;
}

Piece::~Piece() {}
