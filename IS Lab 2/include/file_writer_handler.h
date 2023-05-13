#ifndef IS_LAB_2_SRC_FILE_WRITER_HANDLER_H_
#define IS_LAB_2_SRC_FILE_WRITER_HANDLER_H_

#include "file_writer.h"
#include "string_parser.h"
#include "string_validator.h"

#include <unordered_map>
#include <string>
#include <ostream>

class FileWriterHandler {
 public:
  FileWriterHandler(
      std::ostream &out_stream,
      std::ostream &err_stream,
      StringValidator validator
  ) :
      _out_stream(out_stream),
      _err_stream(err_stream),
      _validator(std::move(validator)) {}

  void HandleCommand(StringParser &parser);

  void HandleCreate(StringParser &parser);

  void HandleOpen(StringParser &parser);

  void HandleClose(StringParser &parser);

  void HandleWriteString(StringParser &parser);

  void HandleWriteInteger(StringParser &parser);

  void HandleWriteDouble(StringParser &parser);

  void HandleGetPath(StringParser &parser) const;

  void HandleIsOpen(StringParser &parser) const;

 private:
  const StringValidator _validator;

  std::ostream &_out_stream;
  std::ostream &_err_stream;
  std::unordered_map<std::string, FileWriter> _vars;
};

#endif //IS_LAB_2_SRC_FILE_WRITER_HANDLER_H_
