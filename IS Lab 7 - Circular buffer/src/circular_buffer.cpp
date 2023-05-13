#include "../include/circular_buffer.h"

static const size_t DEFAULT_CAPACITY = 0;

template<class T, class Allocator>
CircularBuffer<T, Allocator>::CircularBuffer() :
    CircularBuffer(std::allocator<T>()) {}

template<class T, class Allocator>
CircularBuffer<T, Allocator>::CircularBuffer(const Allocator &alloc) :
    CircularBuffer(DEFAULT_CAPACITY, alloc) {}

template<class T, class Allocator>
CircularBuffer<T, Allocator>::CircularBuffer(size_t count, const Allocator &alloc) :
    capacity_(count + 1),
    head_(0),
    tail_(count),
    allocator_(alloc) {
  elements_ = allocator_.allocate(capacity_);
}

template<class T, class Allocator>
CircularBuffer<T, Allocator>::CircularBuffer(size_t count, const T &value, const Allocator &alloc) :
    CircularBuffer(count, alloc) {
  for (int i = 0; i < capacity_; i++) {
    elements_[i] = value;
  }
}

template<class T, class Allocator>
template<class InputIt>
CircularBuffer<T, Allocator>::CircularBuffer(InputIt first, InputIt last, const Allocator &alloc) :
    CircularBuffer(std::distance(first, last), alloc) {
  int i = 0;
  for (InputIt it = first; it != last; it++) {
    elements_[i++] = *it;
  }
}

template<class T, class Allocator>
CircularBuffer<T, Allocator>::CircularBuffer(const CircularBuffer &other) :
    CircularBuffer(other.begin(), other.end()) {}

template<class T, class Allocator>
CircularBuffer<T, Allocator>::CircularBuffer(const CircularBuffer &other, const Allocator &alloc) :
    CircularBuffer(other.begin(), other.end(), alloc) {}

template<class T, class Allocator>
CircularBuffer<T, Allocator>::CircularBuffer(CircularBuffer &&other, const Allocator &alloc) {
  capacity_ = other.capacity_;
  head_ = other.head_;
  tail_ = other.tail_;
  allocator_ = alloc;

  if (allocator_ == other.allocator_) {
    elements_ = other.elements_;
  } else {
    elements_ = allocator_.allocate(capacity_);
    std::memcpy(elements_, other.elements_, capacity_ * sizeof(value_type));
  }
}

template<class T, class Allocator>
CircularBuffer<T, Allocator>::CircularBuffer(std::initializer_list<T> initializer_list, const Allocator &alloc) :
    CircularBuffer(initializer_list.begin(), initializer_list.end(), alloc) {}

template<class T, class Allocator>
CircularBuffer<T, Allocator>::~CircularBuffer() {
  allocator_.deallocate(elements_, capacity_);
}

template<class T, class Allocator>
CircularBuffer<T, Allocator> &CircularBuffer<T, Allocator>::operator=(const CircularBuffer<T, Allocator> &other) {
  if (this != &other) assign(other.begin(), other.end());
  return *this;
}

template<class T, class Allocator>
CircularBuffer<T, Allocator> &CircularBuffer<T, Allocator>::operator=(CircularBuffer<T, Allocator> &&other) noexcept {
  capacity_ = other.capacity_;
  head_ = other.head_;
  tail_ = other.tail_;
  elements_ = other.elements_;
  allocator_ = other.allocator_;

  return *this;
}

template<class T, class Allocator>
CircularBuffer<T, Allocator> &CircularBuffer<T, Allocator>::operator=(std::initializer_list<T> initializer_list) {
  assign(initializer_list.begin(), initializer_list.end());
  return *this;
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::assign(size_type count, const T &value) {

  if (!EnoughCapacity(count)) ReCreateBuffer(count);

  for (; tail_ < count; tail_++) {
    elements_[tail_] = value;
  }
}

template<class T, class Allocator>
template<class InputIt>
void CircularBuffer<T, Allocator>::assign(InputIt first, InputIt last) {
  difference_type required_capacity = std::distance(first, last);

  if (!EnoughCapacity(required_capacity)) ReCreateBuffer(required_capacity);

  for (InputIt it = first; it != last; it++) {
    elements_[tail_++] = *it;
  }
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::assign(std::initializer_list<T> initializer_list) {
  assign(initializer_list.begin(), initializer_list.end());
}

template<class T, class Allocator>
Allocator CircularBuffer<T, Allocator>::get_allocator() const noexcept {
  return allocator_;
}

/* Elements access */
template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::reference CircularBuffer<T, Allocator>::at(size_type pos) {
  if (pos >= size()) throw std::out_of_range("Circular buffer index is out of range");
  return elements_[ADD_MODULO(head_, pos, capacity_)];
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_reference CircularBuffer<T, Allocator>::at(size_type pos) const {
  if (pos >= size()) throw std::out_of_range("Circular buffer index is out of range");
  return elements_[ADD_MODULO(head_, pos, capacity_)];
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::reference CircularBuffer<T, Allocator>::operator[](size_type pos) {
  return at(pos);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_reference CircularBuffer<T, Allocator>::operator[](size_type pos) const {
  return at(pos);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::reference CircularBuffer<T, Allocator>::front() {
  return elements_[head_];
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_reference CircularBuffer<T, Allocator>::front() const {
  return elements_[head_];
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::reference CircularBuffer<T, Allocator>::back() {
  return elements_[tail_];
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_reference CircularBuffer<T, Allocator>::back() const {
  return elements_[tail_];
}

/* Iterators */
template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::begin() noexcept {
  return iterator(elements_, head_, capacity_, head_);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_iterator CircularBuffer<T, Allocator>::begin() const noexcept {
  return iterator(elements_, head_, capacity_, head_);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_iterator CircularBuffer<T, Allocator>::cbegin() const noexcept {
  return iterator(elements_, head_, capacity_, head_);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::end() noexcept {
  return iterator(elements_, head_, capacity_, tail_);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_iterator CircularBuffer<T, Allocator>::end() const noexcept {
  return iterator(elements_, head_, capacity_, tail_);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_iterator CircularBuffer<T, Allocator>::cend() const noexcept {
  return iterator(elements_, head_, capacity_, tail_);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::rbegin() noexcept {
  return std::make_reverse_iterator(end());
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_iterator CircularBuffer<T, Allocator>::rbegin() const noexcept {
  return std::make_reverse_iterator(cend());
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_iterator CircularBuffer<T, Allocator>::crbegin() const noexcept {
  return std::make_reverse_iterator(cend());
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::rend() noexcept {
  return std::make_reverse_iterator(begin());
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_iterator CircularBuffer<T, Allocator>::rend() const noexcept {
  return std::make_reverse_iterator(cbegin());
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::const_iterator CircularBuffer<T, Allocator>::crend() const noexcept {
  return std::make_reverse_iterator(cbegin());
}

/* Capacity */
template<class T, class Allocator>
bool CircularBuffer<T, Allocator>::empty() const noexcept {
  return head_ == tail_;
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::size_type CircularBuffer<T, Allocator>::size() const noexcept {
  if (head_ <= tail_) return tail_ - head_;
  return capacity_ - head_ + tail_;
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::size_type CircularBuffer<T, Allocator>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max();
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::shrink_to_fit() {
  ResizeBuffer(size());
}

/* Modifiers */
template<class T, class Allocator>
void CircularBuffer<T, Allocator>::clear() noexcept {
  head_ = 0;
  tail_ = 0;
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::insert(
    const_iterator pos,
    const T &value
) {
  return insert(pos, 1, value);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::insert(
    const_iterator pos,
    T &&value
) {
  return insert(pos, 1, value);
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::insert(
    const_iterator pos,
    size_type count,
    const T &value
) {
  difference_type relative_pos = pos - begin();

  MakeWindow(relative_pos, count);

  iterator it = begin() + relative_pos;

  for (int i = 0; i < count; i++) {
    *it++ = value;
  }

  return begin() + relative_pos;
}

template<class T, class Allocator>
template<class InputIt>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::insert(
    const_iterator pos,
    InputIt first,
    InputIt last,
    typename std::enable_if<std::__is_cpp17_input_iterator<InputIt>::value>::type *
) {
  difference_type relative_pos = pos - begin();
  difference_type count = std::distance(first, last);

  MakeWindow(relative_pos, count);

  iterator it = begin() + relative_pos;

  for (int i = 0; i < count; i++) {
    *it++ = *first++;
  }

  return begin() + relative_pos;
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::insert(
    CircularBuffer::const_iterator pos,
    std::initializer_list<T> initializer_list
) {
  return insert(pos, initializer_list.begin(), initializer_list.end());
}

template<class T, class Allocator>
template<class ...Args>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::emplace(
    const_iterator pos,
    Args &&... args
) {
  return insert(pos, T(args...));
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::erase(const_iterator pos) {
  difference_type relative_pos = pos - begin();

  std::allocator_traits<allocator_type>::destroy(allocator_, elements_ + (head_ + relative_pos) % capacity_);

  if (pos <= begin() + size() / 2) {
    for (iterator it = begin() + relative_pos; it != begin(); it--) *it = *(it - 1);
    head_ = ADD_MODULO(head_, 1, capacity_);
  } else {
    for (iterator it = begin() + relative_pos; it != end(); it++) *it = *(it + 1);
    tail_ = ADD_MODULO(tail_, -1, capacity_);
  }

  return begin() + relative_pos;
}

template<class T, class Allocator>
typename CircularBuffer<T, Allocator>::iterator CircularBuffer<T, Allocator>::erase(
    const_iterator first,
    const_iterator last
) {
  difference_type relative_first = first - begin();
  difference_type relative_last = last - begin();
  difference_type range_length = last - first;

  for (int i = 0; i < range_length; i++) {
    std::allocator_traits<allocator_type>::destroy(
        allocator_,
        elements_ + ADD_MODULO(head_, relative_first + i, capacity_));
  }

  if (relative_first <= cend() - last) {
    for (iterator it = begin() + relative_last - 1; it >= begin() + range_length; it--) *it = *(it - range_length);
    head_ = ADD_MODULO(head_, range_length, capacity_);
  } else {
    for (iterator it = begin() + relative_first; it < end() - range_length; it++) *it = *(it + range_length);
    tail_ = ADD_MODULO(tail_, -range_length, capacity_);
  }

  return begin() + relative_first;
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::push_back(const T &value) {
  insert(end(), value);
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::push_back(T &&value) {
  insert(end(), value);
}

template<class T, class Allocator>
template<class ...Args>
typename CircularBuffer<T, Allocator>::reference CircularBuffer<T, Allocator>::emplace_back(Args &&...args) {
  return *emplace(end(), args...);
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::pop_back() {
  erase(end() - 1);
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::push_front(const T &value) {
  insert(begin(), value);
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::push_front(T &&value) {
  insert(begin(), value);
}

template<class T, class Allocator>
template<class ...Args>
typename CircularBuffer<T, Allocator>::reference CircularBuffer<T, Allocator>::emplace_front(Args &&... args) {
  return *emplace(begin(), args...);
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::pop_front() {
  erase(begin());
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::resize(size_type count) {
  if (count == size()) return;
  ResizeBuffer(count);
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::resize(size_type count, const value_type &value) {
  if (count == size()) return;
  ResizeBuffer(count);

  if (size() > count) return;

  for (int i = 0; i < count - size(); i++) {
    elements_[ADD_MODULO(tail_, i, capacity_)] = value;
  }
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::swap(CircularBuffer<T, Allocator> &other) noexcept {
  struct {
    size_type capacity, head, tail;
    value_type *elements;
    allocator_type allocator;
  } tmp = {other.capacity_, other.head_, other.tail_, other.elements_, other.allocator_};

  other = std::move(*this);

  capacity_ = tmp.capacity;
  head_ = tmp.head;
  tail_ = tmp.tail;
  elements_ = tmp.elements;
  allocator_ = tmp.allocator;
}

/* Private */
template<class T, class Allocator>
bool CircularBuffer<T, Allocator>::EnoughCapacity(size_type size) const {
  return capacity_ >= size + 1;
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::ReCreateBuffer(size_type size) {
  T *new_elements = allocator_.allocate(size + 1);
  allocator_.deallocate(elements_, capacity_);

  elements_ = new_elements;
  capacity_ = size + 1;

  head_ = 0;
  tail_ = 0;
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::ResizeBuffer(size_type size) {
  size_type elements_count = this->size();
  size_type new_size = size + 1;

  T *new_elements = allocator_.allocate(new_size);

  if (head_ <= tail_) {
    for (int i = 0; i < std::min(new_size, tail_ - head_); i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + i,
                                                       *(elements_ + head_ + i));
    }
  } else {
    for (int i = 0; i < std::min(new_size, capacity_ - head_); i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + i,
                                                       *(elements_ + head_ + i));
    }

    for (int i = 0; i < std::min(new_size + tail_ - head_, tail_); i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + (capacity_ - head_) + i,
                                                       *(elements_ + i));
    }
  }

  allocator_.deallocate(elements_, capacity_);

  elements_ = new_elements;
  capacity_ = new_size;

  head_ = 0;
  tail_ = elements_count;
}

template<class T, class Allocator>
void CircularBuffer<T, Allocator>::MakeWindow(size_type pos, size_type window_size) {
  size_type elements_count = this->size();

  if (begin() + pos > end()) throw std::out_of_range("Insert index is out of range");

  if (EnoughCapacity(elements_count + window_size)) {
    if (pos <= elements_count / 2) {
      for (iterator it = begin(); it != begin() + pos; it++) *(it - window_size) = *it;
      head_ = ADD_MODULO(head_, -window_size, capacity_);
    } else {
      for (iterator it = end() - 1; it >= begin() + pos; it++) *(it + window_size) = *it;
      tail_ = ADD_MODULO(tail_, window_size, capacity_);
    }

    return;
  }

  size_type new_size = (elements_count + window_size) * 2 + 1;

  T *new_elements = allocator_.allocate(new_size);

  if (head_ <= tail_) {
    for (int i = 0; i < pos; i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + i,
                                                       *(elements_ + head_ + i));
    }

    for (int i = 0; i < tail_ - head_ - pos; i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + pos + window_size + i,
                                                       *(elements_ + head_ + pos + i));
    }
  } else if (pos < capacity_ - head_) {
    for (int i = 0; i < pos; i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + i,
                                                       *(elements_ + head_ + i));
    }

    for (int i = 0; i < capacity_ - head_ - pos; i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + pos + window_size + i,
                                                       *(elements_ + head_ + pos + i));
    }

    for (int i = 0; i < tail_; i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + (capacity_ - head_) + window_size + i,
                                                       *(elements_ + i));
    }
  } else {
    pos -= capacity_ - head_;

    for (int i = 0; i < capacity_ - head_; i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + i,
                                                       *(elements_ + head_ + i));
    }

    for (int i = 0; i < pos; i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + (capacity_ - head_) + i,
                                                       *(elements_ + i));
    }

    for (int i = 0; i < tail_ - pos; i++) {
      std::allocator_traits<allocator_type>::construct(allocator_,
                                                       new_elements + (capacity_ - head_) + pos + i,
                                                       *(elements_ + pos + i));
    }
  }

  allocator_.deallocate(elements_, capacity_);

  elements_ = new_elements;
  capacity_ = new_size;

  head_ = 0;
  tail_ = elements_count + window_size;
}
