#ifndef IS_LAB_4_INCLUDE_VECTOR2_H_
#define IS_LAB_4_INCLUDE_VECTOR2_H_

#include <ostream>

class Vector2 {
 public:
  double x;
  double y;

  Vector2(double x, double y) : x(x), y(y) {}

  Vector2 operator+(const Vector2 &v) const;

  Vector2 operator*(double m) const;
};

std::ostream &operator<<(std::ostream &out, const Vector2 &vector);

#endif //IS_LAB_4_INCLUDE_VECTOR2_H_
