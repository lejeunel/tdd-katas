#ifndef GRID_H_
#define GRID_H_

#include <vector>

class Grid {
  public:
    Grid(const int &n_rows, const int &n_cols);
    void activate_light(const int &row, const int &col);
    int light_emission();

  private:
    int n_rows;
    int n_cols;
    std::vector<std::vector<int>> lights;
};

#endif // GRID_H_
