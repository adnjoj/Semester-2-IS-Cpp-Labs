#include "../../include/rectangle/rectangle.h"

std::string Rectangle::ClassName() const {
  return "Rectangle";
}

size_t Rectangle::Size() const {
  return sizeof(*this);
}

double Rectangle::Square() const {
  return width * height;
}

double Rectangle::Perimeter() const {
  return 2 * (width + height);
}

std::string Rectangle::Serialize() const {
  if (_serializer == nullptr) {
    return "";
  }

  return _serializer->Serialize(*this);
}

void Rectangle::UseSerializer(const IRectangleSerializer *serializer) {
  _serializer = serializer;
}
