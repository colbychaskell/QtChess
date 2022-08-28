#include "catch.hpp"
#include "position.h"
#include "rook.h"

TEST_CASE("Test getting name of rook", "[rook]") {
  SECTION("White") {
    // Test Getting Name of White Rook
    Rook testPiece = Rook(Piece::Side::W);
    REQUIRE(testPiece.getName() == "RW");
  }

  SECTION("Black") {
    // Test Getting Name of White Rook
    Rook testPiece = Rook(Piece::Side::B);
    REQUIRE(testPiece.getName() == "RB");
  }
}

TEST_CASE("Test valid and invalid moves", "[rook]") {
  SECTION("Valid Moves") {
    Rook testPiece = Rook(Piece::Side::W);

    // Right
    Position positionA = Position(0, 0);
    Position positionB = Position(0, 5);

    REQUIRE(testPiece.isValidMove(positionA, positionB));
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