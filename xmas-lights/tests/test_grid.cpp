#include "../src/include/grid.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Create grid with number of rows less than one should fail",
          "[grid-invalid-n-rows]") {
  REQUIRE_THROWS_AS(Grid(-1, 1), std::invalid_argument);
}

TEST_CASE("Create grid with number of columns less than one should fail",
          "[grid-invalid-n-cols]") {
  REQUIRE_THROWS_AS(Grid(1, -1), std::invalid_argument);
}

TEST_CASE("Grid with no activation should return 0", "[grid-not-activated]") {
  auto grid = Grid(1, 1);
  REQUIRE(grid.light_emission() == 0);
}
