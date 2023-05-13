#ifndef IS_LAB_7_INCLUDE_CIRCULAR_BUFFER_ITERATOR_H_
#define IS_LAB_7_INCLUDE_CIRCULAR_BUFFER_ITERATOR_H_

#include <iterator>

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
class CircularBufferIterator {
  template<typename ValueType_, typename Pointer_, typename Reference_, typename DifferenceType_, typename SizeType_>
  friend class CircularBufferIterator;

  typedef SizeType size_type;

 public:
  [[maybe_unused]] typedef std::random_access_iterator_tag iterator_category;
  [[maybe_unused]] typedef ValueType value_type;
  [[maybe_unused]] typedef DifferenceType difference_type;
  [[maybe_unused]] typedef Pointer pointer;
  [[maybe_unused]] typedef Reference reference;

  CircularBufferIterator(pointer begin, size_type head, size_type capacity, size_type pos) noexcept:
      begin_(begin),
      head_(head),
      capacity_(capacity),
      pos_(pos) {}

  template<class Ptr, class Rf>
  CircularBufferIterator(
      const CircularBufferIterator<value_type, Ptr, Rf, difference_type, size_type> &other
  ) :
      begin_(other.begin_),
      head_(other.head_),
      capacity_(other.capacity_),
      pos_(other.pos_) {};

  CircularBufferIterator(const CircularBufferIterator &other) = default;

  CircularBufferIterator(CircularBufferIterator &&other) noexcept = default;

  CircularBufferIterator &operator=(const CircularBufferIterator &);

  CircularBufferIterator &operator=(CircularBufferIterator &&) noexcept;

  CircularBufferIterator &operator++();

  CircularBufferIterator operator++(int); // NOLINT(cert-dcl21-cpp)

  CircularBufferIterator &operator--();

  CircularBufferIterator operator--(int); // NOLINT(cert-dcl21-cpp)

  reference operator*();

  pointer operator->();

  CircularBufferIterator operator+(int);

  CircularBufferIterator &operator+=(int);

  CircularBufferIterator operator-(int);

  difference_type operator-(CircularBufferIterator);

  CircularBufferIterator &operator-=(int);

  reference operator[](int i);

  bool operator==(CircularBufferIterator);

  bool operator!=(CircularBufferIterator);

  bool operator<(CircularBufferIterator);

  bool operator>(CircularBufferIterator);

  bool operator<=(CircularBufferIterator);

  bool operator>=(CircularBufferIterator);

 private:
  pointer begin_;
  size_type head_;
  size_type pos_;
  size_type capacity_;
};

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
CircularBufferIterator<ValueType, Pointer, Reference, DifferenceType, SizeType> operator+(
    int,
    CircularBufferIterator<ValueType, Pointer, Reference, DifferenceType, SizeType> &);

#include "../src/circular_buffer_iterator.cpp"

#endif //IS_LAB_7_INCLUDE_CIRCULAR_BUFFER_ITERATOR_H_
