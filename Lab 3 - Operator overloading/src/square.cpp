#include "../include/square.h"

bool Square::operator==(const Square &s) const {
  return Area() == s.Area();
}

bool Square::operator!=(const Square &s) const {
  return !operator==(s);
}

bool Square::operator<(const Square &s) const {
  return Area() < s.Area();
}

bool Square::operator<=(const Square &s) const {
  return Area() <= s.Area();
}

bool Square::operator>(const Square &s) const {
  return Area() > s.Area();
}

bool Square::operator>=(const Square &s) const {
  return Area() >= s.Area();
}

Square Square::operator*(double number) const {
  return {_pos, _side * number, _angle};
}

Square Square::operator+(const Vector2 &v) const {
  return {_pos + v, _side, _angle};
}

double Square::Area() const {
  return _side * _side;
}

Vector2 Square::Position() const {
  return _pos;
}

double Square::Side() const {
  return _side;
}
