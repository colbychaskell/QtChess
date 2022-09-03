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
