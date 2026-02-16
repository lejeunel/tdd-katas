#include "../src/include/grid.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Create grid with negative number of rows should fail",
          "[grid-invalid-n-rows]") {
  REQUIRE_THROWS_AS(Grid(-1, 1), std::invalid_argument);
}

TEST_CASE("Create grid with negative number of columns should fail",
          "[grid-invalid-n-cols]") {
  REQUIRE_THROWS_AS(Grid(1, -1), std::invalid_argument);
}

TEST_CASE("activate light in empty grid should fail",
          "[turn-on-single-light]") {
  auto grid = Grid(0, 0);
  REQUIRE_THROWS_AS(grid.activate_light(0, 0), std::out_of_range);
}

TEST_CASE("empty grid should return zero light emission",
          "[empty-grid-zero-emission]") {
  auto grid = Grid(0, 0);
  REQUIRE(grid.light_emission() == 0);
}

TEST_CASE(
    "single-light grid with one litten up light should return 1 light emission",
    "[one-grid-one-emission]") {
  auto grid = Grid(1, 1);
  grid.activate_light(0, 0);
  REQUIRE(grid.light_emission() == 1);
}

TEST_CASE("activate light out of range should fail",
          "[activate-light-out-of-range]") {
  auto grid = Grid(1, 2);
  REQUIRE_THROWS_AS(grid.activate_light(1, 1), std::out_of_range);
}
