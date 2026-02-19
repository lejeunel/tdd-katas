#include "../src/include/catalog.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("wall size must be greater than 0", "[wall-size-gt-zero]") {
  auto catalog = Catalog();
  REQUIRE_THROWS_AS(catalog.combinations(-1), std::invalid_argument);
}

TEST_CASE("return no combination for wall size = 0", "[wall-size-eq-zero]") {
  auto catalog = Catalog();
  REQUIRE(catalog.combinations(0).size() == 0);
}

TEST_CASE("return one combination for catalog with matching wall size",
          "[single-elem-matching-wall]") {
  auto catalog = Catalog();
  catalog.add(Item("an-item", 25));
  catalog.add(Item("another-item", 15));
  REQUIRE(catalog.combinations(15).size() == 1);
}

TEST_CASE("return no combination for catalog with single element smaller than "
          "wall size",
          "[single-elem-wall-bigger]") {
  auto catalog = Catalog();
  catalog.add(Item("a-item", 10));
  REQUIRE(catalog.combinations(15).size() == 0);
}

TEST_CASE("return no combination for catalog with all elements greater than "
          "wall size",
          "[all-are-bigger]") {
  auto catalog = Catalog();
  catalog.add(Item("a-item", 16));
  catalog.add(Item("another-item", 20));
  REQUIRE(catalog.combinations(10).size() == 0);
}

TEST_CASE("single element catalog return one combination with two-duplicate",
          "[single-elem-two-duplicate]") {
  auto catalog = Catalog();
  catalog.add(Item("a-item", 10));
  auto combinations = catalog.combinations(20);
  REQUIRE(combinations.size() == 1);
  REQUIRE(combinations[0].size() == 2);
}

TEST_CASE("single element catalog return one combination with three-duplicate",
          "[single-elem-three-duplicate]") {
  auto catalog = Catalog();
  catalog.add(Item("a-item", 10));
  auto combinations = catalog.combinations(30);
  REQUIRE(combinations.size() == 1);
  REQUIRE(combinations[0].size() == 3);
}

TEST_CASE("two empty lists should be equal", "[equal-empty-lists]") {
  auto first_list = List();
  auto second_list = List();
  REQUIRE(first_list == second_list);
}

TEST_CASE("two non-equal lists should be non-equal",
          "[non-equal-empty-lists]") {
  auto first_list = List();
  auto second_list = List();
  second_list.add(Item("a-item", 1));
  REQUIRE(first_list != second_list);
}

TEST_CASE("catalog with two items with total length matching wall size",
          "[two-item-catalog-matching]") {
  auto catalog = Catalog();
  catalog.add(Item("first-item", 3));
  catalog.add(Item("second-item", 5));
  auto combinations = catalog.combinations(8);
  REQUIRE(combinations.size() == 1);
  REQUIRE(combinations[0].size() == 2);
  REQUIRE(combinations[0][0].name() != combinations[0][1].name());
}
