#ifndef IS_LAB_2_INCLUDE_STRING_QUEUE_HANDLER_H_
#define IS_LAB_2_INCLUDE_STRING_QUEUE_HANDLER_H_

#include "string_queue.h"
#include "string_parser.h"
#include "string_validator.h"

#include <unordered_map>
#include <string>
#include <ostream>

class StringQueueHandler {
 public:
  StringQueueHandler(
      std::ostream &out_stream,
      std::ostream &err_stream,
      StringValidator validator
  ) :
      _out_stream(out_stream),
      _err_stream(err_stream),
      _validator(std::move(validator)) {}

  void HandleCommand(StringParser &parser);

  void HandleCreate(StringParser &parser);

  void HandleGetLength(StringParser &parser) const;

  void HandleGetFront(StringParser &parser) const;

  void HandleGetBack(StringParser &parser) const;

  void HandlePush(StringParser &parser);

  void HandlePop(StringParser &parser);

  void HandlePrint(StringParser &parser) const;

 private:
  const StringValidator _validator;

  std::ostream &_out_stream;
  std::ostream &_err_stream;
  std::unordered_map<std::string, StringQueue> _vars;
};

#endif //IS_LAB_2_INCLUDE_STRING_QUEUE_HANDLER_H_
