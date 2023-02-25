#ifndef __SRC_STACK_STACK_H__
#define __SRC_STACK_STACK_H__

#include "../list/s21_list.h"
#include <initializer_list>

namespace s21 {
template <class T> class stack {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_t = unsigned long;

  stack();
  stack(std::initializer_list<T> const &items);
  stack(const stack &s);
  stack(stack &&s);
  stack &operator=(stack &&s);
  ~stack();

  void push(const_reference value);
  void pop();
  void swap(stack &other);
  bool empty() const;
  size_t size();
  const_reference top();
  template <class... Args> void emplace_back(Args &&... args);

private:
  s21::list<T> obj; // object
};

// Methods

template <class T> unsigned long stack<T>::size() { return obj.size(); }

template <class T> void stack<T>::push(const_reference value) {
  obj.push_back(value);
}

template <class T> void stack<T>::pop() {
  if (obj.size() != 0)
    obj.pop_back();
}

template <class T> void stack<T>::swap(stack &other) { obj.swap(other.obj); }

template <class T> bool stack<T>::empty() const { return obj.empty(); }

template <class T> const T &stack<T>::top() { return *(--obj.end()); }
//////////

// Constructors
template <class T> stack<T>::stack() = default;

template <class T>
template <class... Args>
void stack<T>::emplace_back(Args &&... args) {
  vector<T> temp{args...};
  auto it = temp.begin();
  for (; it != temp.end(); it++) {
    this->push(*it);
  }
}

template <class T> stack<T>::stack(const stack &s) = default;

template <class T> stack<T>::stack(stack &&s) { obj = std::move(s.obj); }

template <class T> stack<T> &stack<T>::operator=(stack &&s) = default;

template <class T> stack<T>::stack(std::initializer_list<T> const &items) {
  for (auto p = items.begin(); p != items.end(); p++)
    obj.push_back(*p);
}

template <class T> stack<T>::~stack() = default;
} // namespace s21
#endif