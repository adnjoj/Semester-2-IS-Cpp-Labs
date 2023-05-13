#ifndef IS_LAB_3_SQUARE_H
#define IS_LAB_3_SQUARE_H

#include "vector2.h"

class Square {
 public:
  Square() : _pos(0, 0), _side(1), _angle(0) {}

  explicit Square(double side) : _pos(0, 0), _side(side), _angle(0) {}

  Square(double x, double y) : _pos(x, y), _side(1), _angle(0) {}

  explicit Square(const Vector2 &pos) : Square(pos.x, pos.y) {}

  Square(double x, double y, double side) : _pos(x, y), _side(side), _angle(0) {}

  Square(const Vector2 &pos, double side) : Square(pos.x, pos.y, side) {}

  Square(double x, double y, double side, double angle) : _pos(x, y), _side(side), _angle(angle) {}

  Square(const Vector2 &pos, double side, double angle) : Square(pos.x, pos.y, side, angle) {}

  [[nodiscard]] double Area() const;

  [[nodiscard]] Vector2 Position() const;

  [[nodiscard]] double Side() const;

  bool operator==(const Square &s) const;

  bool operator!=(const Square &s) const;

  bool operator<(const Square &s) const;

  bool operator<=(const Square &s) const;

  bool operator>(const Square &s) const;

  bool operator>=(const Square &s) const;

  Square operator*(double number) const;

  Square operator+(const Vector2 &v) const;

 private:
  Vector2 _pos;
  double _side;
  double _angle;
};

#endif //IS_LAB_3_SQUARE_H
