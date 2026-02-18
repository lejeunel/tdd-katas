#include "include/grid.h"
#include <algorithm>
#include <format>
#include <stdexcept>

Grid::Grid(const int &a_n_rows, const int &a_n_cols) {
  if (a_n_rows < 1) {
    throw std::invalid_argument("Number of rows should be at least 1");
  }
  if (a_n_cols < 1) {
    throw std::invalid_argument("Number of columns should be at least 1");
  }
  n_rows = a_n_rows;
  n_cols = a_n_cols;
}
int Grid::luminous_power() {
  auto total_light = 0;
  for (const auto &r : regions)
    total_light += r.get_luminous_power();
  return total_light;
}

void Grid::activate(Region r) {
  check_is_in_range(r);
  r.set_luminous_power(r.size());
  add_region(r);
}

void Grid::disactivate(Region r) {
  check_is_in_range(r);

  auto budget = r.size();
  for (const auto &ovr : find_overlapping_regions(r)) {
    auto delta =
        std::min(budget, std::min(ovr->get_luminous_power(), ovr->overlaps(r)));
    r.set_luminous_power(r.get_luminous_power() - delta);
    budget -= delta;
  }

  add_region(r);
}

void Grid::toggle(Region r) {
  check_is_in_range(r);
  auto luminous_power = 0;
  for (const auto &ovr : find_overlapping_regions(r)) {
    luminous_power += ovr->get_luminous_power();
  }

  r.set_luminous_power(-2 * std::min(r.size(), luminous_power) + r.size());
  add_region(r);
}

std::vector<const Region *>
Grid::find_overlapping_regions(const Region &region) {
  std::vector<const Region *> result;
  for (const auto &r : regions) {
    if (r.overlaps(region))
      result.push_back(&r);
  }
  return result;
}

void Grid::check_is_in_range(const Region &region) {
  auto err_msg =
      std::format("Cannot use region {}. Coordinate out of range for "
                  "grid with dimension: ({},{})",
                  region.to_str(), n_rows, n_cols);

  if ((region.get_row_end() > n_rows - 1) ||
      (region.get_col_end() > n_cols - 1))
    throw std::out_of_range(err_msg);
}

void Grid::add_region(const Region &r) {
  if (r.get_luminous_power() != 0)
    regions.push_back(r);
}
