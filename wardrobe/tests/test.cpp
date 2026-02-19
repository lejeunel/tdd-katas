#include "../src/include/wardrobe_catalog.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("wall size must be greater than 0", "[wall-size-gt-zero]") {
  auto catalog = WardrobeCatalog();
  REQUIRE_THROWS_AS(catalog.combinations(-1), std::invalid_argument);
}

TEST_CASE("return no combinations for wall size = 0", "[wall-size-eq-zero]") {
  auto catalog = WardrobeCatalog();
  REQUIRE(catalog.combinations(0).size() == 0);
}

TEST_CASE("return single element for catalog with matching wall size",
          "[single-elem-matching-wall]") {
  auto catalog = WardrobeCatalog();
  catalog.add(Wardrobe(15));
  REQUIRE(catalog.combinations(15).size() == 1);
}

TEST_CASE("return single element for catalog with single element smaller than "
          "wall size",
          "[single-elem-wall-bigger]") {
  auto catalog = WardrobeCatalog();
  catalog.add(Wardrobe(10));
  REQUIRE(catalog.combinations(15).size() == 1);
}
