#include "../../include/isosceles_trapezoid/basic_dialog_initializer.h"

IsoscelesTrapezoid *IsoscelesTrapezoidBasicDialogInitializer::Initialize() const {
  double x, y, height, upper_base_length, lower_base_length, mass;
  _in_stream >> x >> y >> height >> upper_base_length >> lower_base_length >> mass;

  return new IsoscelesTrapezoid{x, y, height, upper_base_length, lower_base_length, mass};
}
