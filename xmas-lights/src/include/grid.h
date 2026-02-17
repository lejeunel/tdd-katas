#ifndef GRID_H_
#define GRID_H_

#include "region.h"
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
  std::vector<Region> added_regions;
  void check_is_in_range(const Region &region);
  bool is_region_redundant(const Region &region);
};

#endif // GRID_H_
