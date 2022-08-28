#include "catch.hpp"
#include "pawn.h"
#include "position.h"

TEST_CASE("Test getting name of pawn", "[pawn]") {
  SECTION("White") {
    // Test Getting Name of White Pawn
    Pawn testPiece = Pawn(Piece::Side::W);
    REQUIRE(testPiece.getName() == "PW");
  }

  SECTION("Black") {
    // Test Getting Name of White Pawn
    Pawn testPiece = Pawn(Piece::Side::B);
    REQUIRE(testPiece.getName() == "PB");
  }
}

TEST_CASE("Test valid and invalid moves", "[pawn]") {
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