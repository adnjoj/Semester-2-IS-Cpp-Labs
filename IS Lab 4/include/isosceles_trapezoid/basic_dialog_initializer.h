#ifndef IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_BASIC_DIALOG_INITIALIZER_H_
#define IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_BASIC_DIALOG_INITIALIZER_H_

#include "isosceles_trapezoid.h"
#include "i_dialog_initializer.h"

#include <istream>

class IsoscelesTrapezoidBasicDialogInitializer : public IIsoscelesTrapezoidDialogInitializer {
 public:
  explicit IsoscelesTrapezoidBasicDialogInitializer(std::istream &in_stream) : _in_stream(in_stream) {}

  [[nodiscard]] IsoscelesTrapezoid *Initialize() const override;

 private:
  std::istream &_in_stream;
};

#endif //IS_LAB_4_INCLUDE_ISOSCELES_TRAPEZOID_BASIC_DIALOG_INITIALIZER_H_
