#ifndef GRID_H_
#define GRID_H_

#include "region.h"
#include <vector>

class Grid {
public:
  Grid(const int &n_rows, const int &n_cols);
  void activate(Region r);
  void disactivate(Region r);
  void toggle(Region r);
  int light_units();

private:
  int n_rows;
  int n_cols;
  std::vector<Region> regions;
  void check_is_in_range(const Region &region);
  int overlap_area(const Region &region);
};

#endif // GRID_H_
