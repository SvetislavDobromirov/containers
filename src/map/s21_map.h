#ifndef __SRC_MAP_H__
#define __SRC_MAP_H__

#include "../set/s21_set.h"

namespace s21 {

typedef unsigned long size_t;

template <class Key, class T>
class map : public set<std::pair<Key, T>> {
 public:
  using mapped_type = T;
  using key_type = Key;
  using value_type = std::pair<key_type, mapped_type>;
  using iterator = typename set<value_type>::iterator;

  map() = default;
  map(std::initializer_list<value_type> const &items);
  map(const map& other);
  map(map&& other) noexcept;

  bool contains(const key_type& key);

  mapped_type &at(const key_type &key);

  mapped_type &operator[](const key_type &key);

  std::pair<iterator, bool> insert(const value_type &value);

  std::pair<iterator, bool> insert(const key_type &key, const mapped_type &obj);

  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
};

}  // namespace s21

#include "s21_map.tpp"

#endif  // __SRC_MAP_H__
