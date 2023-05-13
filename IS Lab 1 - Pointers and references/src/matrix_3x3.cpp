#include "../include/matrix_3x3.h"

#include <cstdlib>

Matrix3x3::Matrix3x3(const Matrix3x3 &matrix) {
  elements = (double *) malloc(9 * sizeof(double));

  for (int i = 0; i < 9; i++) {
    elements[i] = matrix.elements[i];
  }
}

Matrix3x3::Matrix3x3(std::initializer_list<double> _elements) {
  elements = (double *) malloc(9 * sizeof(double));

  int i = 0;

  for (double element : _elements) {
    elements[i++] = element;
  }

  for (; i < 9; i++) {
    elements[i] = 0;
  }
}

Matrix3x3::~Matrix3x3() {
  free(elements);
}

void MultiplyMatrix(Matrix3x3 &matrix, double x) {
  for (int i = 0; i < 9; i++) {
    matrix.elements[i] *= x;
  }
}

void MultiplyMatrixPtr(Matrix3x3 *matrix, double x) {
  for (int i = 0; i < 9; i++) {
    matrix->elements[i] *= x;
  }
}
