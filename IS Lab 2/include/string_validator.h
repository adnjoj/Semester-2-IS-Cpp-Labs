#ifndef IS_LAB_2_INCLUDE_STRING_VALIDATOR_H_
#define IS_LAB_2_INCLUDE_STRING_VALIDATOR_H_

#include <string>
#include <ostream>

class StringValidator {
 public:
  [[nodiscard]] virtual bool IsVarName(const std::string &str) const;

  [[nodiscard]] virtual bool IsNumber(const std::string &str) const;
};

#endif //IS_LAB_2_INCLUDE_STRING_VALIDATOR_H_
