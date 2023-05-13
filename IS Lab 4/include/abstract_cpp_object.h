#ifndef IS_LAB_4_INCLUDE_ABSTRACT_CPP_OBJECT_H_
#define IS_LAB_4_INCLUDE_ABSTRACT_CPP_OBJECT_H_

#include <string>

class ICppObject {
 public:
  [[nodiscard]] virtual std::string ClassName() const = 0;

  [[nodiscard]] virtual size_t Size() const = 0;
};

#endif //IS_LAB_4_INCLUDE_ABSTRACT_CPP_OBJECT_H_
