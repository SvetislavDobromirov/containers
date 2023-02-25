#ifndef __SRC_SET_H__
#define __SRC_SET_H__

#include "s21_tree.h"
#include "../vector/s21_vector.h"

namespace s21 {

typedef unsigned long size_t;

template <typename Key> class set : public tree<Key> {
public:
  class iterator;
  using key_type = Key;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = iterator;
  using iterator = iterator;
  using size_type = size_t;

  set() = default;
  set(std::initializer_list<Key> const &items);
  set(const set &s);
  set(set &&s);

  set &operator=(set &&other) noexcept;

  std::pair<iterator, bool> insert(const value_type &value);
  template <class... Args>
  vector<std::pair<iterator, bool>> emplace(Args &&... args);

  void erase(iterator pos);
  iterator find(const key_type &key);
  bool contains(const key_type &key);
  void swap(set &other) noexcept;
  void merge(set &other);
  class const_iterator {
  public:
    auto operator++(int);
    auto operator++();
    auto operator--(int);
    auto operator--();
    const auto operator*();
    bool operator!=(const const_iterator &other);
    bool operator==(const const_iterator &other);
    typename tree<Key>::node *it_current_node = nullptr;
  };
  class iterator : public const_iterator {
  public:
    iterator() : const_iterator() {}
  };

  iterator begin();
  iterator end();
};

} // namespace s21

#include "s21_set.tpp"

#endif // __SRC_SET_H__