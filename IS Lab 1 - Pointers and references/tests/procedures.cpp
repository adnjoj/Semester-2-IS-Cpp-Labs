#include "../include/procedures.h"

#include <iostream>

void TestTruncate() {
  std::cout << std::endl << "Testing Truncate procedure:" << std::endl << std::endl;

  float test_cases[] = {0.5, 100.0001, -999.999, 10000000.10, -0.00000001};
  float expected[] = {0, 100, -999, 10000000, 0};

  for (int i = 0; i < 5; i++) {
    float value = test_cases[i];

    Truncate(value);

    assert(value == expected[i]);

    std::printf("    Test %i passed: Truncate(%.8f) = %f\n", i + 1, test_cases[i], value);
  }

  std::cout << std::endl << "Truncate procedure passed all tests!" << std::endl;
}

void TestTruncatePtr() {
  std::cout << std::endl << "Testing TruncatePtr procedure:" << std::endl << std::endl;

  float test_cases[] = {0.5, 100.0001, -999.999, 10000000.10, -0.00000001};
  float expected[] = {0, 100, -999, 10000000, 0};

  for (int i = 0; i < 5; i++) {
    float value = test_cases[i];

    TruncatePtr(&value);

    assert(value == expected[i]);

    std::printf("    Test %i passed: TruncatePtr(%.8f) = %f\n", i + 1, test_cases[i], value);
  }

  std::cout << std::endl << "TruncatePtr procedure passed all tests!" << std::endl;
}

void TestNegateInt() {
  std::cout << std::endl << "Testing NegateInt procedure:" << std::endl << std::endl;

  int test_cases[] = {1, 100, -999, 10000000, INT_MAX};
  int expected[] = {-1, -100, 999, -10000000, -INT_MAX};

  for (int i = 0; i < 5; i++) {
    int value = test_cases[i];

    NegateInt(value);

    assert(value == expected[i]);

    std::printf("    Test %i passed: NegateInt(%i) = %i\n", i + 1, test_cases[i], value);
  }

  std::cout << std::endl << "NegateInt procedure passed all tests!" << std::endl;
}

void TestNegateIntPtr() {
  std::cout << std::endl << "Testing NegateIntPtr procedure:" << std::endl << std::endl;

  int test_cases[] = {1, 100, -999, 10000000, INT_MAX};
  int expected[] = {-1, -100, 999, -10000000, -INT_MAX};

  for (int i = 0; i < 5; i++) {
    int value = test_cases[i];

    NegateIntPtr(&value);

    assert(value == expected[i]);

    std::printf("    Test %i passed: NegateIntPtr(%i) = %i\n", i + 1, test_cases[i], value);
  }

  std::cout << std::endl << "NegateIntPtr procedure passed all tests!" << std::endl;
}

void TestNegateFloat() {
  std::cout << std::endl << "Testing NegateFloat procedure:" << std::endl << std::endl;

  float test_cases[] = {1.01, 100.99, -999.98, 10000000.56443, 128817.12938};
  float expected[] = {-1.01, -100.99, 999.98, -10000000.56443, -128817.12938};

  for (int i = 0; i < 5; i++) {
    float value = test_cases[i];

    NegateFloat(value);

    assert(value == expected[i]);

    std::printf("    Test %i passed: NegateFloat(%f) = %f\n", i + 1, test_cases[i], value);
  }

  std::cout << std::endl << "NegateFloat procedure passed all tests!" << std::endl;
}

void TestNegateFloatPtr() {
  std::cout << std::endl << "Testing NegateFloatPtr procedure:" << std::endl << std::endl;

  float test_cases[] = {1.01, 100.99, -999.98, 10000000.56443, 128817.12938};
  float expected[] = {-1.01, -100.99, 999.98, -10000000.56443, -128817.12938};

  for (int i = 0; i < 5; i++) {
    float value = test_cases[i];

    NegateFloatPtr(&value);

    assert(value == expected[i]);

    std::printf("    Test %i passed: NegateFloatPtr(%f) = %f\n", i + 1, test_cases[i], value);
  }

  std::cout << std::endl << "NegateFloatPtr procedure passed all tests!" << std::endl;
}
