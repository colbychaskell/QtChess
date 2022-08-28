#include "catch.hpp"
#include "position.h"
#include "queen.h"

TEST_CASE("Test getting name of queen", "[queen]") {
  SECTION("White") {
    // Test Getting Name of White Queen
    Queen testPiece = Queen(Piece::Side::W);
    REQUIRE(testPiece.getName() == "QW");
  }

  SECTION("Black") {
    // Test Getting Name of White Queen
    Queen testPiece = Queen(Piece::Side::B);
    REQUIRE(testPiece.getName() == "QB");
  }
}

TEST_CASE("Test valid and invalid moves", "[queen]") {
  SECTION("Valid Moves") {
    Queen testPiece = Queen(Piece::Side::W);

    // Right
    Position positionA = Position(0, 0);
    Position positionB = Position(0, 5);

    REQUIRE(testPiece.isValidMove(positionA, positionB));
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