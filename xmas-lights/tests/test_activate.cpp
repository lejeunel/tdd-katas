#include "../src/include/grid.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Activate region that spans outside grid should fail",
          "[activate-out-of-range-region]") {
  auto grid = Grid(1, 1);
  REQUIRE_THROWS_AS(grid.activate(Region(0, 0, 0, 1)), std::out_of_range);
}

TEST_CASE("Activate region filling the grid of size 2 should return 2",
          "[activate-one-two-region]") {
  auto grid = Grid(1, 2);
  grid.activate(Region(0, 0, 0, 1));
  REQUIRE(grid.luminous_power() == 2);
}

TEST_CASE("Activate two disjoint regions of size 1 should return 2",
          "[activate-two-disjoint]") {
  auto grid = Grid(1, 2);
  grid.activate(Region(0, 0, 0, 0));
  grid.activate(Region(0, 1, 0, 1));
  REQUIRE(grid.luminous_power() == 2);
}

TEST_CASE("Activate two identical regions add contributions",
          "[activate-two-identical]") {
  auto grid = Grid(1, 2);
  grid.activate(Region(0, 1, 0, 1));
  grid.activate(Region(0, 1, 0, 1));
  REQUIRE(grid.luminous_power() == 2);
}

TEST_CASE("Activate the same region later on should add",
          "[activate-identical-later]") {
  auto grid = Grid(1, 2);
  grid.activate(Region(0, 1, 0, 1));
  grid.activate(Region(0, 0, 0, 0));
  grid.activate(Region(0, 1, 0, 1));
  REQUIRE(grid.luminous_power() == 3);
}

TEST_CASE("Activate a region contained in another should have no effect",
          "[activate-region-contained-in-another]") {
  auto grid = Grid(1, 3);
  grid.activate(Region(0, 0, 0, 2));
  grid.activate(Region(0, 1, 0, 2));
  REQUIRE(grid.luminous_power() == 5);
}

TEST_CASE("Activate partly overlapping regions",
          "[activate-partly-overlapping-regions]") {
  auto grid = Grid(1, 5);
  grid.activate(Region(0, 0, 0, 2));
  grid.activate(Region(0, 1, 0, 3));
  REQUIRE(grid.luminous_power() == 6);
}
