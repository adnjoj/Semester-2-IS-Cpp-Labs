#ifndef IS_LAB_2_STRING_PARSER_H
#define IS_LAB_2_STRING_PARSER_H

#include <string>

class StringParser {
 public:
  StringParser(std::string str, std::string delimiter) : _s(std::move(str)), _delimiter(std::move(delimiter)) {}

  std::string Next(const std::string &delimiter = " ");

  std::string Rest();

 private:
  const std::string _delimiter;
  std::string _s;
};

#endif //IS_LAB_2_STRING_PARSER_H
