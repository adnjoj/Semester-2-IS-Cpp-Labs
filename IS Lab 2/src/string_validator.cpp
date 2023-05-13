#include "../include/string_validator.h"

bool StringValidator::IsVarName(const std::string &str) const {
  return !(str.empty() || str[0] < 'a' || str[0] > 'z');
}

bool StringValidator::IsNumber(const std::string &str) const {
  return !(str.empty() || str[0] < '0' || str[0] > '9');
}
