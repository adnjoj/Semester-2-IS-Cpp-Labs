#ifndef IS_LAB_2_MENU_H
#define IS_LAB_2_MENU_H

#include "complex_number.h"
#include "string_queue.h"
#include "file_writer.h"
#include "string_parser.h"
#include "complex_number_handler.h"
#include "string_queue_handler.h"
#include "file_writer_handler.h"

#include <string>
#include <unordered_map>

class Menu {
 public:
  Menu(std::ostream &out_stream, std::ostream &err_stream) :
      _err_stream(err_stream),
      _complex_number_handler(out_stream, err_stream, StringValidator()),
      _string_queue_handler(out_stream, err_stream, StringValidator()),
      _file_writer_handler(out_stream, err_stream, StringValidator()) {}

  void HandleCommand(const std::string &command);

 private:
  ComplexNumberHandler _complex_number_handler;
  StringQueueHandler _string_queue_handler;
  FileWriterHandler _file_writer_handler;

  std::ostream &_err_stream;
};

#endif //IS_LAB_2_MENU_H
