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

TEST_CASE("detect row-region not containing another",
          "[not-containing-regions-row]") {
  auto first_region = Region(0, 0, 0, 3);
  auto not_contained_region = Region(0, 4, 0, 4);
  REQUIRE(first_region.contains(not_contained_region) == false);
}

TEST_CASE("detect row-region containing another", "[containing-regions-row]") {
  auto first_region = Region(0, 0, 0, 3);
  auto contained_region = Region(0, 1, 0, 2);
  REQUIRE(first_region.contains(contained_region));
}

TEST_CASE("detect column-region not containing another",
          "[not-containing-regions-col]") {
  auto first_region = Region(0, 0, 3, 0);
  auto not_contained_region = Region(4, 0, 5, 0);
  REQUIRE(first_region.contains(not_contained_region) == false);
}

TEST_CASE("detect column-region containing another",
          "[containing-regions-col]") {
  auto first_region = Region(0, 0, 3, 0);
  auto contained_region = Region(0, 0, 2, 0);
  REQUIRE(first_region.contains(contained_region));
}

TEST_CASE("non-overlapping rows", "[not-overlapping-regions]") {
  auto first_region = Region(0, 0, 0, 3);
  auto not_overlapping_region = Region(0, 4, 0, 4);
  REQUIRE(first_region.overlaps(not_overlapping_region) == 0);
}

TEST_CASE("overlapping rows (span=1)", "[overlapping-rows-span-1]") {
  auto first_region = Region(0, 0, 0, 3);
  auto overlapping_region = Region(0, 3, 0, 4);
  REQUIRE(first_region.overlaps(overlapping_region) == 1);
}

TEST_CASE("overlapping rows (span=2)", "[overlapping-rows-span-2]") {
  auto first_region = Region(0, 0, 0, 3);
  auto overlapping_region = Region(0, 2, 0, 4);
  REQUIRE(first_region.overlaps(overlapping_region) == 2);
}

TEST_CASE("overlapping columns (span=2)", "[overlapping-cols-span-2]") {
  auto first_region = Region(0, 0, 3, 0);
  auto overlapping_region = Region(2, 0, 4, 0);
  REQUIRE(first_region.overlaps(overlapping_region) == 2);
}

TEST_CASE("new region has zero light emission", "[new-region-zero-light]") {
  auto region = Region(0, 0, 3, 0);
  REQUIRE(region.get_light() == 0);
}

TEST_CASE("setting light units", "[set-light-units]") {
  auto region = Region(0, 0, 3, 0);
  region.set_light(-1);
  REQUIRE(region.get_light() == -1);
}
