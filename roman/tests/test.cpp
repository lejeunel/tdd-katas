#include "../src/include/number.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("zero", "[zero]") {
  REQUIRE_THROWS_AS(Number(0).to_roman(), std::invalid_argument);
}

TEST_CASE("one", "[one]") { REQUIRE(Number(1).to_roman() == "I"); }
TEST_CASE("two", "[two]") { REQUIRE(Number(2).to_roman() == "II"); }
TEST_CASE("four", "[four]") { REQUIRE(Number(4).to_roman() == "IV"); }
TEST_CASE("five", "[five]") { REQUIRE(Number(5).to_roman() == "V"); }
TEST_CASE("six", "[six]") { REQUIRE(Number(6).to_roman() == "VI"); }
TEST_CASE("nine", "[nine]") { REQUIRE(Number(9).to_roman() == "IX"); }
TEST_CASE("ten", "[ten]") { REQUIRE(Number(10).to_roman() == "X"); }
TEST_CASE("eleven", "[eleven]") { REQUIRE(Number(11).to_roman() == "XI"); }
TEST_CASE("fifty", "[fifty]") { REQUIRE(Number(50).to_roman() == "L"); }
TEST_CASE("fifty-one", "[fifty-one]") {
  REQUIRE(Number(51).to_roman() == "LI");
}
TEST_CASE("hundred-one", "[hundred-one]") {
  REQUIRE(Number(101).to_roman() == "CI");
}

TEST_CASE("five-hundred-one", "[five-hundred-one]") {
  REQUIRE(Number(501).to_roman() == "DI");
}

TEST_CASE("thousand-one", "[thousand-one]") {
  REQUIRE(Number(1001).to_roman() == "MI");
}
TEST_CASE("twenty", "[twenty]") { REQUIRE(Number(20).to_roman() == "XX"); }
TEST_CASE("twenty-one", "[twenty-one]") {
  REQUIRE(Number(21).to_roman() == "XXI");
}
TEST_CASE("twenty-five", "[twenty-five]") {
  REQUIRE(Number(25).to_roman() == "XXV");
}
