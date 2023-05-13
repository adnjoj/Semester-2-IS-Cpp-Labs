#include <cmath>

void Truncate(float &number) {
  number = trunc(number);
}

void TruncatePtr(float *number) {
  *number = trunc(*number);
}

void NegateInt(int &number) {
  number = -number;
}

void NegateIntPtr(int *number) {
  *number = -(*number);
}

void NegateFloat(float &number) {
  number = -number;
}

void NegateFloatPtr(float *number) {
  *number = -(*number);
}
