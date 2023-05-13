#ifndef IS_LAB_4_INCLUDE_RECTANGLE_H_
#define IS_LAB_4_INCLUDE_RECTANGLE_H_

#include "../abstract_serializable_shape_body.h"
#include "i_serializer.h"

class Rectangle : public AbstractSerializableShapeBody {
 public:
  double width;
  double height;

  Rectangle(double x, double y, double width, double height, double mass) :
      AbstractSerializableShapeBody(x, y, mass),
      width(width),
      height(height),
      _serializer(nullptr) {}

  [[nodiscard]] std::string ClassName() const override;

  [[nodiscard]] size_t Size() const override;

  [[nodiscard]] double Square() const override;

  [[nodiscard]] double Perimeter() const override;

  [[nodiscard]] std::string Serialize() const override;

  void UseSerializer(const IRectangleSerializer *serializer);

 private:
  const IRectangleSerializer *_serializer;
};

#endif //IS_LAB_4_INCLUDE_RECTANGLE_H_
