#include "../src/include/grid.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Toggle region that spans outside grid should fail",
          "[toggle-out-of-range-region]") {
  auto grid = Grid(1, 1);
  REQUIRE_THROWS_AS(grid.toggle(Region(0, 0, 0, 1)), std::out_of_range);
}

TEST_CASE("Toggling fresh grid should set to 2", "[toggling-fresh]") {
  auto grid = Grid(1, 1);
  grid.toggle(Region(0, 0, 0, 0));
  REQUIRE(grid.luminous_power() == 2);
}

TEST_CASE("Toggling activated light should increase by 2",
          "[toggling-activated]") {
  auto grid = Grid(1, 1);
  grid.activate(Region(0, 0, 0, 0));
  grid.toggle(Region(0, 0, 0, 0));
  REQUIRE(grid.luminous_power() == 3);
}

TEST_CASE("Toggling activated then disactivated light should be 2",
          "[toggling-flipped]") {
  auto grid = Grid(1, 1);
  grid.activate(Region(0, 0, 0, 0));
  grid.disactivate(Region(0, 0, 0, 0));
  grid.toggle(Region(0, 0, 0, 0));
  REQUIRE(grid.luminous_power() == 2);
}

TEST_CASE("Toggling overlapping (span=1)", "[toggling-overlap-span-1]") {
  auto grid = Grid(1, 3);
  grid.activate(Region(0, 0, 0, 0));
  grid.toggle(Region(0, 0, 0, 2));
  REQUIRE(grid.luminous_power() == 7);
}

TEST_CASE("Toggling overlapping (span=2)", "[toggling-overlap-span-2]") {
  auto grid = Grid(1, 4);
  grid.activate(Region(0, 0, 0, 1));
  grid.toggle(Region(0, 0, 0, 3));
  REQUIRE(grid.luminous_power() == 10);
}

TEST_CASE("Toggling two overlapping (span=1)", "[toggle-two-overlap-span-1]") {
  auto grid = Grid(2, 3);
  grid.activate(Region(0, 0, 0, 1));
  grid.activate(Region(0, 1, 1, 1));
  grid.toggle(Region(0, 1, 0, 2));
  REQUIRE(grid.luminous_power() == 8);
}
