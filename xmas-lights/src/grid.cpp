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

bool Grid::is_operation_redundant(const Operation &operation) {
  if (operations.size() == 0)
    return false;

  for (std::vector<Operation>::reverse_iterator riter = operations.rbegin();
       riter != operations.rend(); ++riter) {

    if ((*riter).get_region().contains(operation.get_region()))
      return true;
  }
  return false;
}

void Grid::activate(const Region &r) {
  auto new_operation = Operation(r);
  if (is_operation_redundant(new_operation))
    return;
  operations.push_back(new_operation);
  n_lights += r.size();
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
