#include "include/wardrobe_catalog.h"
#include "include/wardrobe.h"
#include <format>
#include <stdexcept>

WardrobeCatalog::WardrobeCatalog() {}

WardrobeCombinations WardrobeCatalog::combinations(int wall_size) {
  if (wall_size < 0)
    throw std::invalid_argument(
        std::format("wall size should be >= 0, got {}", wall_size));

  if (wardrobes.size() == 0)
    return WardrobeCombinations();
  if (wardrobes[0].get_size() <= wall_size)
    return WardrobeCombinations{WardrobeList{wardrobes[0]}};
  return WardrobeCombinations();
}

void WardrobeCatalog::add(const Wardrobe &wr) { wardrobes.push_back(wr); }
