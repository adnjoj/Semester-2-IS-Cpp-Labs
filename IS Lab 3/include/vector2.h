#ifndef IS_LAB_3_VECTOR2_H
#define IS_LAB_3_VECTOR2_H

class Vector2 {
 public:
  double x;
  double y;

  Vector2() : x(0), y(0) {}

  Vector2(double _x, double _y) : x(_x), y(_y) {}

  Vector2 operator+(const Vector2 &v) const;

  bool operator==(const Vector2 &v) const;
};

#endif //IS_LAB_3_VECTOR2_H
