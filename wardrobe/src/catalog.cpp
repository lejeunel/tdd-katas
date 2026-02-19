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

  extend_combinations(combinations, List(), wall_size);

  return combinations;
}

void Catalog::extend_combinations(Combinations &combinations, List list,
                                  const int &wall_size) {
  for (const auto &w : items) {
    if (wall_size - list.length() >= w.size()) {
      list.add(w);
      if (list.length() == wall_size) {
        combinations.add(list);
        return;
      }
      extend_combinations(combinations, list, wall_size);
    }
  }
}

void Catalog::add(const Item &wr) { items.add(wr); }
