#ifndef IS_LAB_5_INCLUDE_INDEX_OUT_OF_BOUND_EXCEPTION_H_
#define IS_LAB_5_INCLUDE_INDEX_OUT_OF_BOUND_EXCEPTION_H_

#include <exception>

class IndexOutOfBoundsException : public std::exception {
 public:
  [[nodiscard]] const char *what() const noexcept override {
    return "Array index out of bounds";
  }
};

#endif //IS_LAB_5_INCLUDE_INDEX_OUT_OF_BOUND_EXCEPTION_H_
