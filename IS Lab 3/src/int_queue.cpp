#include "../include/int_queue.h"

int IntQueue::Size() const {
  if (_tail < _head) {
    return _tail + _capacity - _head;
  }

  return _tail - _head;
}

int IntQueue::Back() const {
  assert(Size() > 0);

  return _elements[(_tail - 1 + _capacity) % _capacity];
}

IntQueue &IntQueue::operator<<(int value) {
  assert(Size() < _elements.size());

  _elements[_tail] = value;
  _tail = (_tail + 1) % _capacity;
  return *this;
}

IntQueue &IntQueue::operator>>(int &out) {
  assert(Size() > 0);

  out = _elements[_head];
  _head = (_head + 1) % _capacity;
  return *this;
}
