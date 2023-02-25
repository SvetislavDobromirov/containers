#ifndef __SRC_S21_VECTOR_H__
#define __SRC_S21_VECTOR_H__

#define print cout
typedef unsigned long size_t;
#include <initializer_list>

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdio.h>

namespace s21 {
template <class T> class vector {
public:
  // members types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Constrictors and destructors
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &other);
  vector(vector &&v);
  ~vector();
  vector &operator=(vector &&other);

  // методы вызова // vector Element Access
  reference operator[](size_type index);
  reference at(size_type index);
  const_reference front() noexcept;
  const_reference back() noexcept;
  T *data() noexcept;

  void push_back(const_reference new_element);
  void pop_back() noexcept;

  void clear() noexcept;
  bool empty() noexcept;
  size_type size() noexcept;
  size_type max_size() noexcept;
  void reserve(size_type __n);
  void shrink_to_fit();
  size_type capacity() noexcept;
  iterator insert(iterator pos, const_reference value) noexcept;

  // methods iterators
  iterator begin() noexcept;
  iterator end() noexcept;

  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&... args);
  template <typename... Args> void emplace_back(Args &&... args);

private:
  size_type m_size;
  size_type m_capacity;
  T *arr;
  void add_memory();
};
} // namespace s21

#include "s21_vector.tpp"
#endif