#include "include/grid.h"
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
  auto total_light_units = 0;
  for (std::vector<Region>::iterator iter = regions.begin();
       iter != regions.end(); ++iter)
    total_light_units += (*iter).get_light_units();
  return total_light_units;
}

void Grid::activate(Region r) {
  check_is_in_range(r);
  r.set_light_units(r.size() - overlap_existing_region(r));
  regions.push_back(r);
}

void Grid::toggle(Region r) {
  check_is_in_range(r);
  auto overlap = overlap_existing_region(r);
  if (overlap == 0)
    r.set_light_units(r.size());
  else
    r.set_light_units(-overlap);
  regions.push_back(r);
}

void Grid::disactivate(Region r) {
  check_is_in_range(r);
  auto overlap = overlap_existing_region(r);
  if (overlap >= r.size())
    r.set_light_units(-r.size());
  else
    r.set_light_units(-overlap);

  regions.push_back(r);
}

int Grid::overlap_existing_region(const Region &region) {
  if (regions.size() == 0)
    return 0;

  int n_overlap = 0;
  for (std::vector<Region>::iterator iter = regions.begin();
       iter != regions.end(); ++iter) {
    n_overlap += (*iter).overlaps(region);
  }

  return n_overlap;
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
