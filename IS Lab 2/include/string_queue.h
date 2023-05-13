#ifndef IS_LAB_2_STRING_QUEUE_H
#define IS_LAB_2_STRING_QUEUE_H

#include <ostream>
#include <vector>
#include <string>

class StringQueue {
 public:
  StringQueue() : _capacity(10), _head(0), _tail(0), _elements(11) {}

  StringQueue(const StringQueue &queue) = default;

  explicit StringQueue(int capacity) : _capacity(capacity), _head(0), _tail(0), _elements(capacity + 1) {}

  [[nodiscard]] int Size() const;

  [[nodiscard]] std::string Front() const;

  [[nodiscard]] std::string Back() const;

  void Push(const std::string &element);

  std::string Pop();

 private:
  int _capacity;
  int _head;
  int _tail;
  std::vector<std::string> _elements;
};

std::ostream &operator<<(std::ostream &out, const StringQueue &queue);

#endif //IS_LAB_2_STRING_QUEUE_H
