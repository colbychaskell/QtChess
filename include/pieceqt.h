#ifndef PIECEQT_H
#define PIECEQT_H

#include "position.h"
#include <QObject>
#include <QPixmap>
#include <QGraphicsItem>
#include <QtCore>
#include <QtGui>
#include <string>

class PieceQt : public QGraphicsPixmapItem
{
public:
    PieceQt(const std::string& name, const Position& position, QGraphicsItem *parent = nullptr);
    ~PieceQt();
    void movePiece(const Position& position);
    Position getPosition();

private:
    std::string name;
    Position position;
    QPixmap piecePM;
};

#endif // PIECEQT_H
