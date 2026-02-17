#ifndef GRID_H_
#define GRID_H_

#include "operation.h"
#include "region.h"
#include <string>
#include <vector>

class Grid {
public:
  Grid(const int &n_rows, const int &n_cols);
  void activate(const Region &r);
  void disactivate(const Region &r);
  void toggle(const Region &r);
  int light_emission();

private:
  int n_rows;
  int n_cols;
  int n_lights;
  std::vector<Operation> operations;
  void check_is_in_range(const int &row, const int &col,
                         const std::string &action);
  bool is_operation_redundant(const Operation &operation);
};

#endif // GRID_H_
