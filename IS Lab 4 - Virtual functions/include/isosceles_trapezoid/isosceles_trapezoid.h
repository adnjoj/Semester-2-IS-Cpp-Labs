#ifndef IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_ISOSCELES_TRAPEZOID_H_
#define IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_ISOSCELES_TRAPEZOID_H_

#include "../abstract_serializable_shape_body.h"
#include "i_serializer.h"

class IIsoscelesTrapezoidSerializer;

class IsoscelesTrapezoid : public AbstractSerializableShapeBody {
 public:
  double height;
  double upper_base_length;
  double lower_base_length;

  IsoscelesTrapezoid(double x,
                     double y,
                     double height,
                     double upper_base_length,
                     double lower_base_length,
                     double mass)
      :
      AbstractSerializableShapeBody(x, y, mass),
      height(height),
      upper_base_length(upper_base_length),
      lower_base_length(lower_base_length),
      _serializer(nullptr) {}

  [[nodiscard]] std::string ClassName() const override;

  [[nodiscard]] size_t Size() const override;

  [[nodiscard]] double Square() const override;

  [[nodiscard]] double Perimeter() const override;

  [[nodiscard]] std::string Serialize() const override;

  void UseSerializer(const IIsoscelesTrapezoidSerializer *serializer);

 private:
  const IIsoscelesTrapezoidSerializer *_serializer;
};

#endif //IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_ISOSCELES_TRAPEZOID_H_
