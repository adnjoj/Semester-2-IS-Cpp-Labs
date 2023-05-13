#include "../../include/isosceles_trapezoid/isosceles_trapezoid.h"

#include <cmath>

std::string IsoscelesTrapezoid::ClassName() const {
  return "IsoscelesTrapezoid";
}

size_t IsoscelesTrapezoid::Size() const {
  return sizeof(*this);
}

double IsoscelesTrapezoid::Square() const {
  return 0.5 * height * (upper_base_length + lower_base_length);
}

double IsoscelesTrapezoid::Perimeter() const {
  double bases_diff = upper_base_length - lower_base_length;
  double side = sqrt(height * height + 0.25 * bases_diff * bases_diff);
  return upper_base_length + lower_base_length + 2 * side;
}

std::string IsoscelesTrapezoid::Serialize() const {
  if (_serializer == nullptr) {
    return "";
  }

  return _serializer->Serialize(*this);
}

void IsoscelesTrapezoid::UseSerializer(const IIsoscelesTrapezoidSerializer *serializer) {
  _serializer = serializer;
}
