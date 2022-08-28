#include "catch.hpp"
#include "knight.h"
#include "position.h"

TEST_CASE("Test getting name of knight", "[knight]") {
  SECTION("White") {
    // Test Getting Name of White Knight
    Knight testPiece = Knight(Piece::Side::W);
    REQUIRE(testPiece.getName() == "NW");
  }

  SECTION("Black") {
    // Test Getting Name of White Knight
    Knight testPiece = Knight(Piece::Side::B);
    REQUIRE(testPiece.getName() == "NB");
  }
}

TEST_CASE("Test valid and invalid moves", "[knight]") {
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