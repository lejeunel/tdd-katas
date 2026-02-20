#include "../src/include/catalog.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("wall size must be greater than 0", "[wall-size-gt-zero]") {
  auto catalog = Catalog();
  REQUIRE_THROWS_AS(catalog.propose(-1), std::invalid_argument);
}

TEST_CASE("return no proposal for wall size = 0", "[wall-size-eq-zero]") {
  auto catalog = Catalog();
  REQUIRE(catalog.propose(0).size() == 0);
}

TEST_CASE("return one proposal for catalog with matching wall size",
          "[single-elem-matching-wall]") {
  auto catalog = Catalog();
  catalog.add(Item("an-item", 25));
  catalog.add(Item("another-item", 15));
  REQUIRE(catalog.propose(15).size() == 1);
}

TEST_CASE("return no proposal for catalog with single element smaller than "
          "wall size",
          "[single-elem-wall-bigger]") {
  auto catalog = Catalog();
  catalog.add(Item("a-item", 10));
  REQUIRE(catalog.propose(15).size() == 0);
}

TEST_CASE("return no proposal for catalog with all elements greater than "
          "wall size",
          "[all-are-bigger]") {
  auto catalog = Catalog();
  catalog.add(Item("a-item", 16));
  catalog.add(Item("another-item", 20));
  REQUIRE(catalog.propose(10).size() == 0);
}

TEST_CASE("single element catalog return one proposal with two-duplicate",
          "[single-elem-two-duplicate]") {
  auto catalog = Catalog();
  catalog.add(Item("a-item", 10));
  auto proposals = catalog.propose(20);
  REQUIRE(proposals.size() == 1);
  REQUIRE(proposals[0].size() == 2);
}

TEST_CASE("single element catalog return one proposal with three-duplicate",
          "[single-elem-three-duplicate]") {
  auto catalog = Catalog();
  catalog.add(Item("a-item", 10));
  auto proposals = catalog.propose(30);
  REQUIRE(proposals.size() == 1);
  REQUIRE(proposals[0].size() == 3);
}

TEST_CASE("catalog with two items with total length matching wall size",
          "[two-item-catalog-several-match]") {
  auto catalog = Catalog();
  catalog.add(Item("first-item", 50));
  catalog.add(Item("second-item", 100));
  auto proposals = catalog.propose(250);
  REQUIRE(proposals.size() == 3);
}

TEST_CASE("sorting two proposals by total price", "[sorting-proposals]") {
  auto first_list = List()
                        .add(Item("first-item-first-list", 1, 5.0))
                        .add(Item("second-item-first-list", 1, 10.0));

  auto second_list = List()
                         .add(Item("first-item-second-list", 1, 1.0))
                         .add(Item("second-item-second-list", 1, 2.0));

  auto proposals = Proposals().add(first_list).add(second_list).sort_by_price();
  REQUIRE(proposals[0].price() == 3.0);
  REQUIRE(proposals[1].price() == 15.0);
}
