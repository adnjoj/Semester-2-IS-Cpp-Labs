#include "../include/power.h"

#include <iostream>

void TestPower() {
  std::cout << "Testing Power function:" << std::endl;

  if (Power<int, 1>(1) != 1) return;
  if (Power<int, 0>(1) != 1) return;
  if (Power<int, 2>(10) != 100) return;
  if (Power<int, -10>(2) != 0) return;

  std::cout << "All tests on integers are passed!" << std::endl;

  if (Power<double, 1>(1.0) != 1.0) return;
  if (Power<double, -10>(2.0) != 1.0 / 1024.0) return;
  if (Power<double, 2>(10.0) != 100.0) return;
  if (Power<double, 3>(-1.5) != -3.375) return;

  std::cout << "All tests on doubles are passed!" << std::endl;
}
