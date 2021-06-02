#include "boardscene.h"
#include "position.h"
#include "piece.h"
#include "humanPlayer.h"
#include "cpuPlayer.h"

#include <iostream>

BoardScene::BoardScene(QObject *parent, const Piece::Side& humanSide) : QGraphicsScene(parent), cpuPlayer(CPUPlayer(humanSide == Piece::Side::W ? Piece::Side::B : Piece::Side::W)), gameBoard(Board())
{
    this->setSceneRect(0,0,400,400);
    squares = new std::vector<BoardSquare*>();
    pieces = std::vector<PieceQt*>();


    Position square = Position(0,0);
    for(size_t x=0; x<8; x++) {
      for(size_t y=0; y<8; y++) {
          square = Position(y,x);
          if(gameBoard.at(square)->getName() != "EE") {
            pieces.push_back(new PieceQt(gameBoard.at(square)->getName(), square));
          }
          if (x%2 !=0) {
              if(y%2 == 0) {
                 squares->push_back(new BoardSquare(nullptr, Position(y,x), QColor(247,229,165)));
              }
              else {
                 squares->push_back(new BoardSquare(nullptr, Position(y,x), QColor(20,95,75)));
              }
          }
          else {
              if(y%2 == 0) {
                 squares->push_back(new BoardSquare(nullptr, Position(y,x), QColor(20,95,75)));
              }
              else {
                 squares->push_back(new BoardSquare(nullptr, Position(y,x), QColor(247,229,165)));
              }
          }
          pieces.back()->setZValue(1);


          this->addItem(pieces.back());
          this->addItem(squares->back());
      }
    }
    if(humanSide != Piece::Side::W) {
        cpuPlayer.makeRandomMove(gameBoard);
    }
    this->updateBoard();
}

Board& BoardScene::getBoard() {
    return this->gameBoard;
}

void BoardScene::resetBoard() {
    this->gameBoard.resetBoard();
    //this->humanPlayer = HumanPlayer(humanPlayer.getSide());
    this->cpuPlayer = CPUPlayer(cpuPlayer.getSide());
    cpuPlayer.makeRandomMove(gameBoard);
    this->updateBoard();
}

void BoardScene::updateBoard() {
    std::vector<PieceQt*> tempPieces;

    Position square = Position(0,0);
    for(auto piece : pieces) {
        this->removeItem(piece);
        delete piece;
    }
    for(size_t x=0; x<8; x++) {
      for(size_t y=0; y<8; y++) {
          square = Position(x,y);
          if(gameBoard.at(square)->getSide() != Piece::Side::E) {
            tempPieces.push_back(new PieceQt(gameBoard.at(square)->getName(), square));
            this->addItem(tempPieces.back());
          }
      }
    }
    pieces = tempPieces;
}


void BoardScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
            return;

    if(event->button() == Qt::LeftButton) {
        Position clickPosition = Position(9,9);
        for(auto square : *squares) {
            if(square->sceneBoundingRect().contains(event->buttonDownScenePos(Qt::LeftButton)))
            clickPosition = square->getPosition();
        }
        if(clickPosition != Position(9,9)) {
            selectedPiece = nullptr;
            for(auto piece : pieces) {
                if(piece->getPosition() == clickPosition) {
                   selectedPiece = piece;
                }
            }
        }
        else {
            return;
        }
    }
}

void BoardScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(selectedPiece != nullptr) {
        selectedPiece->setPos(event->scenePos().x()-25, event->scenePos().y()-25);
    }
}

//Game loop essentially contained within release event
void BoardScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if(selectedPiece != nullptr) {
        try {
            if(event->button() == Qt::LeftButton) {
                Position mousePosition = Position(9,9);
                for(auto square : *squares) {
                    if(square->sceneBoundingRect().contains(event->scenePos()))
                        mousePosition = square->getPosition();
                    }
                    if(mousePosition != Position(9,9)) {
                        if(cpuPlayer.getSide() == Piece::Side::W) {
                            gameBoard.makeMove(Piece::Side::B, selectedPiece->getPosition(), mousePosition); //Try to move on underlying board
                            selectedPiece->movePiece(mousePosition); //if movable, move on the graphics scene
                        }
                        else {
                            gameBoard.makeMove(Piece::Side::W, selectedPiece->getPosition(), mousePosition); //Try to move on underlying board
                            selectedPiece->movePiece(mousePosition); //if movable, move on the graphics scene
                        }


                        cpuPlayer.makeRandomMove(gameBoard); //CPU takes turn
                        this->updateBoard();

                        if(cpuPlayer.inCheckmate()) {
                            std::cout << "Checkmate" << std::endl;
                            //this->resetBoard();
                        }
                        if(cpuPlayer.inStalemate()) {
                            std::cout << "Stalemate" << std::endl;
                        }

                }
            }
            selectedPiece = nullptr;
        }
        catch(const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            selectedPiece->movePiece(selectedPiece->getPosition()); //undo any movement
            selectedPiece = nullptr;
        }
    }
}

BoardScene::~BoardScene() {
    delete squares;
    for (auto piece : pieces) {
        delete piece;
    }
}
