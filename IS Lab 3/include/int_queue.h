#ifndef IS_LAB_3_INT_QUEUE_H
#define IS_LAB_3_INT_QUEUE_H

#include <vector>
#include <string>

class IntQueue {
 public:
  IntQueue(const IntQueue &queue) = default;

  explicit IntQueue(int capacity) : _capacity(capacity + 1), _head(0), _tail(0), _elements(capacity + 1) {}

  IntQueue &operator<<(int value);

  IntQueue &operator>>(int &out);

  [[nodiscard]] int Size() const;

  [[nodiscard]] int Back() const;

 private:
  int _capacity;
  int _head;
  int _tail;
  std::vector<int> _elements;
};

#endif //IS_LAB_3_INT_QUEUE_H
