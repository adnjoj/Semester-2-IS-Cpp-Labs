#include "../include/int_queue.h"

#include <iostream>

void DumpQueue(const IntQueue &queue) {
  IntQueue copy = queue;

  int element;

  std::cout << "IntQueue { ";

  while (copy.Size() > 0) {
    copy >> element;
    std::cout << element << (copy.Size() > 0 ? ", " : "");
  }

  std::cout << " }" << std::endl;
}

void TestIntQueue() {
  std::cout << "Testing IntQueue class: " << std::endl << std::endl;

  IntQueue queue(10);

  for (int i = 0; i < 10; i++) {
    queue << i;

    assert(queue.Size() == i + 1 && queue.Back() == i);

    std::printf("    Passed test %i: push %i - ", i + 1, i);
    DumpQueue(queue);
  }

  for (int i = 9; i >= 0; i--) {
    int front;
    queue >> front;

    assert(queue.Size() == i && front == 9 - i);

    std::printf("    Passed test %i: pop - ", i);
    DumpQueue(queue);
  }

  std::cout << std::endl << "Passed all tests!" << std::endl;
}
