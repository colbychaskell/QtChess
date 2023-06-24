#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#include "piece.h"
#include "position.h"

class Board {
 public:
  Board();  // Constructor creates the starting board setup
  void printBoard(std::ostream& out) const;  // display the board to ostream out
  size_t makeMove(const Piece::Side& playerSide, const Position& piece,
                  const Position& dest);  // returns value of any captured piece
  size_t testMove(const Piece::Side& playerSide, const Position& piece,
                  const Position& dest)
      const;  // returns value of piece to be captured, does not execute move
  std::vector<Position> findPieces(const Piece::Side& side)
      const;  // returns list of all piece locations for specified side
  std::vector<Position> getPieceMoves(const Position& piece)
      const;  // returns list of all possible moves for piece
  Piece* at(const Position& piece)
      const;  // Retrieve raw pointer of piece from position
  bool isInCheck(const Piece::Side& side) const;  // Check if side is in check
  void resetBoard();

 private:
  std::string boardString;
  std::array<std::array<std::unique_ptr<Piece>, 8>, 8>
      pieces;  // Underlying 8x8 array to represent the board
  bool whiteCastleAllowed;
  bool blackCastleAllowed;

  /* Helper Functions */
  size_t movePiece(const Position& pieceA,
                   const Position& pieceB);  // Move pieces in the array
  bool hasPiece(const Position& pos) const;  // Check if square has a piece
  bool isSide(const Position& piece, const Piece::Side& side)
      const;                 // Check if piece is of specified side
  void updateBoardString();  // update the board string if the array changes
  void buildBoard();         // Creates the starting board setup
  bool isChecking(const Position& piece)
      const;  // Check if specified piece is checking other side
};

#endif
