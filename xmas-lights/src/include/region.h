#ifndef REGION_H_
#define REGION_H_

class Region {
  public:
    Region(const int &row_start, const int &col_start, const int &row_end,
           const int &col_end);
    Region();
    int size() const;
    bool operator==(const Region &other) const;
    bool contains(const Region &other) const;
    int get_row_end() const;
    int get_col_end() const;

  private:
    int row_start = 0;
    int col_start = 0;
    int row_end = 0;
    int col_end = 0;
};

#endif // REGION_H_
