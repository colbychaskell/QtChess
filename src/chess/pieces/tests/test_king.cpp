#include "catch.hpp"
#include "king.h"
#include "position.h"

TEST_CASE("Test getting name of king", "[king]") {
  SECTION("White") {
    // Test Getting Name of White King
    King testPiece = King(Piece::Side::W);
    REQUIRE(testPiece.getName() == "KW");
  }

  SECTION("Black") {
    // Test Getting Name of White King
    King testPiece = King(Piece::Side::B);
    REQUIRE(testPiece.getName() == "KB");
  }
}

TEST_CASE("Test valid and invalid moves", "[king]") {
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