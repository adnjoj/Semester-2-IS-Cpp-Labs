#ifndef IS_LAB_7_INCLUDE_CIRCULAR_BUFFER_H_
#define IS_LAB_7_INCLUDE_CIRCULAR_BUFFER_H_

#include "circular_buffer_iterator.h"

#include <cstddef>
#include <initializer_list>
#include <memory>

#define ADD_MODULO(x, y, m) (((long long)x + (long long)m + (long long)y % (long long)m) % (long long)m)

template<class T, class Allocator = std::allocator<T>>
class CircularBuffer {
 public:
  [[maybe_unused]] typedef T value_type;
  [[maybe_unused]] typedef Allocator allocator_type;
  [[maybe_unused]] typedef size_t size_type;
  [[maybe_unused]] typedef ptrdiff_t difference_type;

  [[maybe_unused]] typedef value_type &reference;
  [[maybe_unused]] typedef const value_type &const_reference;

  [[maybe_unused]] typedef typename std::allocator_traits<Allocator>::pointer pointer;
  [[maybe_unused]] typedef typename std::allocator_traits<Allocator>::const_pointer const_pointer;

  [[maybe_unused]] typedef CircularBufferIterator<value_type, pointer, reference,
                                                  difference_type, size_type> iterator;
  [[maybe_unused]] typedef CircularBufferIterator<value_type, const_pointer, const_reference,
                                                  difference_type, size_type> const_iterator;

  [[maybe_unused]] typedef std::reverse_iterator<iterator> reverse_iterator;
  [[maybe_unused]] typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  CircularBuffer();

  explicit CircularBuffer(const Allocator &alloc);

  explicit CircularBuffer(size_type count, const Allocator &alloc = Allocator());

  CircularBuffer(size_type count, const T &value, const Allocator &alloc = Allocator());

  template<class InputIt>
  CircularBuffer(InputIt first, InputIt last, const Allocator &alloc = Allocator());

  CircularBuffer(const CircularBuffer &other);

  CircularBuffer(const CircularBuffer &other, const Allocator &alloc);

  CircularBuffer(CircularBuffer &&other) noexcept = default;

  CircularBuffer(CircularBuffer &&other, const Allocator &alloc);

  CircularBuffer(std::initializer_list<T> initializer_list, const Allocator &alloc = Allocator());

  ~CircularBuffer();

  CircularBuffer &operator=(const CircularBuffer &other);

  CircularBuffer &operator=(CircularBuffer &&other) noexcept;

  CircularBuffer &operator=(std::initializer_list<T> initializer_list);

  [[maybe_unused]] void assign(size_type count, const T &value);

  template<class InputIt>
  [[maybe_unused]] void assign(InputIt first, InputIt last);

  [[maybe_unused]] void assign(std::initializer_list<T> initializer_list);

  [[maybe_unused]] Allocator get_allocator() const noexcept;

  /* Element access */
  [[maybe_unused]] reference at(size_type pos);

  [[maybe_unused]] const_reference at(size_type pos) const;

  [[maybe_unused]] reference operator[](size_type pos);

  [[maybe_unused]] const_reference operator[](size_type pos) const;

  [[nodiscard, maybe_unused]] reference front();

  [[nodiscard, maybe_unused]] const_reference front() const;

  [[nodiscard, maybe_unused]] reference back();

  [[nodiscard, maybe_unused]] const_reference back() const;

  /* Iterators */
  [[nodiscard, maybe_unused]] iterator begin() noexcept;

  [[nodiscard, maybe_unused]] const_iterator begin() const noexcept;

  [[nodiscard, maybe_unused]] const_iterator cbegin() const noexcept;

  [[nodiscard, maybe_unused]] iterator end() noexcept;

  [[nodiscard, maybe_unused]] const_iterator end() const noexcept;

  [[nodiscard, maybe_unused]] const_iterator cend() const noexcept;

  [[nodiscard, maybe_unused]] iterator rbegin() noexcept;

  [[nodiscard, maybe_unused]] const_iterator rbegin() const noexcept;

  [[nodiscard, maybe_unused]] const_iterator crbegin() const noexcept;

  [[nodiscard, maybe_unused]] iterator rend() noexcept;

  [[nodiscard, maybe_unused]] const_iterator rend() const noexcept;

  [[nodiscard, maybe_unused]] const_iterator crend() const noexcept;

  /* Capacity */
  [[nodiscard, maybe_unused]] bool empty() const noexcept;

  [[nodiscard, maybe_unused]] size_type size() const noexcept;

  [[nodiscard, maybe_unused]] size_type max_size() const noexcept;

  [[maybe_unused]] void shrink_to_fit();

  /* Modifiers */
  [[maybe_unused]] void clear() noexcept;

  [[maybe_unused]] iterator insert(const_iterator pos, const T &value);

  [[maybe_unused]] iterator insert(const_iterator pos, T &&value);

  [[maybe_unused]] iterator insert(const_iterator pos, size_type count, const T &value);

  template<class InputIt>
  [[maybe_unused]] iterator insert(
      const_iterator pos,
      InputIt first,
      InputIt last,
      typename std::enable_if<std::__is_cpp17_input_iterator<InputIt>::value>::type * = 0
  );

  [[maybe_unused]] iterator insert(const_iterator pos, std::initializer_list<T> initializer_list);

  template<class... Args>
  [[maybe_unused]] iterator emplace(const_iterator pos, Args &&... args);

  [[maybe_unused]] iterator erase(const_iterator pos);

  [[maybe_unused]] iterator erase(const_iterator first, const_iterator last);

  [[maybe_unused]] void push_back(const T &value);

  [[maybe_unused]] void push_back(T &&value);

  template<class... Args>
  [[maybe_unused]] reference emplace_back(Args &&... args);

  [[maybe_unused]] void pop_back();

  [[maybe_unused]] void push_front(const T &value);

  [[maybe_unused]] void push_front(T &&value);

  template<class... Args>
  [[maybe_unused]] reference emplace_front(Args &&... args);

  [[maybe_unused]] void pop_front();

  [[maybe_unused]] void resize(size_type count);

  [[maybe_unused]] void resize(size_type count, const value_type &value);

  [[maybe_unused]] void swap(CircularBuffer &other) noexcept;

 private:
  size_type capacity_;
  size_type head_;
  size_type tail_;

  value_type *elements_;

  allocator_type allocator_;

  [[nodiscard]] bool EnoughCapacity(size_type size) const;

  void ReCreateBuffer(size_type size);

  void ResizeBuffer(size_type size);

  void MakeWindow(size_type pos, size_type window_size);
};

#include "../src/circular_buffer.cpp"

#endif //IS_LAB_7_INCLUDE_CIRCULAR_BUFFER_H_
