#ifndef IS_LAB_1_INCLUDE_MATRIX_3X3_H_
#define IS_LAB_1_INCLUDE_MATRIX_3X3_H_

#include <initializer_list>

struct Matrix3x3 {
  double *elements;

  Matrix3x3(const Matrix3x3 &matrix);

  Matrix3x3(std::initializer_list<double> _elements);

  ~Matrix3x3();
};

void MultiplyMatrix(Matrix3x3 &matrix, double x);

void MultiplyMatrixPtr(Matrix3x3 *matrix, double x);

#endif //IS_LAB_1_INCLUDE_MATRIX_3X3_H_
