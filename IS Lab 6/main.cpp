#include "algorithms.h"

#include <iostream>
#include <vector>

class CRational {
 public:
  int numerator;
  unsigned denominator;

  CRational(int p, unsigned q) : numerator(p), denominator(q) {}

  bool operator==(CRational r) const {
    return (double) numerator / (double) denominator == (double) r.numerator / (double) r.denominator;
  }

  bool operator!=(CRational r) const {
    return !(*this == r);
  }

  bool operator<(CRational r) const {
    return (double) numerator / (double) denominator < (double) r.numerator / (double) r.denominator;
  }

  bool operator<=(CRational r) const {
    return *this < r || *this == r;
  }

  bool operator>(CRational r) const {
    return !(*this <= r);
  }

  bool operator>=(CRational r) const {
    return *this > r || *this == r;
  }
};

bool pred1_int(int a) {
  return a > 10;
}

bool comp_int(int a, int b) {
  return a < b;
}

bool pred2_int(int a) {
  return a < 2;
}

bool pred1_rat(CRational a) {
  return a > CRational{10, 1};
}

bool comp_rat(CRational a, CRational b) {
  return a < b;
}

bool pred2_rat(CRational a) {
  return a < CRational{4, 6};
}

int main() {
  std::cout << "Integers:" << std::endl;

  std::vector<int> v1 = {1, 2, 3};
  int first_int;
  bool found_int = find_not(v1.begin(), v1.end(), pred2_int, &first_int);

  std::cout << (my_none_of(v1.begin(), v1.end(), pred1_int) ? "None of" : "One of") << std::endl;
  std::cout << (my_is_sorted(v1.begin(), v1.end(), comp_int) ? "Sorted" : "Not sorted") << std::endl;
  std::cout << (found_int ? "Found " : "Not found ");
  if (found_int) std::cout << first_int << std::endl;

  std::cout << std::endl << "CRational:" << std::endl;

  std::vector<CRational> v2 = {CRational{21, 2}, CRational{2, 3}, CRational{3, 4}};
  CRational first_rat{0, 0};
  bool found_rat = find_not(v2.begin(), v2.end(), pred2_rat, &first_rat);

  std::cout << (my_none_of(v2.begin(), v2.end(), pred1_rat) ? "None of" : "One of") << std::endl;
  std::cout << (my_is_sorted(v2.begin(), v2.end(), comp_rat) ? "Sorted" : "Not sorted") << std::endl;
  std::cout << (found_rat ? "Found " : "Not found ");
  if (found_rat) std::cout << first_rat.numerator << " / " << first_rat.denominator << std::endl;

  return 0;
}
