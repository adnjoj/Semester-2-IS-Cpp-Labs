#include "../include/complex_number_handler.h"

#include <iomanip>

void ComplexNumberHandler::HandleCommand(StringParser &parser) {
  std::string command = parser.Next();

  if (command == "create") {
    HandleCreate(parser);
  } else if (command == "get_re") {
    HandleGetReal(parser);
  } else if (command == "get_im") {
    HandleGetImaginary(parser);
  } else if (command == "abs") {
    HandleAbs(parser);
  } else if (command == "set_re") {
    HandleSetReal(parser);
  } else if (command == "set_im") {
    HandleSetImaginary(parser);
  } else if (command == "add") {
    HandleAdd(parser);
  } else if (command == "mul") {
    HandleMultiply(parser);
  } else if (command == "print") {
    HandlePrint(parser);
  } else {
    _err_stream << "Unsupported command for complex numbers " << std::quoted(command) << std::endl;
  }
}

void ComplexNumberHandler::HandleCreate(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string op1 = parser.Next();
  std::string op2 = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " already exists" << std::endl;
    return;
  }

  if (op1.empty()) {
    _vars.insert_or_assign(var_name, ComplexNumber());
    return;
  }

  if (_validator.IsVarName(op1) && !_vars.contains(op1)) {
    _err_stream << "Variable " << std::quoted(op1) << " does not exist" << std::endl;
    return;
  }

  if (_validator.IsVarName(op1)) {
    _vars.insert_or_assign(var_name, ComplexNumber(_vars.at(op1)));
    return;
  }

  if (!_validator.IsNumber(op1)) {
    _err_stream << "Argument 2(" << std::quoted(op1) << ") must be a variable name or a double" << std::endl;
    return;
  }

  if (op2.empty()) {
    _vars.insert_or_assign(var_name, ComplexNumber(std::stod(op1)));
    return;
  }

  if (op2[0] < '0' || op2[0] > '9') {
    _err_stream << "Argument 3(" << std::quoted(op2) << ") must be a double" << std::endl;
    return;
  }

  _vars.insert_or_assign(var_name, ComplexNumber(std::stod(op1), std::stod(op2)));
}

void ComplexNumberHandler::HandleGetReal(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << _vars.at(var_name).Real() << std::endl;
}

void ComplexNumberHandler::HandleGetImaginary(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << _vars.at(var_name).Imaginary() << std::endl;
}

void ComplexNumberHandler::HandleAbs(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << _vars.at(var_name).Abs() << std::endl;
}

void ComplexNumberHandler::HandleSetReal(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string op1 = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  if (!_validator.IsNumber(op1)) {
    _err_stream << "Argument 2(" << std::quoted(var_name) << ") must be a double" << std::endl;
    return;
  }

  _vars.at(var_name).SetReal(std::stod(op1));
}

void ComplexNumberHandler::HandleSetImaginary(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string op1 = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  if (!_validator.IsNumber(op1)) {
    _err_stream << "Argument 2(" << std::quoted(var_name) << ") must be a double" << std::endl;
    return;
  }

  _vars.at(var_name).SetImaginary(std::stod(op1));
}

void ComplexNumberHandler::HandleAdd(StringParser &parser) const {
  std::string op1 = parser.Next();
  std::string op2 = parser.Next();

  if (!_validator.IsVarName(op1)) {
    _err_stream << "Argument 1(" << std::quoted(op1) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(op1)) {
    _err_stream << "Variable " << std::quoted(op1) << " does not exist" << std::endl;
    return;
  }

  if (!_validator.IsVarName(op2)) {
    _err_stream << "Argument 2(" << std::quoted(op2) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(op2)) {
    _err_stream << "Variable " << std::quoted(op2) << " does not exist" << std::endl;
    return;
  }

  _out_stream << (_vars.at(op1) + _vars.at(op2)) << std::endl;
}

void ComplexNumberHandler::HandleMultiply(StringParser &parser) const {
  std::string op1 = parser.Next();
  std::string op2 = parser.Next();

  if (!_validator.IsVarName(op1)) {
    _err_stream << "Argument 1(" << std::quoted(op1) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(op1)) {
    _err_stream << "Variable " << std::quoted(op1) << " does not exist" << std::endl;
    return;
  }

  if (_validator.IsVarName(op2) && !_vars.contains(op2)) {
    _err_stream << "Variable " << std::quoted(op2) << " does not exist" << std::endl;
    return;
  }

  if (_validator.IsVarName(op2)) {
    _out_stream << (_vars.at(op1) * _vars.at(op2)) << std::endl;
    return;
  }

  if (!_validator.IsNumber(op2)) {
    _err_stream << "Argument 2(" << std::quoted(op2) << ") must be a variable name or a double" << std::endl;
    return;
  }

  _out_stream << (_vars.at(op1) * std::stod(op2)) << std::endl;
}

void ComplexNumberHandler::HandlePrint(StringParser &parser) const {
  std::string op1 = parser.Next();

  if (!_validator.IsVarName(op1)) {
    _err_stream << "Argument 1(" << std::quoted(op1) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(op1)) {
    _err_stream << "Variable " << std::quoted(op1) << " does not exist" << std::endl;
    return;
  }

  _out_stream << _vars.at(op1) << std::endl;
}
