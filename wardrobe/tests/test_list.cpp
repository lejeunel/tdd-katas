#include "../src/include/item.h"
#include "../src/include/list.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("two empty lists should be equal", "[equal-empty-lists]") {
  auto first_list = List();
  auto second_list = List();
  REQUIRE(first_list == second_list);
}

TEST_CASE("two lists of different sizes should be non-equal",
          "[non-equal-lists-different-sizes]") {
  auto first_list = List();
  auto second_list = List();
  second_list.add(Item("a-item", 1));
  REQUIRE(first_list != second_list);
}

TEST_CASE("two lists of same size but different content should be non-equal",
          "[non-equal-lists-same-size-different-content]") {
  auto first_list = List();
  auto second_list = List();
  first_list.add(Item("an-item", 1));
  second_list.add(Item("another-item", 1));
  REQUIRE(first_list != second_list);
}

TEST_CASE("two lists with different orderings should be equal",
          "[equal-shuffled-lists]") {
  auto first_list = List();
  auto second_list = List();
  auto first_item = Item("first-item", 1);
  auto second_item = Item("second-item", 1);
  first_list.add(first_item);
  first_list.add(second_item);
  second_list.add(second_item);
  second_list.add(first_item);
  REQUIRE(first_list == second_list);
}
