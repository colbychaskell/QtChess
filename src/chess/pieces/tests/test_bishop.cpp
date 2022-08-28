#include "bishop.h"
#include "catch.hpp"
#include "position.h"

TEST_CASE("Test getting name of bishop", "[bishop]") {
  SECTION("White") {
    // Test Getting Name of White Bishop
    Bishop testPiece = Bishop(Piece::Side::W);
    REQUIRE(testPiece.getName() == "BW");
  }

  SECTION("Black") {
    // Test Getting Name of White Bishop
    Bishop testPiece = Bishop(Piece::Side::B);
    REQUIRE(testPiece.getName() == "BB");
  }
}

TEST_CASE("Test valid and invalid moves", "[bishop]") {
  SECTION("Valid Moves") {
    Bishop testPiece = Bishop(Piece::Side::W);

    // Up and Right
    Position positionA = Position(0, 0);
    Position positionB = Position(1, 1);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Up and Left
    positionA = Position(5, 5);
    positionB = Position(7, 3);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Down and Left
    positionA = Position(6, 3);
    positionB = Position(3, 0);

    REQUIRE(testPiece.isValidMove(positionA, positionB));

    // Down and Right
    positionA = Position(4, 2);
    positionB = Position(2, 4);

    REQUIRE(testPiece.isValidMove(positionA, positionB));
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