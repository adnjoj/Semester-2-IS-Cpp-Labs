#ifndef IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_BASIC_SERIALIZER_H_
#define IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_BASIC_SERIALIZER_H_

#include "i_serializer.h"
#include "isosceles_trapezoid.h"

class IsoscelesTrapezoidBasicSerializer : public IIsoscelesTrapezoidSerializer {
 public:
  [[nodiscard]] std::string Serialize(const IsoscelesTrapezoid &trapezoid) const override;
};

#endif //IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_BASIC_SERIALIZER_H_
