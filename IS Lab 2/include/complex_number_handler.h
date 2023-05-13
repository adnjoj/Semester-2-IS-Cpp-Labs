#ifndef IS_LAB_2_COMPLEX_NUMBER_HANDLER_H
#define IS_LAB_2_COMPLEX_NUMBER_HANDLER_H

#include "complex_number.h"
#include "string_parser.h"
#include "string_validator.h"

#include <unordered_map>
#include <string>
#include <ostream>

class ComplexNumberHandler {
 public:
  ComplexNumberHandler(
      std::ostream &out_stream,
      std::ostream &err_stream,
      StringValidator validator
  ) :
      _out_stream(out_stream),
      _err_stream(err_stream),
      _validator(std::move(validator)) {}

  void HandleCommand(StringParser &parser);

  void HandleCreate(StringParser &parser);

  void HandleGetReal(StringParser &parser) const;

  void HandleGetImaginary(StringParser &parser) const;

  void HandleAbs(StringParser &parser) const;

  void HandleSetReal(StringParser &parser);

  void HandleSetImaginary(StringParser &parser);

  void HandleAdd(StringParser &parser) const;

  void HandleMultiply(StringParser &parser) const;

  void HandlePrint(StringParser &parser) const;

 private:
  const StringValidator _validator;

  std::ostream &_out_stream;
  std::ostream &_err_stream;
  std::unordered_map<std::string, ComplexNumber> _vars;
};

#endif //IS_LAB_2_COMPLEX_NUMBER_HANDLER_H
