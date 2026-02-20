#include "include/point.h"
#include <cmath>

Point::Point(float a_x, float a_y) : x(a_x), y(a_y) {};

float Point::manhattan_distance(const Point &other) const {
  return std::abs(other.x - x) + std::abs(other.y - y);
}
