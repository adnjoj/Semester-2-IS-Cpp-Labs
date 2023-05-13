#ifndef IS_LAB_6_ALGORITHMS_H_
#define IS_LAB_6_ALGORITHMS_H_

template<typename IterType, typename Predicate>
bool my_none_of(IterType begin, IterType end, Predicate predicate) {
  IterType it = begin;

  while (it != end) {
    if (predicate(*(it++))) return false;
  }

  return true;
}

template<typename IterType, typename Predicate>
bool my_is_sorted(IterType begin, IterType end, Predicate sorted) {
  IterType it = begin;
  IterType prev = it++;

  while (prev != end && it != end) {
    if (!sorted(*(prev++), *(it++))) return false;
  }

  return true;
}

template<typename T, typename IterType, typename Predicate>
bool find_not(IterType begin, IterType end, Predicate predicate, T *out) {
  IterType it = begin;

  while (it != end) {
    if (!predicate(*it)) {
      *out = *it;
      return true;
    }

    it++;
  }

  return false;
}

#endif //IS_LAB_6_ALGORITHMS_H_
