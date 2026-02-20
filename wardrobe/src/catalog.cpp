#include "include/catalog.h"
#include "include/item.h"
#include <format>
#include <stdexcept>

Catalog::Catalog() {}

Proposals Catalog::propose(const int &wall_size) {
  if (wall_size < 0)
    throw std::invalid_argument(
        std::format("wall size should be >= 0, got {}", wall_size));

  if (items.size() == 0)
    return Proposals();

  auto proposals = Proposals();
  auto current = List();
  find_proposals(proposals, current, wall_size, 0);
  return proposals;
}

void Catalog::find_proposals(Proposals &proposals, List &list, int wall_size,
                             std::size_t start_ix) {
  if (list.length() == wall_size) {
    proposals.add(list);
    return;
  }
  if (list.length() > wall_size)
    return;

  for (std::size_t i = start_ix; i < items.size(); ++i) {
    list.add(items[i]);
    find_proposals(proposals, list, wall_size, i);
    list.pop();
  }
}

void Catalog::add(const Item &wr) { items.add(wr); }
