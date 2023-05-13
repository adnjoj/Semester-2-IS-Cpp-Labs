#ifndef IS_LAB_2_COMPLEX_NUMBER_H
#define IS_LAB_2_COMPLEX_NUMBER_H

#include <ostream>

class ComplexNumber {
 public:
  ComplexNumber() : _re(), _im() {}

  ComplexNumber(const ComplexNumber &number) = default;

  ComplexNumber(double real, double imaginary) : _re(real), _im(imaginary) {}

  explicit ComplexNumber(double real) : _re(real), _im() {}

  ComplexNumber operator*(double number) const;

  ComplexNumber operator*(const ComplexNumber &number) const;

  ComplexNumber operator+(const ComplexNumber &number) const;

  [[nodiscard]] double Real() const;

  [[nodiscard]] double Imaginary() const;

  [[nodiscard]] double Abs() const;

  void SetReal(double real);

  void SetImaginary(double imaginary);

 private:
  double _re;
  double _im;
};

std::ostream &operator<<(std::ostream &out, const ComplexNumber &number);

#endif //IS_LAB_2_COMPLEX_NUMBER_H
