#include "../include/circular_buffer_iterator.h"

#define iterator CircularBufferIterator<ValueType, Pointer, Reference, DifferenceType, SizeType>

#define ADD_MODULO(x, y, m) (((long long)x + (long long)m + (long long)y % (long long)m) % (long long)m)

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator &iterator::operator=(const iterator &it) {
  if (this == &it) return *this;

  begin_ = it.begin_;
  pos_ = it.pos_;
  capacity_ = it.capacity_;

  return *this;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator &iterator::operator=(iterator &&it) noexcept {
  begin_ = it.begin_;
  pos_ = it.pos_;
  capacity_ = it.capacity_;

  return *this;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator &iterator::operator++() {
  pos_ = ADD_MODULO(pos_, 1, capacity_);
  return *this;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator iterator::operator++(int) { // NOLINT(cert-dcl21-cpp)
  iterator result = *this;
  pos_ = ADD_MODULO(pos_, 1, capacity_);
  return result;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator &iterator::operator--() {
  pos_ = ADD_MODULO(pos_, capacity_ - 1, capacity_);
  return *this;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator iterator::operator--(int) { // NOLINT(cert-dcl21-cpp)
  iterator result = *this;
  pos_ = ADD_MODULO(pos_, capacity_ - 1, capacity_);
  return result;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
typename iterator::reference iterator::operator*() {
  return *(begin_ + pos_);
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
typename iterator::pointer iterator::operator->() {
  return begin_ + pos_;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator iterator::operator+(int n) {
  iterator result = *this;
  result.pos_ = (result.pos_ + n) % result.capacity_;
  return result;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator operator+(int n, iterator &it) {
  iterator result = it;
  result.pos_ = ADD_MODULO(result.pos_, n, result.capacity_);
  return result;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator &iterator::operator+=(int n) {
  pos_ = ADD_MODULO(pos_, n, capacity_);
  return *this;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator iterator::operator-(int n) {
  iterator result = *this;
  result.pos_ = ADD_MODULO(result.pos_, -n, result.capacity_);
  return result;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
typename iterator::difference_type iterator::operator-(iterator it) {
  if (pos_ >= it.pos_) return pos_ - it.pos_;
  return pos_ + capacity_ - it.pos_;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
iterator &iterator::operator-=(int n) {
  pos_ = ADD_MODULO(pos_, -n, capacity_);
  return *this;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
typename iterator::reference iterator::operator[](int i) {
  return *(begin_ + ADD_MODULO(pos_, i, capacity_));
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
bool iterator::operator==(iterator it) {
  return begin_ + pos_ == it.begin_ + it.pos_;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
bool iterator::operator!=(iterator it) {
  return begin_ + pos_ != it.begin_ + it.pos_;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
bool iterator::operator<(iterator it) {
  if (pos_ >= head_ && it.pos_ >= it.head_) return begin_ + pos_ < it.begin_ + it.pos_;
  if (pos_ < head_ && it.pos_ < it.head_) return begin_ + pos_ < it.begin_ + it.pos_;
  if (pos_ >= head_) return true;
  return false;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
bool iterator::operator>(iterator it) {
  if (pos_ >= head_ && it.pos_ >= it.head_) return begin_ + pos_ > it.begin_ + it.pos_;
  if (pos_ < head_ && it.pos_ < it.head_) return begin_ + pos_ > it.begin_ + it.pos_;
  if (pos_ >= head_) return false;
  return true;
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
bool iterator::operator<=(iterator it) {
  return (*this == it) || (*this < it);
}

template<typename ValueType, typename Pointer, typename Reference, typename DifferenceType, typename SizeType>
bool iterator::operator>=(iterator it) {
  return (*this == it) || (*this > it);
}

#undef iterator

#undef ADD_MODULO
