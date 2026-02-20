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
  auto current = List();
  find_combinations(combinations, current, wall_size, 0);
  return combinations;
}

void Catalog::find_combinations(Combinations &combinations, List &list,
                                int wall_size, std::size_t start_ix) {
  if (list.length() == wall_size) {
    combinations.add(list);
    return;
  }
  if (list.length() > wall_size)
    return;

  for (std::size_t i = start_ix; i < items.size(); ++i) {
    list.add(items[i]);
    find_combinations(combinations, list, wall_size, i);
    list.pop();
  }
}

void Catalog::add(const Item &wr) { items.add(wr); }
