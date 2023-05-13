#include "../include/string_parser.h"

std::string StringParser::Next(const std::string &delimiter) {
  const std::string d = delimiter.empty() ? _delimiter : delimiter;

  size_t pos = _s.find(d);

  if (pos == -1) {
    return Rest();
  }

  std::string result = _s.substr(0, pos);
  _s = pos + d.length() >= _s.length() ? "" : _s.substr(pos + d.length());

  while (!d.empty() && _s.find(d) == 0) {
    _s = d.length() >= _s.length() ? "" : _s.substr(d.length());
  }

  return result;
}

std::string StringParser::Rest() {
  std::string result = _s;
  _s = "";
  return result;
}
