#include "include/circular_buffer.h"

#include <iostream>

using namespace std;

template<class Ostream, class Container>
Ostream &operator<<(Ostream &stream, const Container &container) {
  stream << "{";
  for (auto const &el : container) stream << " " << el;
  return stream << " } ";
}

int main() {
  CircularBuffer<int> a1{1, 2, 3}, a2{4, 5};

  a1.insert(a1.begin() + 2, 5);
  a1.insert(a1.begin() + 2, 6);
  a1.insert(a1.begin() + 2, 7);

  a1.insert(a1.begin() + 2, 8);
  a1.insert(a1.begin() + 2, 9);

  auto it1 = std::next(a1.begin());
  auto it2 = std::next(a2.begin());

  int &ref1 = a1.front();
  int &ref2 = a2.front();

  std::cout << a1 << a2 << *it1 << " " << *it2 << " " << ref1 << " " << ref2 << "\n";
  a1.swap(a2);
  std::cout << a1 << a2 << *it1 << " " << *it2 << " " << ref1 << " " << ref2 << "\n";

  a2.erase(std::remove_if(a2.begin(), a2.end(), [](auto &el) { return el > 7; }), a2.end());

  std::cout << a2 << '\n';

  std::sort(a2.begin(), a2.end());

  std::cout << a2 << '\n';

  return 0;
}
