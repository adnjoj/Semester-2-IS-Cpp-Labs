#include "../include/string_queue.h"

#include <ostream>
#include <iomanip>

std::ostream &operator<<(std::ostream &out, const StringQueue &queue) {
  StringQueue copy = queue;

  out << "StringQueue { ";

  int i = 0;
  while (copy.Size() > 0) {
    if (i++ > 0) {
      out << ", ";
    }

    out << std::quoted(copy.Front());
    copy.Pop();
  }

  out << " }";

  return out;
}

int StringQueue::Size() const {
  if (_tail < _head) {
    return _tail + (_capacity - _head);
  }

  return _tail - _head;
}

void StringQueue::Push(const std::string &element) {
  assert(Size() < _capacity);

  _elements[_tail] = element;
  _tail = (_tail + 1) % (_capacity + 1);
}

std::string StringQueue::Pop() {
  assert(Size() > 0);

  std::string result = _elements[_head];
  _head = (_head + 1) % (_capacity + 1);
  return result;
}

std::string StringQueue::Front() const {
  assert(Size() > 0);

  return _elements[_head];
}

std::string StringQueue::Back() const {
  assert(Size() > 0);

  return _elements[(_tail + _capacity) % (_capacity + 1)];
}
