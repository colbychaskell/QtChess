#ifndef BOARDSCEME_H
#define BOARDSCEME_H

#include "board.h"
#include "boardsquare.h"
#include "pieceqt.h"
//#include "humanPlayer.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <vector>

#include "cpuPlayer.h"

class BoardScene : public QGraphicsScene {
 public:
  BoardScene(QObject *parent, const Piece::Side &humanSide);
  ~BoardScene();
  Board &getBoard();
  void resetBoard();
  void updateBoard();

 protected:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

 private:
  // HumanPlayer humanPlayer;
  CPUPlayer cpuPlayer;
  PieceQt *selectedPiece;
  Board gameBoard;
  std::vector<BoardSquare *> *squares;
  std::vector<PieceQt *> pieces;
};

#endif  // BOARDSCEME_H
