#include "include/region.h"
#include <format>
#include <stdexcept>

Region::Region(const int &a_row_start, const int &a_col_start,
               const int &a_row_end, const int &a_col_end)
    : row_start(a_row_start), col_start(a_col_start), row_end(a_row_end),
      col_end(a_col_end) {
  if (row_end < row_start) {
    throw std::invalid_argument(
        std::format("Row-span should be at least 1, got start {} and end {}",
                    row_start, row_end));
  }

  if (col_end < col_start) {
    throw std::invalid_argument(
        std::format("Column-span should be at least 1, got start {} and end {}",
                    col_start, col_end));
  }
}

Region::Region() : row_start(0), col_start(0), row_end(0), col_end(0) {}

std::string Region::to_str() const {
  return std::format("({},{}), ({},{})", row_start, col_start, row_end,
                     col_end);
}

std::ostream &operator<<(std::ostream &os, const Region &region) {
  os << region.to_str();
  return os;
}

int Region::get_row_end() const { return row_end; }
int Region::get_col_end() const { return col_end; }

int Region::size() const {
  return (row_end - row_start + 1) * (col_end - col_start + 1);
}

bool Region::operator==(const Region &other) const {
  return row_start == other.row_start && col_start == other.col_start &&
         row_end == other.row_end && col_end == other.col_end;
}

bool Region::contains(const Region &other) const {
  if ((other.row_start >= row_start) && (other.row_end <= row_end) &&
      (other.col_start >= col_start) && (other.col_end <= col_end))
    return true;

  return false;
}

int Region::overlaps(const Region &other) const {
  auto col_overlap_start = std::max(col_start, other.col_start);
  auto col_overlap_end = std::min(col_end, other.col_end);
  auto n_overlapping_cols =
      std::max(0, col_overlap_end - col_overlap_start + 1);

  auto row_overlap_start = std::max(row_start, other.row_start);
  auto row_overlap_end = std::min(row_end, other.row_end);
  auto n_overlapping_rows =
      std::max(0, row_overlap_end - row_overlap_start + 1);

  return n_overlapping_cols * n_overlapping_rows;
}

int Region::get_luminous_power() const { return light_units; }

void Region::set_luminous_power(const int &a_light_units) {
  light_units = a_light_units;
}
