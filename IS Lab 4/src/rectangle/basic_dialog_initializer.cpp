#include "../../include/rectangle/basic_dialog_initializer.h"

Rectangle *RectangleBasicDialogInitializer::Initialize() const {
  double x, y, width, height, mass;
  _in_stream >> x >> y >> width >> height >> mass;

  return new Rectangle{x, y, width, height, mass};
}
