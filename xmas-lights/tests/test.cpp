#include "../src/include/grid.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Activate region filling the grid of size 1 should return 1",
          "[activate-one-one-region]") {
  auto grid = Grid(1, 1);
  grid.activate(Region(0, 0, 0, 0));
  REQUIRE(grid.light_emission() == 1);
}

TEST_CASE("Activate region filling the grid of size 2 should return 2",
          "[activate-one-two-region]") {
  auto grid = Grid(1, 2);
  grid.activate(Region(0, 0, 0, 1));
  REQUIRE(grid.light_emission() == 2);
}

TEST_CASE("Activate two disjoint regions of size 1 should return 2",
          "[activate-two-disjoint]") {
  auto grid = Grid(1, 2);
  grid.activate(Region(0, 0, 0, 0));
  grid.activate(Region(0, 1, 0, 1));
  REQUIRE(grid.light_emission() == 2);
}

TEST_CASE("Activate two redundant regions should have no effect",
          "[activate-two-identical]") {
  auto grid = Grid(1, 2);
  grid.activate(Region(0, 1, 0, 1));
  grid.activate(Region(0, 1, 0, 1));
  REQUIRE(grid.light_emission() == 1);
}

TEST_CASE("Activate a redundant region later on should have no effect",
          "[activate-identical-later]") {
  auto grid = Grid(1, 2);
  grid.activate(Region(0, 1, 0, 1));
  grid.activate(Region(0, 0, 0, 0));
  grid.activate(Region(0, 1, 0, 1));
  REQUIRE(grid.light_emission() == 2);
}

TEST_CASE("Activate an overlapping region should have no effect",
          "[activate-overlapping]") {
  auto grid = Grid(1, 3);
  grid.activate(Region(0, 0, 0, 3));
  grid.activate(Region(0, 1, 0, 2));
  REQUIRE(grid.light_emission() == 4);
}
