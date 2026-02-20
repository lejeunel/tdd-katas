#include "include/catalog.h"
#include "include/item.h"
#include <format>
#include <stdexcept>

Catalog::Catalog() {}

Combinations Catalog::combinations(const int &wall_size) {
  if (wall_size < 0)
    throw std::invalid_argument(
        std::format("wall size should be >= 0, got {}", wall_size));

  if (items.size() == 0)
    return Combinations();

  auto combinations = Combinations();
  for (const auto &i : items)
    extend_list(combinations, List().add(i), wall_size);
  return combinations;
}

void Catalog::extend_list(Combinations &combinations, List list,
                          const int &wall_size) {
  for (const auto &w : items) {
    if ((list.length() == wall_size) && (!combinations.contains(list))) {
      combinations.add(list);
      return;
    }
    if (wall_size - list.length() >= w.size()) {
      list.add(w);
      extend_list(combinations, list, wall_size);
    }
  }
}

void Catalog::add(const Item &wr) { items.add(wr); }
