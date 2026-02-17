#include "../src/include/grid.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Activate region that spans outside grid should fail",
          "[activate-out-of-range-region]") {
  auto grid = Grid(1, 1);
  REQUIRE_THROWS_AS(grid.activate(Region(0, 0, 0, 1)), std::out_of_range);
}

TEST_CASE("Disactivate region that spans outside grid should fail",
          "[disactivate-out-of-range-region]") {
  auto grid = Grid(1, 1);
  REQUIRE_THROWS_AS(grid.disactivate(Region(0, 0, 0, 1)), std::out_of_range);
}

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
  grid.activate(Region(0, 0, 0, 2));
  grid.activate(Region(0, 1, 0, 2));
  REQUIRE(grid.light_emission() == 3);
}

TEST_CASE("Disactivate grid not activated yet",
          "[disactivate-not-activated-yet]") {
  auto grid = Grid(1, 3);
  grid.disactivate(Region(0, 0, 0, 2));
  REQUIRE(grid.light_emission() == 0);
}

TEST_CASE("Disactivate part not activated yet", "[disactivate-outside]") {
  auto grid = Grid(1, 4);
  grid.activate(Region(0, 0, 0, 2));
  grid.disactivate(Region(0, 3, 0, 3));
  REQUIRE(grid.light_emission() == 3);
}

TEST_CASE("Disactivate from single", "[disactivate-from-one]") {
  auto grid = Grid(1, 3);
  grid.activate(Region(0, 0, 0, 2));
  grid.disactivate(Region(0, 0, 0, 1));
  REQUIRE(grid.light_emission() == 1);
}
