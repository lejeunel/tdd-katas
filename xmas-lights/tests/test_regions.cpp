#include "../src/include/region.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Create region with negative row span should fail",
          "[region-invalid-row-span]") {
  REQUIRE_THROWS_AS(Region(3, 0, 2, 0), std::invalid_argument);
}

TEST_CASE("Create region with negative col span should fail",
          "[region-invalid-col-span]") {
  REQUIRE_THROWS_AS(Region(0, 3, 0, 2), std::invalid_argument);
}

TEST_CASE("Size of region of single element", "[size-single-element-region]") {
  auto region = Region(0, 0, 0, 0);
  REQUIRE(region.size() == 1);
}

TEST_CASE("Size of region of two columns", "[size-two-columns-region]") {
  auto region = Region(0, 0, 0, 1);
  REQUIRE(region.size() == 2);
}

TEST_CASE("Size of region of two rows", "[size-two-rows-region]") {
  auto region = Region(0, 0, 1, 0);
  REQUIRE(region.size() == 2);
}

TEST_CASE("Comparing two identical regions", "[compare-identical-regions]") {
  auto first_region = Region(0, 0, 0, 0);
  auto second_region = Region(0, 0, 0, 0);
  REQUIRE(first_region == second_region);
}

TEST_CASE("Comparing two different regions", "[compare-identical-regions]") {
  auto first_region = Region(0, 0, 0, 0);
  auto second_region = Region(0, 0, 0, 1);
  REQUIRE(first_region != second_region);
}

TEST_CASE("Overlapping region should be contained", "[overlapping-regions]") {
  auto first_region = Region(0, 0, 0, 3);
  auto overlapping_region = Region(0, 1, 0, 2);
  REQUIRE(first_region.contains(overlapping_region));
}
