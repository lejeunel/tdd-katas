#include "../src/include/grid.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Disactivate region that spans outside grid should fail",
          "[disactivate-out-of-range-region]") {
  auto grid = Grid(1, 1);
  REQUIRE_THROWS_AS(grid.disactivate(Region(0, 0, 0, 1)), std::out_of_range);
}

TEST_CASE("Disactivate grid not activated yet",
          "[disactivate-not-activated-yet]") {
  auto grid = Grid(1, 3);
  grid.disactivate(Region(0, 0, 0, 2));
  REQUIRE(grid.luminous_power() == 0);
}

TEST_CASE("Disactivate part not activated yet has no effect",
          "[disactivate-outside-no-effect]") {
  auto grid = Grid(1, 4);
  grid.activate(Region(0, 0, 0, 2));
  grid.disactivate(Region(0, 3, 0, 3));
  REQUIRE(grid.luminous_power() == 3);
}

TEST_CASE("Disactivate one region contained in another",
          "[disactivate-contained-region]") {
  auto grid = Grid(1, 3);
  grid.activate(Region(0, 0, 0, 2));
  grid.disactivate(Region(0, 0, 0, 1));
  REQUIRE(grid.luminous_power() == 1);
}

TEST_CASE("Disactivate overlapping row (span 1)",
          "[disactivate-overlapping-row-span-1]") {
  auto grid = Grid(1, 5);
  grid.activate(Region(0, 0, 0, 2));
  grid.disactivate(Region(0, 2, 0, 3));
  REQUIRE(grid.luminous_power() == 2);
}

TEST_CASE("Disactivate overlapping columns (span 1)",
          "[disactivate-overlapping-col-span-1]") {
  auto grid = Grid(5, 1);
  grid.activate(Region(0, 0, 2, 0));
  grid.disactivate(Region(2, 0, 3, 0));
  REQUIRE(grid.luminous_power() == 2);
}

TEST_CASE("Disactivate overlapping row (span 2)",
          "[disactivate-overlapping-row-span-2]") {
  auto grid = Grid(1, 5);
  grid.activate(Region(0, 0, 0, 2));
  grid.disactivate(Region(0, 1, 0, 3));
  REQUIRE(grid.luminous_power() == 1);
}

TEST_CASE("Disactivate overlapping columns (span 2)",
          "[disactivate-overlapping-col-span-2]") {
  auto grid = Grid(5, 1);
  grid.activate(Region(0, 0, 3, 0));
  grid.disactivate(Region(2, 0, 4, 0));
  REQUIRE(grid.luminous_power() == 2);
}

TEST_CASE("Disactivate row that overlaps two rows",
          "[disactivate-two-overlapping-row-span-2]") {
  auto grid = Grid(1, 5);
  grid.activate(Region(0, 0, 0, 1));
  grid.activate(Region(0, 1, 0, 4));
  grid.disactivate(Region(0, 1, 0, 2));
  REQUIRE(grid.luminous_power() == 4);
}

TEST_CASE("Disactivate col that overlaps two cols",
          "[disactivate-two-overlapping-col-span-2]") {
  auto grid = Grid(5, 1);
  grid.activate(Region(0, 0, 1, 0));
  grid.activate(Region(1, 0, 4, 0));
  grid.disactivate(Region(1, 0, 2, 0));
  REQUIRE(grid.luminous_power() == 4);
}

TEST_CASE("Disactivate same light twice", "[disactivate-same-region-twice]") {
  auto grid = Grid(1, 1);
  grid.activate(Region(0, 0, 0, 0));
  grid.disactivate(Region(0, 0, 0, 0));
  grid.disactivate(Region(0, 0, 0, 0));
  REQUIRE(grid.luminous_power() == 0);
}

TEST_CASE("Disactivate same overlapping twice",
          "[disactivate-same-overlap-twice]") {
  auto grid = Grid(1, 4);
  grid.activate(Region(0, 0, 0, 2));
  grid.disactivate(Region(0, 1, 0, 3));
  grid.disactivate(Region(0, 1, 0, 3));
  REQUIRE(grid.luminous_power() == 1);
}

TEST_CASE("Disactivate two overlapping", "[disactivate-two-overlap]") {
  auto grid = Grid(2, 2);
  grid.activate(Region(0, 0, 0, 1));
  grid.activate(Region(0, 1, 1, 1));
  grid.disactivate(Region(0, 1, 0, 1));
  REQUIRE(grid.luminous_power() == 3);
}
