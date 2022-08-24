#include "pieceqt.h"

#include <iostream>

PieceQt::PieceQt(const std::string& name, const Position& position,
                 QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), name(name), position(position) {
  this->setFlag(ItemSendsGeometryChanges);
  this->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
  // Set the diaplyed location of the piece
  size_t topLeftX = 0, topLeftY = 0;
  size_t x = topLeftX + 50 * position.column, y = topLeftY + 50 * position.row;
  this->setPos(x, y);
  // Paint correct pixmap
  if (name == "RW") {
    piecePM = QPixmap(":/resources/resources/img/wRook.png");
  } else if (name == "NW") {
    piecePM = QPixmap(":/resources/resources/img/wKnight.png");
  } else if (name == "BW") {
    piecePM = QPixmap(":/resources/resources/img/wBishop.png");
  } else if (name == "QW") {
    piecePM = QPixmap(":/resources/resources/img/wQueen.png");
  } else if (name == "KW") {
    piecePM = QPixmap(":/resources/resources/img/wKing.png");
  } else if (name == "PW") {
    piecePM = QPixmap(":/resources/resources/img/wPawn.png");
  } else if (name == "RB") {
    piecePM = QPixmap(":/resources/resources/img/bRook.png");
  } else if (name == "NB") {
    piecePM = QPixmap(":/resources/resources/img/bKnight.png");
  } else if (name == "BB") {
    piecePM = QPixmap(":/resources/resources/img/bBishop.png");
  } else if (name == "QB") {
    piecePM = QPixmap(":/resources/resources/img/bQueen.png");
  } else if (name == "KB") {
    piecePM = QPixmap(":/resources/resources/img/bKing.png");
  } else if (name == "PB") {
    piecePM = QPixmap(":/resources/resources/img/bPawn.png");
  } else if (name == std::string("EE")) {
    // piecePM = QPixmap();
  } else {
    throw std::invalid_argument("INVALID PIECE");
  }
  if (!piecePM.isNull()) {
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setPixmap(piecePM.scaled(50, 50, Qt::KeepAspectRatio));
  } else {
    // this->setPixmap(piecePM);
  }

  this->setZValue(10);
}

void PieceQt::movePiece(const Position& position) {
  size_t topLeftX = 0, topLeftY = 0;
  size_t x = topLeftX + 50 * position.column, y = topLeftY + 50 * position.row;
  this->setPos(x, y);
  this->position = position;
}

Position PieceQt::getPosition() { return position; }

PieceQt::~PieceQt() {}
