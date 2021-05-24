#include "boardsquare.h"
#include "position.h"

BoardSquare::BoardSquare(QGraphicsItem *parent, Position position, QBrush color) : QGraphicsRectItem(parent), position(position), color(color)
{
    this->setRect(position.column*50, position.row*50, 50, 50);
    this->setBrush(color);

}

Position BoardSquare::getPosition() {
    return position;
}
