#include "../src/include/point.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("identical points at zero is zero ", "[two-identical]") {
  REQUIRE(Point(0, 0).manhattan_distance(Point(0, 0)) == 0.);
}

TEST_CASE("points on horizontal axis at distance 1",
          "[distance-one-horizontal]") {
  REQUIRE(Point(0, 0).manhattan_distance(Point(1, 0)) == 1.);
}

TEST_CASE("points on vertical axis at distance 1", "[distance-one-vertical]") {
  REQUIRE(Point(0, 0).manhattan_distance(Point(0, 1)) == 1.);
}

TEST_CASE("points on horizontal axis at distance 1 inverted",
          "[distance-one-horizontal-inverted]") {
  REQUIRE(Point(1, 0).manhattan_distance(Point(0, 0)) == 1.);
}

TEST_CASE("points on vertical axis at distance 1 inverted",
          "[distance-one-vertical-inverted]") {
  REQUIRE(Point(0, 1).manhattan_distance(Point(0, 0)) == 1.);
}

TEST_CASE("point at bottom-right distance 2", "[bottom-right]") {
  REQUIRE(Point(0, 0).manhattan_distance(Point(1, 1)) == 2.);
}

TEST_CASE("point at bottom-right distance 4", "[bottom-right]") {
  REQUIRE(Point(0, 0).manhattan_distance(Point(2, 2)) == 4.);
}
