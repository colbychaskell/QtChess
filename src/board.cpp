#include "board.h"

#include <stdio.h>

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

#include "bishop.h"
#include "emptyPiece.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "position.h"
#include "queen.h"
#include "rook.h"

void Board::resetBoard() { this->buildBoard(); }

bool Board::isInCheck(const Piece::Side& side) const {
  Piece::Side otherSide = Piece::Side::E;
  if (side == Piece::Side::W) {
    otherSide = Piece::Side::B;
  } else {
    otherSide = Piece::Side::W;
  }

  std::vector<Position> pieceList = this->findPieces(otherSide);
  for (auto piece = pieceList.begin(); piece != pieceList.end(); piece++) {
    if (this->isChecking(*piece)) {
      return true;
    }
  }
  return false;
}

// Checks if this piece is applying check to the other side
bool Board::isChecking(const Position& piece) const {
  if (this->at(piece)->getName().find('K') != std::string::npos) {
    return false;  // King cant be next to another king
  } else {
    std::vector<Position> movesList = this->getPieceMoves(piece);
    for (auto move = movesList.begin(); move != movesList.end(); move++) {
      if (this->at(*move)->getName().find('K') != std::string::npos) {
        return true;
      }
    }
    return false;
  }
}

// Returns a list of possible destinations for the specified piece
std::vector<Position> Board::getPieceMoves(const Position& piece) const {
  std::vector<Position> tempMovesList;
  for (size_t row = 0; row < 8; row++) {
    for (size_t col = 0; col < 8; col++) {
      try {
        if (this->at(piece)->isValidMove(
                piece,
                Position(
                    row,
                    col))) {  // no point in checking further if impossible move
          this->testMove(this->at(piece)->getSide(), piece,
                         Position(row, col));  // testMove will further validate
          tempMovesList.push_back(
              Position(row, col));  // add to moveslist if no error
        }
      } catch (const std::runtime_error& e) {
      }  // ignore move if error is thrown
    }
  }
  return tempMovesList;
}

// Return list of locations for pieces of specified side
std::vector<Position> Board::findPieces(const Piece::Side& side) const {
  std::vector<Position> tempList;

  for (size_t row = 0; row < 8; row++) {
    for (size_t col = 0; col < 8; col++) {
      if (this->at(Position(row, col))->getSide() == side) {
        tempList.push_back(Position(row, col));
      }
    }
  }
  return tempList;
}

size_t Board::testMove(const Piece::Side& playerSide, const Position& piece,
                       const Position& dest) const {
  if (!this->hasPiece(piece)) {
    throw std::runtime_error("That square is empty");
  } else if (!this->isSide(piece, playerSide)) {
    throw std::runtime_error("You dont own that piece");
  } else {
    if (this->at(piece)->isValidMove(piece, dest)) {
      // For pawn verify a piece to be attack if its an attack move
      if (this->at(piece)->getName().find('P') != std::string::npos) {
        if (this->hasPiece(dest)) {
          if (dest.column == piece.column) {
            throw std::runtime_error("Pawns cant capture forward");
          }
        } else {
          if (dest.column != piece.column) {  // only possible with diagonal
                                              // move
            throw std::runtime_error("No piece to attack");
          }
        }
      }

      if (this->isSide(
              dest,
              this->at(piece)->getSide())) {  // Invalid move if dest piece is
                                              // on same side as moving piece
        throw std::runtime_error("You can't capture your own piece");
      }
      // Begin checking for pieces in the way
      else if (this->at(piece)->getName().find('N') !=
               std::string::npos) {  // Skip if piece is a knight
        return this->at(dest)->getValue();
      } else if (piece.row == dest.row) {  // Horizontal Move
        for (size_t col = std::max(piece.column, dest.column) - 1;
             col != std::min(piece.column, dest.column); col--) {
          if (this->hasPiece(Position(piece.row, col))) {
            throw std::runtime_error("That Piece cant move there");
          }
        }
      } else if (piece.column == dest.column) {  // Vertical Move
        for (size_t row = std::max(piece.row, dest.row) - 1;
             row != std::min(piece.row, dest.row); row--) {
          if (this->hasPiece(Position(row, piece.column))) {
            throw std::runtime_error("That Piece cant move there");
          }
        }
      } else {  // Diagonal Move
        size_t rowIt = piece.row;
        size_t colIt = piece.column;
        size_t rowDiff = 0;
        size_t colDiff = 0;

        if (dest.row > piece.row) {
          rowDiff = 1;
        } else {
          rowDiff = -1;
        }
        if (dest.column > piece.column) {
          colDiff = 1;
        } else {
          colDiff = -1;
        }
        while (rowIt != dest.row - rowDiff) {  // loop until row before dest row
          rowIt += rowDiff;
          colIt += colDiff;
          if (this->hasPiece(Position(rowIt, colIt))) {
            throw std::runtime_error("That Piece cant move there 1");
          }
        }
      }

    } else {
      throw std::runtime_error("That Piece cant move there 2");
    }
    return this->at(dest)->getValue();
  }
}

// Validate and execute the specified move if possible
// Returns any points gained
size_t Board::makeMove(const Piece::Side& playerSide, const Position& piece,
                       const Position& dest) {
  this->testMove(playerSide, piece, dest);
  return this->movePiece(piece, dest);
}

// Check if there is a piece at the specified position
bool Board::hasPiece(const Position& pos) const {
  return (this->at(pos)->getSide() != Piece::Side::E);
}

bool Board::isSide(const Position& piece, const Piece::Side& side) const {
  return (this->at(piece)->getSide() == side);
}

// Moves the piece within the array, returns the value of any captured pieces
size_t Board::movePiece(const Position& piece, const Position& dest) {
  size_t newPoints =
      this->at(dest)->getValue();  // get value of captured piece (if exists)
  std::unique_ptr<Piece> old =
      std::make_unique<EmptyPiece>();  // store in case of undo
  this->pieces[piece.row][piece.column].swap(
      this->pieces[dest.row][dest.column]);  // swap pieces
  this->pieces[piece.row][piece.column].swap(
      old);  // swap old piece to old pointer (Empty Piece)

  // Make sure side is not in check after move
  if (isInCheck(this->at(dest)->getSide())) {
    // UNDO MOVE
    this->pieces[piece.row][piece.column].swap(old);
    this->pieces[piece.row][piece.column].swap(
        this->pieces[dest.row][dest.column]);
    throw std::runtime_error("Cant move into check");
  }

  // Check for pawn on final row
  if (this->at(dest)->getName().find('P') != std::string::npos) {
    if (dest.row == 7 || dest.row == 0) {
      Piece::Side side = this->at(dest)->getSide();
      this->pieces[dest.row][dest.column].reset();
      this->pieces[dest.row][dest.column] = std::make_unique<Queen>(side);
    }
  }

  if (this->isInCheck(this->at(dest)->getSide())) {
    if (this->isSide(dest, Piece::Side::W)) {
      std::cout << "Black is in check" << std::endl;
    } else {
      std::cout << "White is in check" << std::endl;
    }
  }
  return newPoints;
}

// Return raw pointer to piece at specified location
// Throws runtime_error on out of range error
Piece* Board::at(const Position& piece) const {
  try {
    return this->pieces.at(piece.row).at(piece.column).get();
  } catch (const std::out_of_range& oor) {
    throw std::runtime_error("INVALID POSITION");
  }
}

// Constructur creates the board and respective string
Board::Board() { buildBoard(); }

// Creates the starting board as a 2x2 array of unique pointers
void Board::buildBoard() {
  for (int row = 0; row < 8; row++) {
    std::array<std::unique_ptr<Piece>, 8> tempRow;
    for (int col = 0; col < 8; col++) {
      // First White Row
      if (row == 0) {
        switch (col) {
          case 0:
          case 7:
            tempRow[col] = std::make_unique<Rook>(Piece::Side::W);
            break;
          case 1:
          case 6:
            tempRow[col] = std::make_unique<Knight>(Piece::Side::W);
            break;
          case 2:
          case 5:
            tempRow[col] = std::make_unique<Bishop>(Piece::Side::W);
            break;
          case 3:
            tempRow[col] = std::make_unique<Queen>(Piece::Side::W);
            break;
          case 4:
            tempRow[col] = std::make_unique<King>(Piece::Side::W);
            break;
        }
      } else if (row == 1) {
        tempRow[col] = std::make_unique<Pawn>(Piece::Side::W);
      } else if (row == 6) {
        tempRow[col] = std::make_unique<Pawn>(Piece::Side::B);
      } else if (row == 7) {
        switch (col) {
          case 0:
          case 7:
            tempRow[col] = std::make_unique<Rook>(Piece::Side::B);
            break;
          case 1:
          case 6:
            tempRow[col] = std::make_unique<Knight>(Piece::Side::B);
            break;
          case 2:
          case 5:
            tempRow[col] = std::make_unique<Bishop>(Piece::Side::B);
            break;
          case 3:
            tempRow[col] = std::make_unique<Queen>(Piece::Side::B);
            break;
          case 4:
            tempRow[col] = std::make_unique<King>(Piece::Side::B);
            break;
        }
      } else {
        for (int col = 0; col < 8; col++) {
          tempRow[col] = std::make_unique<EmptyPiece>();
        }
      }
    }
    this->pieces[row] = std::move(tempRow);
  }
}
