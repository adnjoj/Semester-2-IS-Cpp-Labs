#include "../include/file_writer_handler.h"

#include <iomanip>

void FileWriterHandler::HandleCommand(StringParser &parser) {
  std::string command = parser.Next();

  if (command == "create") {
    HandleCreate(parser);
  } else if (command == "open") {
    HandleOpen(parser);
  } else if (command == "close") {
    HandleClose(parser);
  } else if (command == "is_open") {
    HandleIsOpen(parser);
  } else if (command == "path") {
    HandleGetPath(parser);
  } else if (command == "write_s") {
    HandleWriteString(parser);
  } else if (command == "write_i") {
    HandleWriteInteger(parser);
  } else if (command == "write_d") {
    HandleWriteDouble(parser);
  } else {
    _err_stream << "Unsupported command for file writers " << std::quoted(command) << std::endl;
  }
}

void FileWriterHandler::HandleCreate(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string op1 = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " already exists" << std::endl;
    return;
  }

  if (op1.empty()) {
    _vars.insert_or_assign(var_name, FileWriter());
    return;
  }

  _vars.insert_or_assign(var_name, FileWriter(op1.c_str()));
}

void FileWriterHandler::HandleOpen(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string path = parser.Rest();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  if (path.empty()) {
    _err_stream << "Argument 2(" << std::quoted(path) << ") must be a valid path to a file" << std::endl;
    return;
  }

  _vars.at(var_name).Open(path.c_str());
}

void FileWriterHandler::HandleClose(StringParser &parser) {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _vars.at(var_name).Close();
}

void FileWriterHandler::HandleGetPath(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << std::string(_vars.at(var_name).FilePath()) << std::endl;
}

void FileWriterHandler::HandleIsOpen(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << (_vars.at(var_name).IsOpen() ? "yes" : "no") << std::endl;
}

void FileWriterHandler::HandleWriteString(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string str = parser.Rest();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _vars.at(var_name).WriteString(str.c_str());
}

void FileWriterHandler::HandleWriteInteger(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string number = parser.Rest();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  if (!_validator.IsNumber(number)) {
    _err_stream << "Argument 2(" << std::quoted(number) << ") must be an integer" << std::endl;
    return;
  }

  _vars.at(var_name).WriteInt(std::stoi(number));
}

void FileWriterHandler::HandleWriteDouble(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string number = parser.Rest();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  if (!_validator.IsNumber(number)) {
    _err_stream << "Argument 2(" << std::quoted(number) << ") must be a double" << std::endl;
    return;
  }

  _vars.at(var_name).WriteDouble(std::stod(number));
}
