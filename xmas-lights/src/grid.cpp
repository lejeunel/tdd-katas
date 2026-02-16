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
  auto err_msg =
      std::format("Cannot turn-on light at (row,col): ({},{}). "
                  "Coordinate out of range for grid with dimension: ({},{})",
                  row, col, n_rows, n_cols);

  if ((row >= n_rows) || (col >= n_cols))
    throw std::out_of_range(err_msg);

  lights[row][col] = 1;
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
