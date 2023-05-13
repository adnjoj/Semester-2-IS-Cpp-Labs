#include "../include/matrix_3x3.h"

#include <iostream>

void TestMultiplyMatrix(int tests_count, std::pair<Matrix3x3, double> test_cases[], Matrix3x3 expected[]) {
  std::cout << std::endl << "Testing MultiplyMatrix procedure:" << std::endl << std::endl;

  for (int i = 0; i < tests_count; i++) {
    Matrix3x3 matrix = test_cases[i].first;

    MultiplyMatrix(matrix, test_cases[i].second);

    for (int j = 0; j < 9; j++) {
      assert(matrix.elements[j] == expected[i].elements[j]);
    }

    std::cout << "    Test " << i + 1 << " passed" << std::endl;
  }

  std::cout << std::endl << "MultiplyMatrix procedure passed all tests!" << std::endl;
}

void TestMultiplyMatrixPtr(int tests_count, std::pair<Matrix3x3, double> test_cases[], Matrix3x3 expected[]) {
  std::cout << std::endl << "Testing MultiplyMatrixPtr procedure:" << std::endl << std::endl;

  for (int i = 0; i < tests_count; i++) {
    Matrix3x3 matrix = test_cases[i].first;

    MultiplyMatrixPtr(&matrix, test_cases[i].second);

    for (int j = 0; j < 9; j++) {
      assert(matrix.elements[j] == expected[i].elements[j]);
    }

    std::cout << "    Test " << i + 1 << " passed" << std::endl;
  }

  std::cout << std::endl << "MultiplyMatrixPtr procedure passed all tests!" << std::endl;
}

void TestMatrixMultiplication() {
  std::pair<Matrix3x3, double> test_cases[] = {
      {{}, 5},
      {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 2.5},
      {{1, 2, 3}, -1.5},
      {{1, 0, 0, 2, 0, 0, 3, 0, 0}, 10},
      {{0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09}, 0}
  };

  Matrix3x3 expected[] = {
      {},
      {2.5, 5, 7.5, 10, 12.5, 15, 17.5, 20, 22.5},
      {-1.5, -3, -4.5},
      {10, 0, 0, 20, 0, 0, 30, 0, 0},
      {}
  };

  TestMultiplyMatrix(5, test_cases, expected);

  TestMultiplyMatrixPtr(5, test_cases, expected);
}
