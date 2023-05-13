#include "../include/string_queue_handler.h"

#include <iomanip>

void StringQueueHandler::HandleCommand(StringParser &parser) {
  std::string command = parser.Next();

  if (command == "create") {
    HandleCreate(parser);
  } else if (command == "len") {
    HandleGetLength(parser);
  } else if (command == "front") {
    HandleGetFront(parser);
  } else if (command == "back") {
    HandleGetBack(parser);
  } else if (command == "push") {
    HandlePush(parser);
  } else if (command == "pop") {
    HandlePop(parser);
  } else if (command == "print") {
    HandlePrint(parser);
  } else {
    _err_stream << "Unsupported command for string queues " << std::quoted(command) << std::endl;
  }
}

void StringQueueHandler::HandleCreate(StringParser &parser) {
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
    _vars.insert_or_assign(var_name, StringQueue());
    return;
  }

  if (_validator.IsVarName(op1) && !_vars.contains(op1)) {
    _err_stream << "Variable " << std::quoted(op1) << " does not exist" << std::endl;
    return;
  }

  if (_validator.IsVarName(op1)) {
    _vars.insert_or_assign(var_name, StringQueue(_vars.at(op1)));
    return;
  }

  if (!_validator.IsNumber(op1)) {
    _err_stream << "Argument 2(" << std::quoted(op1) << ") must be a variable name or an integer" << std::endl;
    return;
  }

  _vars.insert_or_assign(var_name, StringQueue(std::stoi(op1)));
}

void StringQueueHandler::HandleGetLength(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << (_vars.at(var_name).Size()) << std::endl;
}

void StringQueueHandler::HandleGetFront(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << (_vars.at(var_name).Front()) << std::endl;
}

void StringQueueHandler::HandleGetBack(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << (_vars.at(var_name).Back()) << std::endl;
}

void StringQueueHandler::HandlePush(StringParser &parser) {
  std::string var_name = parser.Next();
  std::string op1 = parser.Rest();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _vars.at(var_name).Push(op1);
}

void StringQueueHandler::HandlePop(StringParser &parser) {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _vars.at(var_name).Pop();
}

void StringQueueHandler::HandlePrint(StringParser &parser) const {
  std::string var_name = parser.Next();

  if (!_validator.IsVarName(var_name)) {
    _err_stream << "Argument 1(" << std::quoted(var_name) << ") must be a valid variable name" << std::endl;
    return;
  }

  if (!_vars.contains(var_name)) {
    _err_stream << "Variable " << std::quoted(var_name) << " does not exist" << std::endl;
    return;
  }

  _out_stream << _vars.at(var_name) << std::endl;
}
