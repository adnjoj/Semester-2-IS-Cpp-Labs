#include "../include/complex_number.h"

#include <cmath>
#include <ostream>

ComplexNumber ComplexNumber::operator*(double number) const {
  return {_re * number, _im * number};
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &number) const {
  return {
      _re * number.Real() - _im * number.Imaginary(),
      _re * number.Imaginary() + _im * number.Real()
  };
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &number) const {
  return {_re + number.Real(), _im + number.Imaginary()};
}

std::ostream &operator<<(std::ostream &out, const ComplexNumber &number) {
  return out << number.Real() << " + " << number.Imaginary() << "i";
}

double ComplexNumber::Real() const {
  return _re;
}

double ComplexNumber::Imaginary() const {
  return _im;
}

double ComplexNumber::Abs() const {
  return sqrt(_re * _re + _im * _im);
}

void ComplexNumber::SetReal(double real) {
  _re = real;
}

void ComplexNumber::SetImaginary(double imaginary) {
  _im = imaginary;
}
