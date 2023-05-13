#ifndef IS_LAB_4_INCLUDE_I_RECTANGLE_SERIALIZER_H_
#define IS_LAB_4_INCLUDE_I_RECTANGLE_SERIALIZER_H_

#include "rectangle.h"

#include <string>

class Rectangle;

class IRectangleSerializer {
 public:
  [[nodiscard]] virtual std::string Serialize(const Rectangle &rectangle) const = 0;
};

#endif //IS_LAB_4_INCLUDE_I_RECTANGLE_SERIALIZER_H_
