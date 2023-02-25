#include <utility>

#include "s21_set.h"

namespace s21 {

template <typename T>
set<T>::set(const std::initializer_list<T> &items) : tree<T>(items) {}

template <typename T> set<T>::set(const set &s) : tree<T>(s) {}

template <typename T> set<T>::set(set &&s) : tree<T>(std::move(s)) {}

template <typename T> const auto set<T>::const_iterator::operator*() {
  if (!it_current_node) {
    throw std::runtime_error("pointer is null");
  }
  return it_current_node->node_data;
}

template <typename T> auto set<T>::const_iterator::operator++(int) {
  // Если у текущего узла есть правое поддерево, то нужно перейти к наименьшему
  // элементу в этом поддереве
  if (it_current_node->right_node) {
    it_current_node = it_current_node->right_node;
    while (it_current_node->left_node) {
      it_current_node = it_current_node->left_node;
    }
  } else {
    // Иначе, нужно искать родительский узел, который является левым потомком
    typename tree<T>::node *parent = it_current_node->parent_node;
    while (parent && it_current_node == parent->right_node) {
      it_current_node = parent;
      parent = parent->parent_node;
    }
    it_current_node = parent;
  }

  return *this;
}

template <typename T> auto set<T>::const_iterator::operator++() {
  // Если у текущего узла есть правое поддерево, то нужно перейти к наименьшему
  // элементу в этом поддереве
  if (it_current_node->right_node) {
    it_current_node = it_current_node->right_node;
    while (it_current_node->left_node) {
      it_current_node = it_current_node->left_node;
    }
  } else {
    // Иначе, нужно искать родительский узел, который является левым потомком
    typename tree<T>::node *parent = it_current_node->parent_node;
    while (parent && it_current_node == parent->right_node) {
      it_current_node = parent;
      parent = parent->parent_node;
    }
    it_current_node = parent;
  }

  return *this;
}

template <typename T> auto set<T>::const_iterator::operator--(int) {
  // Если у текущего узла есть левое поддерево, то нужно перейти к наибольшему
  // элементу в этом поддереве
  if (it_current_node->left_node) {
    it_current_node = it_current_node->left_node;
    while (it_current_node->right_node) {
      it_current_node = it_current_node->right_node;
    }
  } else {
    // Иначе, нужно искать родительский узел, который является правым потомком
    typename tree<T>::node *parent = it_current_node->parent_node;
    while (parent && it_current_node == parent->left_node) {
      it_current_node = parent;
      parent = parent->parent_node;
    }

    it_current_node = parent;
  }

  return *this;
}

template <typename T> auto set<T>::const_iterator::operator--() {
  // Если у текущего узла есть левое поддерево, то нужно перейти к наибольшему
  // элементу в этом поддереве
  if (it_current_node->left_node) {
    it_current_node = it_current_node->left_node;
    while (it_current_node->right_node) {
      it_current_node = it_current_node->right_node;
    }
  } else {
    // Иначе, нужно искать родительский узел, который является правым потомком
    typename tree<T>::node *parent = it_current_node->parent_node;
    while (parent && it_current_node == parent->left_node) {
      it_current_node = parent;
      parent = parent->parent_node;
    }

    it_current_node = parent;
  }

  return *this;
}

template <typename Key>
std::pair<typename set<Key>::iterator, bool>
set<Key>::insert(const value_type &value) {
  int is_find = tree<Key>::tree_insert(value);
  iterator result_first = find(value);
  bool result_second = is_find != 3;
  std::pair<iterator, bool> result;
  result.first = result_first;
  result.second = result_second;

  return result;
}

template <typename Key>
template <typename... Args>
vector<std::pair<typename set<Key>::iterator, bool>>
set<Key>::emplace(Args &&... args) {
  vector<std::pair<iterator, bool>> result;
  vector<Key> vector_from_args = {args...};
  for (auto &it : vector_from_args) {
    result.push_back(insert(Key(std::forward<Key>(it))));
  }

  return result;
}

template <typename T> typename set<T>::iterator set<T>::begin() {
  iterator result;

  if (tree<T>::root_ == nullptr) {
    result.it_current_node = nullptr;
    return result;
  }

  typename tree<T>::node *current_node = tree<T>::root_;
  while (current_node->left_node != nullptr) {
    current_node = current_node->left_node;
  }
  result.it_current_node = current_node;

  return result;
}

template <typename T> typename set<T>::iterator set<T>::end() {
  iterator result;
  result.it_current_node = nullptr;

  return result;
}

template <typename T> typename set<T>::iterator set<T>::find(const T &key) {
  iterator result;

  if (tree<T>::root_ == nullptr) {
    return result;
  }

  typename tree<T>::node *current_node = tree<T>::root_;
  while (current_node != nullptr) {
    if (key > current_node->node_data) {
      current_node = current_node->right_node;
    } else if (key < current_node->node_data) {
      current_node = current_node->left_node;
    } else {
      result.it_current_node = current_node;
      return result;
    }
  }
  return result;
}

template <typename T> void set<T>::swap(set &other) noexcept {
  std::swap(tree<T>::root_, other.root_);
  size_t size_tmp = this->size_;
  this->size_ = other.size_;
  other.size_ = size_tmp;
}

template <typename T> void set<T>::erase(iterator pos) { tree<T>::erase(*pos); }

template <typename Key> void set<Key>::merge(set &other) {
  for (auto it = other.begin(); it != other.end(); it++) {
    tree<Key>::tree_insert(std::move(*it));
  }
}

template <typename Key> bool set<Key>::contains(const Key &key) {
  typename tree<Key>::node *current_node = tree<Key>::root_;
  while (current_node != nullptr) {
    if (key > current_node->node_data) {
      current_node = current_node->right_node;
    } else if (key < current_node->node_data) {
      current_node = current_node->left_node;
    } else {
      return true;
    }
  }

  return false;
}

template <typename Key>
bool set<Key>::const_iterator::operator!=(
    const set<Key>::const_iterator &other) {
  return it_current_node != other.it_current_node;
}

template <typename Key>
bool set<Key>::const_iterator::operator==(
    const set<Key>::const_iterator &other) {
  return it_current_node == other.it_current_node;
}

template <typename Key> set<Key> &set<Key>::operator=(set &&other) noexcept {
  tree<Key>::root_ = other.root_;
  tree<Key>::size_ = other.size_;
  other.root_ = nullptr;
  other.size_ = 0;
  return *this;
}

} // namespace s21