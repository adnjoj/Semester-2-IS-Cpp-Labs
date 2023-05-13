#ifndef IS_LAB_4_INCLUDE_RECTANGLE_I_DIALOG_INITIALIZER_H_
#define IS_LAB_4_INCLUDE_RECTANGLE_I_DIALOG_INITIALIZER_H_

#include "rectangle.h"

class IRectangleDialogInitializer {
 public:
  [[nodiscard]] virtual Rectangle *Initialize() const = 0;
};

#endif //IS_LAB_4_INCLUDE_RECTANGLE_I_DIALOG_INITIALIZER_H_
