#ifndef IS_LAB_4_INCLUDE_RECTANGLE_BASIC_SERIALIZER_H_
#define IS_LAB_4_INCLUDE_RECTANGLE_BASIC_SERIALIZER_H_

#include "rectangle.h"
#include "i_serializer.h"

class RectangleBasicSerializer : public IRectangleSerializer {
 public:
  [[nodiscard]] std::string Serialize(const Rectangle &rectangle) const override;
};

#endif //IS_LAB_4_INCLUDE_RECTANGLE_BASIC_SERIALIZER_H_
