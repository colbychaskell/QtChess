#include "bishop.h"
#include "catch.hpp"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "position.h"
#include "queen.h"
#include "rook.h"

TEST_CASE("Bishop", "[piece]") {
  SECTION("Get Name as White") {
    // Test Getting Name of White Bishop
    Bishop testPiece = Bishop(Piece::Side::W);
    REQUIRE(testPiece.getName() == "BW");
  }

  SECTION("Get Name as Black") {
    // Test Getting Name of White Bishop
    Bishop testPiece = Bishop(Piece::Side::B);
    REQUIRE(testPiece.getName() == "BB");
  }

  SECTION("Diagonal Moves: Down and Left") {
    Bishop testPiece = Bishop(Piece::Side::W);

    Position positionA = Position(7, 7);
    Position positionB;

    for (size_t i = 0; i < 7; i++) {
      positionB = Position(i, i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Diagonal Moves: - Up and Right") {
    Bishop testPiece = Bishop(Piece::Side::W);

    Position positionA = Position(0, 0);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(i, i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Diagonal Moves: - Up and Left") {
    Bishop testPiece = Bishop(Piece::Side::W);

    Position positionA = Position(0, 7);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(0 + i, 7 - i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Diagonal Moves: - Down and Right") {
    Bishop testPiece = Bishop(Piece::Side::W);

    Position positionA = Position(7, 0);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(7 - i, 0 + i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Invalid Moves") {
    Bishop testPiece = Bishop(Piece::Side::W);

    // Up and Right
    Position positionA = Position(0, 0);
    Position positionB = Position(1, 3);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Up and Left
    positionA = Position(5, 5);
    positionB = Position(7, 0);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Down and Left
    positionA = Position(6, 3);
    positionB = Position(3, 7);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Down and Right
    positionA = Position(4, 2);
    positionB = Position(2, 7);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));
  }
}

TEST_CASE("King", "[piece]") {
  SECTION("Get Name as White") {
    // Test Getting Name of White King
    King testPiece = King(Piece::Side::W);
    REQUIRE(testPiece.getName() == "KW");
  }

  SECTION("Get Name as Black") {
    // Test Getting Name of White King
    King testPiece = King(Piece::Side::B);
    REQUIRE(testPiece.getName() == "KB");
  }

  SECTION("Valid Moves") {
    King testPiece = King(Piece::Side::W);

    // Up and Right
    Position positionA = Position(0, 0);
    Position positionB = Position(1, 1);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Up and Left
    positionA = Position(5, 5);
    positionB = Position(6, 4);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Down and Left
    positionA = Position(5, 5);
    positionB = Position(4, 4);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Down and Right
    positionA = Position(4, 2);
    positionB = Position(3, 3);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Right
    positionA = Position(4, 2);
    positionB = Position(4, 3);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Left
    positionA = Position(4, 2);
    positionB = Position(4, 1);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Up
    positionA = Position(4, 3);
    positionB = Position(5, 3);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Down
    positionA = Position(4, 2);
    positionB = Position(3, 1);

    REQUIRE(testPiece.isValidMove(positionA, positionB));
  }

  SECTION("Invalid Moves") {
    King testPiece = King(Piece::Side::W);

    // Up and Right
    Position positionA = Position(0, 0);
    Position positionB = Position(1, 3);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Up and Left
    positionA = Position(5, 5);
    positionB = Position(7, 0);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Down and Left
    positionA = Position(6, 3);
    positionB = Position(3, 7);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Down and Right
    positionA = Position(4, 2);
    positionB = Position(2, 7);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));
  }
}

TEST_CASE("Knight", "[piece]") {
  SECTION("Get Name as White") {
    // Test Getting Name of White Knight
    Knight testPiece = Knight(Piece::Side::W);
    REQUIRE(testPiece.getName() == "NW");
  }

  SECTION("Get Name as Black") {
    // Test Getting Name of White Knight
    Knight testPiece = Knight(Piece::Side::B);
    REQUIRE(testPiece.getName() == "NB");
  }
  SECTION("Valid Moves") {
    // Up 2, right 1
    Knight testPiece = Knight(Piece::Side::W);

    Position positionA = Position(0, 0);
    Position positionB = Position(2, 1);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // up 2, left 1
    positionA = Position(0, 7);
    positionB = Position(2, 6);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // down 2, left 1
    positionA = Position(7, 7);
    positionB = Position(5, 6);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // down 2, right 1
    positionA = Position(7, 0);
    positionB = Position(5, 1);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // left 2, up 1
    positionA = Position(5, 5);
    positionB = Position(6, 3);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // left 2, down 1
    positionA = Position(5, 5);
    positionB = Position(4, 3);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // right 2, down 1
    positionA = Position(6, 5);
    positionB = Position(5, 7);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // right 2, up 1
    positionA = Position(5, 5);
    positionB = Position(6, 7);

    REQUIRE(testPiece.isValidMove(positionA, positionB));
  }

  SECTION("Invalid Moves") {
    // Test that invalid moves are not allowed
    Knight testPiece = Knight(Piece::Side::W);

    // Diagonal
    Position positionA = Position(5, 5);
    Position positionB = Position(6, 6);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Vertical
    positionA = Position(5, 5);
    positionB = Position(6, 5);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    positionA = Position(5, 5);
    positionB = Position(7, 5);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    positionA = Position(7, 5);
    positionB = Position(4, 5);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Horizontal
    positionA = Position(5, 5);
    positionB = Position(5, 6);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    positionA = Position(5, 5);
    positionB = Position(5, 7);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    positionA = Position(3, 2);
    positionB = Position(3, 5);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    positionA = Position(7, 7);
    positionB = Position(7, 4);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));
  }
}

TEST_CASE("Pawn", "[piece]") {
  SECTION("Get Name as White") {
    // Test Getting Name of White Pawn
    Pawn testPiece = Pawn(Piece::Side::W);
    REQUIRE(testPiece.getName() == "PW");
  }

  SECTION("Get Name as Black") {
    // Test Getting Name of White Pawn
    Pawn testPiece = Pawn(Piece::Side::B);
    REQUIRE(testPiece.getName() == "PB");
  }
  SECTION("Valid Moves") {
    Pawn testPiece = Pawn(Piece::Side::W);

    // Up 1
    Position positionA = Position(0, 0);
    Position positionB = Position(1, 0);

    REQUIRE(testPiece.isValidMove(positionA, positionB));
  }

  SECTION("Invalid Moves") {
    // Test that invalid moves are not allowed
    Pawn testPiece = Pawn(Piece::Side::W);

    // l-shape
    Position positionA = Position(5, 5);
    Position positionB = Position(6, 9);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));

    // Right 1
    positionA = Position(0, 0);
    positionB = Position(0, 1);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));
  }
}

TEST_CASE("Queen", "[piece]") {
  SECTION("Get Name as White") {
    // Test Getting Name of White Queen
    Queen testPiece = Queen(Piece::Side::W);
    REQUIRE(testPiece.getName() == "QW");
  }

  SECTION("Get Name as Black") {
    // Test Getting Name of White Queen
    Queen testPiece = Queen(Piece::Side::B);
    REQUIRE(testPiece.getName() == "QB");
  }
  SECTION("Horizontal Moves Right") {
    Queen testPiece = Queen(Piece::Side::W);

    Position positionA = Position(0, 0);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(0, i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }
  SECTION("Horizontal Moves Left") {
    Queen testPiece = Queen(Piece::Side::W);

    Position positionA = Position(0, 7);
    Position positionB;

    for (size_t i = 0; i < 7; i++) {
      positionB = Position(0, i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }
  SECTION("Vertical Moves Up") {
    Queen testPiece = Queen(Piece::Side::W);

    // Moving Up
    Position positionA = Position(0, 0);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(i, 0);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }
  SECTION("Vertical Moves Down") {
    Queen testPiece = Queen(Piece::Side::W);

    Position positionA = Position(7, 7);
    Position positionB;
    // Right
    for (size_t i = 0; i < 7; i++) {
      positionB = Position(i, 0);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }
  SECTION("Diagonal Moves: Down and Left") {
    Queen testPiece = Queen(Piece::Side::W);

    Position positionA = Position(7, 7);
    Position positionB;

    for (size_t i = 0; i < 7; i++) {
      positionB = Position(i, i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Diagonal Moves: - Up and Right") {
    Queen testPiece = Queen(Piece::Side::W);

    Position positionA = Position(0, 0);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(i, i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Diagonal Moves: - Up and Left") {
    Queen testPiece = Queen(Piece::Side::W);

    Position positionA = Position(0, 7);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(0 + i, 7 - i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Diagonal Moves: - Down and Right") {
    Queen testPiece = Queen(Piece::Side::W);

    Position positionA = Position(7, 0);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(7 - i, 0 + i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Invalid Moves") {
    // Test that invalid moves are not allowed
    Queen testPiece = Queen(Piece::Side::W);

    // l-shape
    Position positionA = Position(5, 5);
    Position positionB = Position(6, 9);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));
  }
}

TEST_CASE("Rook", "[piece]") {
  SECTION("Get Name as White") {
    // Test Getting Name of White Rook
    Rook testPiece = Rook(Piece::Side::W);
    REQUIRE(testPiece.getName() == "RW");
  }

  SECTION("Get Name as Black") {
    // Test Getting Name of White Rook
    Rook testPiece = Rook(Piece::Side::B);
    REQUIRE(testPiece.getName() == "RB");
  }
  SECTION("Horizontal Moves Right") {
    Rook testPiece = Rook(Piece::Side::W);

    Position positionA = Position(0, 0);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(0, i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }
  SECTION("Horizontal Moves Left") {
    Rook testPiece = Rook(Piece::Side::W);

    Position positionA = Position(0, 7);
    Position positionB;

    for (size_t i = 0; i < 7; i++) {
      positionB = Position(0, i);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }
  SECTION("Vertical Moves Up") {
    Rook testPiece = Rook(Piece::Side::W);

    // Moving Up
    Position positionA = Position(0, 0);
    Position positionB;

    for (size_t i = 1; i < 8; i++) {
      positionB = Position(i, 0);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }
  SECTION("Vertical Moves Down") {
    Rook testPiece = Rook(Piece::Side::W);

    Position positionA = Position(7, 7);
    Position positionB;
    // Right
    for (size_t i = 0; i < 7; i++) {
      positionB = Position(i, 0);
      REQUIRE(testPiece.isValidMove(positionA, positionB));
    }
  }

  SECTION("Invalid Moves") {
    // Test that invalid moves are not allowed
    Rook testPiece = Rook(Piece::Side::W);

    // Diagonal
    Position positionA = Position(5, 5);
    Position positionB = Position(6, 6);

    REQUIRE(!testPiece.isValidMove(positionA, positionB));
  }
}