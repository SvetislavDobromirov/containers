#ifndef CPP2_S21_CONTAINERS_0_MASTER_RBTREE_H_
#define CPP2_S21_CONTAINERS_0_MASTER_RBTREE_H_

#include <initializer_list>
#include <iostream>

enum Color { RED, BLACK };

namespace s21 {
template <class Key>
class multiset {
 public:
  class Node {
   public:
    data = new Key;
    Node *parent, *left, *right;
    Color color;
  }
  // Member types
  using value_type = Key;
  using reference = Key &;
  using const_reference = const Key &;
  using iterator = Key *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Member functions
  multiset();
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &ms);
  multiset(multiset &&ms);
  ~multiset();
  operator=(multiset &&ms);

  // Iterators
  iterator begin();
  iterator end();

  // Multiset Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Multiset Modifiers
  void clear();
  iterator insert(const value_type &value);
  void erase(iterator pos);
  void swap(multiset &other);
  void merge(multiset &other);

  // Multiset Lookup
  size_type count(const Key &key);
  iterator find(const Key &key);
  bool contains(const Key &key);
  std::pair<iterator, iterator> equal_range(const Key &key);
  iterator lower_bound(const Key &key);
  iterator upper_bound(const Key &key);

 private:
  Node *root;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_0_MASTER_RBTREE_H_
