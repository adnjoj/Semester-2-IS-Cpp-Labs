#include "../../include/rectangle/basic_serializer.h"

std::string RectangleBasicSerializer::Serialize(const Rectangle &rectangle) const {
  return "Rectangle { x: "
      + std::to_string(rectangle.position.x)
      + ", y: "
      + std::to_string(rectangle.position.y)
      + ", width: "
      + std::to_string(rectangle.width)
      + ", height: "
      + std::to_string(rectangle.height)
      + ", mass: "
      + std::to_string(rectangle.mass)
      + " }";
}
