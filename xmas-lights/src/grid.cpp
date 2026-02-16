#include "include/grid.h"
#include <format>
#include <stdexcept>

Grid::Grid(const int &a_n_rows, const int &a_n_cols) {
  if (a_n_rows < 0) {
    throw std::invalid_argument("Number of rows should be non-negative");
  }
  if (a_n_cols < 0) {
    throw std::invalid_argument("Number of columns should be non-negative");
  }
  n_rows = a_n_rows;
  n_cols = a_n_cols;

  lights.resize(n_rows, std::vector<int>(n_cols, 0));
}

void Grid::activate_light(const int &row, const int &col) {
  check_is_in_range(row, col, "turn-on");
  lights[row][col] = 1;
}

void Grid::disactivate_light(const int &row, const int &col) {

  check_is_in_range(row, col, "turn-off");
  lights[row][col] = 0;
}

int Grid::light_emission() {
  int sum = 0;
  for (const auto &row : lights) {
    for (const auto &val : row) {
      sum += val;
    }
  }
  return sum;
}

void Grid::check_is_in_range(const int &row, const int &col,
                             const std::string &action) {
  auto err_msg =
      std::format("Cannot {} light at (row,col): ({},{}). "
                  "Coordinate out of range for grid with dimension: ({},{})",
                  action, row, col, n_rows, n_cols);

  if ((row >= n_rows) || (col >= n_cols))
    throw std::out_of_range(err_msg);
}
