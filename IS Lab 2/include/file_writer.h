#ifndef IS_LAB_2_FILE_WRITER_H
#define IS_LAB_2_FILE_WRITER_H

#include <string>
#include <fstream>

class FileWriter {
 public:
  FileWriter() : _path(), _out() {}

  explicit FileWriter(const char *path);

  bool Open(const char *file_name);

  bool Close();

  [[nodiscard]] std::string FilePath() const;

  [[nodiscard]] bool IsOpen() const;

  bool WriteString(const char *str);

  bool WriteInt(int number);

  bool WriteDouble(double number);

 private:
  FILE *_out;
  std::string _path;
};

#endif //IS_LAB_2_FILE_WRITER_H
