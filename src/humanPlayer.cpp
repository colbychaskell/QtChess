#include "humanPlayer.h"
#include "board.h"
#include "piece.h"
#include "position.h"

#include <iostream>
#include <string>
#include <exception>

void HumanPlayer::makeMove(Board& board) {
  bool moved = false;
  while(!moved) {
    std::string moveString = "";
    std::cout << "Please enter your move: (Ex. A2-A4) " << std::endl;
    std::cin >> moveString; //No processing yet


    size_t colA = moveString[0] - 'A';
    size_t rowA = moveString[1] - '1';
    size_t colB = moveString[2] - 'A';
    size_t rowB = moveString[3] - '1';

    Position piece = Position(rowA,colA);
    Position dest = Position(rowB,colB);

    try {
      board.makeMove(this->side, piece, dest);
      moved = true;
    }
    catch (const std::runtime_error& e) {
      std::cout << e.what() << std::endl;
      moved = false;
    }


  }
}

void HumanPlayer::makeMove(Board& board, const Position& piece, const Position& dest) {
  bool moved = false;
  while(!moved) {
    try {
      board.makeMove(this->side, piece, dest);
      moved = true;
    }
    catch (const std::runtime_error& e) {
      std::cout << e.what() << std::endl;
      moved = false;
    }


  }
}

Piece::Side HumanPlayer::getSide() const {
    return this->side;
}
