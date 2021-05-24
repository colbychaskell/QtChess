#ifndef BOARDSQUARE_H
#define BOARDSQUARE_H

#include "position.h"
#include "board.h"
#include <QGraphicsRectItem>
#include <QtCore>
#include <QtGui>


class BoardSquare : public QGraphicsRectItem
{
public:
    BoardSquare(QGraphicsItem *parent = nullptr, Position position = Position(0,0), QBrush color = Qt::white);
    Position getPosition();

private:
    Position position;
    QBrush color;
};

#endif // BOARDSQUARE_H
