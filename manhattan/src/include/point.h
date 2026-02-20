#ifndef POINT_H_
#define POINT_H_
class Point {
  public:
    Point(float a_x, float a_y);
    float manhattan_distance(const Point &q) const;

  private:
    float x;
    float y;
};

#endif // POINT_H_
