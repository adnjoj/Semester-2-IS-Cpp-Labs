#ifndef IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_I_SERIALIZER_H_
#define IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_I_SERIALIZER_H_

#include "isosceles_trapezoid.h"

#include <string>

class IsoscelesTrapezoid;

class IIsoscelesTrapezoidSerializer {
 public:
  [[nodiscard]] virtual std::string Serialize(const IsoscelesTrapezoid &trapezoid) const = 0;
};

#endif //IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_I_SERIALIZER_H_
