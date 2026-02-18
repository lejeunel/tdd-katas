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
int Grid::light_units() {
  auto total_light = 0;
  for (const auto &r : regions)
    total_light += r.get_light();
  return total_light;
}

void Grid::activate(Region r) {
  check_is_in_range(r);
  r.set_light(r.size() - overlap_area(r));
  regions.push_back(r);
}

void Grid::disactivate(Region r) {
  check_is_in_range(r);
  auto budget = r.size();
  for (const auto &ovr : find_overlapping_regions(r)) {
    auto delta = std::min(budget, std::min(ovr->get_light(), ovr->overlaps(r)));
    r.set_light(r.get_light() - delta);
    budget -= delta;
  }

  if (r.get_light() != 0)
    regions.push_back(r);
}

void Grid::toggle(Region r) {
  check_is_in_range(r);
  auto overlap = overlap_area(r);
  if (overlap == 0)
    r.set_light(r.size());
  else
    r.set_light(-overlap);
  regions.push_back(r);
}

int Grid::overlap_area(const Region &region) {
  if (regions.size() == 0)
    return 0;

  int n_overlap = 0;
  for (const auto &r : regions) {
    n_overlap += r.overlaps(region);
  }

  return n_overlap;
}
std::vector<const Region *>
Grid::find_overlapping_regions(const Region &region) {
  std::vector<const Region *> result;
  for (const auto &r : regions) {
    if (r.overlaps(region) > 0)
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
