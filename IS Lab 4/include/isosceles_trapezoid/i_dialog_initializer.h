#ifndef IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_I_DIALOG_INITIALIZER_H_
#define IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_I_DIALOG_INITIALIZER_H_

#include "isosceles_trapezoid.h"

class IIsoscelesTrapezoidDialogInitializer {
 public:
  [[nodiscard]] virtual IsoscelesTrapezoid *Initialize() const = 0;
};

#endif //IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_I_DIALOG_INITIALIZER_H_
