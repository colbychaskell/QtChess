#ifndef BOARDSCEME_H
#define BOARDSCEME_H

#include "board.h"
#include "boardsquare.h"
#include "pieceqt.h"
//#include "humanPlayer.h"
#include "cpuPlayer.h"

#include <QObject>
#include <vector>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class BoardScene : public QGraphicsScene
{
public:
    BoardScene(QObject *parent, const Piece::Side& humanSide);
    ~BoardScene();
    Board& getBoard();
    void resetBoard();
    void updateBoard();
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    //HumanPlayer humanPlayer;
    CPUPlayer cpuPlayer;
    PieceQt* selectedPiece;
    Board gameBoard;
    std::vector<BoardSquare*> *squares;
    std::vector<PieceQt*> pieces;
};

#endif // BOARDSCEME_H
