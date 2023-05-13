#include "../include/vector2.h"

Vector2 Vector2::operator+(const Vector2 &v) const {
  return {x + v.x, y + v.y};
}

Vector2 Vector2::operator*(double m) const {
  return {x * m, y * m};
}

std::ostream &operator<<(std::ostream &out, const Vector2 &vector) {
  return out << "{ " << vector.x << ", " << vector.y << " }";
}
