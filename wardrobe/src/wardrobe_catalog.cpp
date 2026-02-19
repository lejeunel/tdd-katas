#include "include/wardrobe_catalog.h"
#include <format>
#include <stdexcept>

WardrobeCatalog::WardrobeCatalog() {}

std::vector<Wardrobe> WardrobeCatalog::combinations(int wall_size) {
  if (wall_size < 0)
    throw std::invalid_argument(
        std::format("wall size should be >= 0, got {}", wall_size));

  return std::vector<Wardrobe>();
}
