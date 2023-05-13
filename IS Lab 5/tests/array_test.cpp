#include "../include/array.h"

#include <iostream>

void TestArray() {
  std::cout << "Testing Array:" << std::endl;

  Array<10, int> array;

  for (int i = 0; i < 10; i++) {
    array.Set(i, i * i);
  }

  for (int i = 0; i < 10; i++) {
    assert(array.Get(i) == i * i);
  }

  try {
    array.Get(100);
  } catch (IndexOutOfBoundsException &e) {
    std::cout << "All tests are passed!" << std::endl;
    return;
  }

  assert(false);
}