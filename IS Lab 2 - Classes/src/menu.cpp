#include "../include/menu.h"

#include <iostream>

void Menu::HandleCommand(const std::string &command) {
  StringParser parser(command, " ");

  std::string data_structure = parser.Next(" ");

  if (data_structure == "complex") {
    _complex_number_handler.HandleCommand(parser);
  } else if (data_structure == "queue") {
    _string_queue_handler.HandleCommand(parser);
  } else if (data_structure == "fw") {
    _file_writer_handler.HandleCommand(parser);
  } else {
    _err_stream << "Incorrect data structure: complex, queue or fw expected" << std::endl;
  }
}
