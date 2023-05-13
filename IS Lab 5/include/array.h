#ifndef IS_LAB_5_INCLUDE_ARRAY_H_
#define IS_LAB_5_INCLUDE_ARRAY_H_

#include "index_out_of_bound_exception.h"

#include <vector>

template<int N, typename T>
class Array {
 public:
  Array() : _elements(N) {}

  T Get(int i) const {
    if (i < 0 || i >= N) throw IndexOutOfBoundsException();
    return _elements[i];
  }

  void Set(int i, T value) {
    if (i < 0 || i >= N) throw IndexOutOfBoundsException();
    _elements[i] = value;
  }

 private:
  std::vector<T> _elements;
};

#endif //IS_LAB_5_INCLUDE_ARRAY_H_
