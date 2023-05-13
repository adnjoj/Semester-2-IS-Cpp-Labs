#ifndef IS_LAB_4_INCLUDE_RECTANGLE_BASIC_DIALOG_INITIALIZER_H_
#define IS_LAB_4_INCLUDE_RECTANGLE_BASIC_DIALOG_INITIALIZER_H_

#include "rectangle.h"
#include "i_dialog_initializer.h"

#include <istream>

class RectangleBasicDialogInitializer : public IRectangleDialogInitializer {
 public:
  explicit RectangleBasicDialogInitializer(std::istream &in_stream) : _in_stream(in_stream) {}

  [[nodiscard]] Rectangle *Initialize() const override;

 private:
  std::istream &_in_stream;
};

#endif //IS_LAB_4_INCLUDE_RECTANGLE_BASIC_DIALOG_INITIALIZER_H_
