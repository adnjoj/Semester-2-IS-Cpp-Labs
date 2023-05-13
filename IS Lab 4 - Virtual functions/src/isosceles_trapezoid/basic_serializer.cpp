#include "../../include/isosceles_trapezoid/basic_serializer.h"

std::string IsoscelesTrapezoidBasicSerializer::Serialize(const IsoscelesTrapezoid &trapezoid) const {
  return "IsoscelesTrapezoid { x: "
      + std::to_string(trapezoid.position.x)
      + ", y: "
      + std::to_string(trapezoid.position.y)
      + ", height: "
      + std::to_string(trapezoid.height)
      + ", upper_base_length: "
      + std::to_string(trapezoid.upper_base_length)
      + ", lower_base_length: "
      + std::to_string(trapezoid.lower_base_length)
      + ", mass: "
      + std::to_string(trapezoid.mass)
      + " }";
}
