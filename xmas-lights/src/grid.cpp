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
  n_lights = 0;
}
int Grid::light_emission() { return n_lights; }

bool Grid::is_region_redundant(const Region &region) {
  if (added_regions.size() == 0)
    return false;

  for (std::vector<Region>::iterator iter = added_regions.begin();
       iter != added_regions.end(); ++iter) {

    if ((*iter).contains(region))
      return true;
  }
  return false;
}

void Grid::activate(const Region &r) {
  check_is_in_range(r);
  if (is_region_redundant(r))
    return;
  added_regions.push_back(r);
  n_lights += r.size();
}

void Grid::disactivate(const Region &r) {
  check_is_in_range(r);
  if (added_regions.size() > 0) {
    for (std::vector<Region>::iterator iter = added_regions.begin();
         iter != added_regions.end(); ++iter) {
      if ((*iter).contains(r))
        n_lights -= r.size();
    }
    return;
  }

  n_lights = 0;
}

void Grid::check_is_in_range(const Region &region) {
  auto err_msg = std::format("Cannot use region. Coordinate out of range for "
                             "grid with dimension: ({},{})",
                             n_rows, n_cols);

  if ((region.get_row_end() > n_rows - 1) ||
      (region.get_col_end() > n_cols - 1))
    throw std::out_of_range(err_msg);
}
