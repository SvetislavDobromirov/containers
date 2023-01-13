
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <class T, size_t N>
class array {
 public:
  // Member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Constructors and destructors
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array();
  array<T, N> &operator=(array &&a);

  // array Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // array Iterators
  iterator begin();
  iterator end();

  // array Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // array Modifiers
  void swap(array &other);
  void fill(const_reference value);

  // Helpers
  void PrintArray();

 private:
  size_type m_size;
  T *arr;
};  // namespace s21template<classT>class array

// Constructors and destructors
template <class T, size_t N>
array<T, N>::array() : m_size(N) {
  if (N == 0)
    arr = nullptr;
  else
    arr = new T[N];
}

template <class T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : m_size(N) {
  if (items.size() > N) throw std::out_of_range("Too large initializer list");
  arr = new T[N];
  for (size_type i = 0; i < items.size(); i++) arr[i] = items.begin()[i];
}

template <class T, size_t N>
array<T, N>::array(const array &a) : m_size(N) {
  if (N != a.m_size) throw std::logic_error("Invalid array size");
  arr = new T[N];
  std::copy_n(a.arr, m_size, arr);
}

template <class T, size_t N>
array<T, N>::array(array &&a) : arr(a.arr), m_size(a.m_size) {
  if (N != a.m_size) throw std::logic_error("Invalid array size");
}

template <class T, size_t N>
array<T, N>::~array() {
  delete[] arr;
};

template <class T, size_t N>
array<T, N> &array<T, N>::operator=(array &&a) {
  if (m_size != a.m_size) throw std::logic_error("Invalid array size");
  arr = a.arr;
  m_size = a.m_size;
  return this;
}

// Temporary helpers
template <class T, size_t N>
void array<T, N>::PrintArray() {
  for (size_type i = 0; i < this->m_size; i++) {
    std::cout << this->arr[i] << ' ';
  }
  std::cout << std::endl;
}

// array Element access
template <class T, size_t N>
typename array<T, N>::reference &array<T, N>::at(size_type pos) {
  if (pos >= m_size) throw std::out_of_range("Out of range");
  return arr[pos];
}

template <class T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  if (pos >= m_size) throw std::out_of_range("Out of range");
  return arr[pos];
}

template <class T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  return arr[0];
}

template <class T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  if (m_size < 1)
    return nullptr;
  else
    return arr[m_size - 1];
}

template <class T, size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return arr;
}

// array Iterators
template <class T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return arr;
}

template <class T, size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  if (m_size < 1)
    return nullptr;
  else
    return arr + m_size - 1;
}

// array Capacity
template <class T, size_t N>
bool array<T, N>::empty() {
  return m_size == 0;
}

template <class T, size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return m_size;
}

template <class T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return static_cast<size_type>(pow(2, sizeof(void *) * 8) / sizeof(T) - 1);
}

// array Modifiers
template <class T, size_t N>
void array<T, N>::swap(array &other) {
  std::swap_ranges(arr, arr + m_size, other.arr);
}

template <class T, size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < m_size; i++) arr[i] = value;
}

}  // namespace s21
