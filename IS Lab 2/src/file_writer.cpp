#include "../include/file_writer.h"

FileWriter::FileWriter(const char *path) : _path(path), _out() {
  _out = fopen(path, "w");
}

bool FileWriter::Open(const char *path) {
  _path = path;
  _out = fopen(path, "w");

  return _out != nullptr;
}

bool FileWriter::Close() {
  bool result = fclose(_out) == 0;
  _out = nullptr;
  return result;
}

std::string FileWriter::FilePath() const {
  return _path;
}

bool FileWriter::IsOpen() const {
  return _out != nullptr;
}

bool FileWriter::WriteString(const char *str) {
  if (_out == nullptr) {
    return false;
  }

  return fprintf(_out, "%s\n", str) >= 0;
}

bool FileWriter::WriteInt(int number) {
  if (_out == nullptr) {
    return false;
  }

  return fprintf(_out, "%i\n", number) >= 0;
}

bool FileWriter::WriteDouble(double number) {
  if (_out == nullptr) {
    return false;
  }

  return fprintf(_out, "%f\n", number) >= 0;
}
