#include "cpuPlayer.h"

#include <stdlib.h>

#include <iostream>
#include <map>
#include <vector>

#include "board.h"
#include "position.h"

void CPUPlayer::makeMove(Board& board) {
  if (this->n_move == 0) {
    Position piece = Position(1, 0);
    Position dest = Position(3, 0);
    score += board.makeMove(this->side, piece, dest);

    this->n_move++;
  }
}

void CPUPlayer::makeRandomMove(Board& board) {
  srand(time(NULL));
  std::map<Position, std::vector<Position>> moveMap;
  std::vector<Position> pieces = board.findPieces(this->side);

  for (auto piece : pieces) {  // iterate through every owned piece
    std::vector<Position> tempMovesList = board.getPieceMoves(piece);
    // if moves are available to this piece add it to the map
    if (tempMovesList.size() != 0) {
      moveMap.insert(std::pair<Position, std::vector<Position>>(
          Position(piece.row, piece.column), tempMovesList));
    }
  }

  // iterate and randomly select a move from the map
  size_t randPiece = size_t(rand()) % moveMap.size();
  std::map<Position, std::vector<Position>>::iterator mapRandPiece =
      moveMap.begin();
  std::advance(mapRandPiece, randPiece);
  size_t randMove = size_t(rand()) % mapRandPiece->second.size();
  try {  // throws error if in check
    // Need to check if currently in check

    board.makeMove(this->side, mapRandPiece->first,
                   mapRandPiece->second.at(randMove));
  } catch (const std::runtime_error& e) {
    bool moved = false;
    for (auto piece = moveMap.begin(); piece != moveMap.end(); piece++) {
      for (auto move = piece->second.begin(); move != piece->second.end();
           move++) {
        if (!moved) {
          try {
            board.makeMove(this->side, piece->first, *move);
            moved = true;
          } catch (const std::runtime_error& e) {
            // ignore
          }
        }
      }
    }
    if (!moved && board.isInCheck(this->side)) {
      this->checkmate = true;
    } else if (!moved) {
      this->stalemate = true;
    }
  }
}

bool CPUPlayer::inCheckmate() const { return checkmate; }

bool CPUPlayer::inStalemate() const { return stalemate; }

Piece::Side CPUPlayer::getSide() const { return this->side; }
