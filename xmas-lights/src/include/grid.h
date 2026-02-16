#ifndef GRID_H_
#define GRID_H_

#include <string>
#include <vector>

struct Region {
    bool row_start = 0;
    bool row_end = 0;
    bool col_start = 0;
    bool col_end = 0;
};

class Grid {
  public:
    Grid(const int &n_rows, const int &n_cols);
    void activate_light(const int &row, const int &col);
    void disactivate_light(const int &row, const int &col);
    void toggle_light(const int &row, const int &col);
    void activate_region(const Region &r);
    void disactivate_region(const Region &r);
    void toggle_region(const Region &r);
    int light_emission();

  private:
    int n_rows;
    int n_cols;
    std::vector<std::vector<int>> lights;
    void check_is_in_range(const int &row, const int &col,
                           const std::string &action);
};

#endif // GRID_H_
