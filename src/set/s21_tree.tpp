#include <iostream>
#include <limits>

#include "s21_tree.h"

namespace s21 {

template <typename T> tree<T>::tree() : root_(nullptr), size_(0) {}

template <typename T>
tree<T>::tree(const std::initializer_list<T> &items)
    : root_(nullptr), size_(0) {
  for (auto p = items.begin(); p != items.end(); p++) {
    tree_insert(*p);
  }
}

template <typename T> tree<T>::tree(const tree &other) {
  size_ = other.size_;
  root_ = copy_tree(other.root_);
}

template <typename T> tree<T>::tree(tree &&other) noexcept {
  root_ = other.root_;
  size_ = other.size_;
  other.root_ = nullptr;
  other.size_ = 0;
}

template <typename T> tree<T>::~tree() { deallocate_node(root_); }

template <typename T> int tree<T>::tree_insert(T value) {
  if (root_ == nullptr) {
    ++size_;
    root_ = new node(value);
  } else {
    node **current_node = &root_;
    node *prev_node = root_;
    while (*current_node != nullptr) {
      prev_node = *current_node;
      node &node_tmp = **current_node;
      if (value < node_tmp.node_data) {
        current_node = &node_tmp.left_node;
      } else if (value > node_tmp.node_data) {
        current_node = &node_tmp.right_node;
      } else {
        return 3;
      }
    }
    ++size_;
    *current_node = new node(value);
    (*current_node)->parent_node = prev_node;
  }

  return 0;
}

template <typename T> void tree<T>::erase(const T &value) {
  node *current_node = root_;
  while (current_node != nullptr && current_node->node_data != value) {
    if (value < current_node->node_data) {
      current_node = current_node->left_node;
    } else {
      current_node = current_node->right_node;
    }
  }
  if (current_node != nullptr) {
    erase(current_node);
    size_--;
  }
}

template <typename T> void tree<T>::erase(node *current_node) {
  if (current_node == nullptr) {
    return;
  }

  if (current_node->left_node == nullptr &&
      current_node->right_node == nullptr) {
    if (current_node->parent_node == nullptr) {
      root_ = nullptr;
    } else if (current_node->parent_node->left_node == current_node) {
      current_node->parent_node->left_node = nullptr;
    } else {
      current_node->parent_node->right_node = nullptr;
    }
  }
  // Если у удаляемого узла нет левого потомка =>
  // переставляем указатель родителя на правого потомка
  else if (current_node->left_node == nullptr) {
    if (current_node->parent_node == nullptr) {
      root_ = current_node->right_node;
    } else if (current_node->parent_node->left_node == current_node) {
      current_node->parent_node->left_node = current_node->right_node;
    } else {
      current_node->parent_node->right_node = current_node->right_node;
    }
    if (current_node->right_node != nullptr) {
      current_node->right_node->parent_node = current_node->parent_node;
    }
  }
  // Если нет правого потомка
  else if (current_node->right_node == nullptr) {
    if (current_node->parent_node == nullptr) {
      root_ = current_node->left_node;
    } else if (current_node->parent_node->left_node == current_node) {
      current_node->parent_node->left_node = current_node->left_node;
    } else {
      current_node->parent_node->right_node = current_node->left_node;
    }
    if (current_node->left_node != nullptr) {
      current_node->left_node->parent_node = current_node->parent_node;
    }
  }
  // Если есть оба потомка =>
  // находим минимального потомка в правом узле
  else {
    node *replacement = current_node->right_node;
    while (replacement->left_node != nullptr) {
      replacement = replacement->left_node;
    }
    current_node->node_data = replacement->node_data;
    erase(replacement);
    return;
  }

  delete current_node;
}

template <typename T> size_t tree<T>::size() { return size_; }

template <typename T> bool tree<T>::empty() { return root_ == nullptr; }

template <typename T> void tree<T>::deallocate_node(node *current_node) {
  if (current_node == nullptr) {
    return;
  }

  deallocate_node(current_node->left_node);
  deallocate_node(current_node->right_node);
  delete current_node;
}

template <typename T> void tree<T>::clear() {
  while (root_ != nullptr) {
    erase(root_);
  }
  size_ = 0;
}

template <typename T> typename tree<T>::size_type tree<T>::max_size() const {
  const size_t node_size = sizeof(node) + alignof(node);
  return std::numeric_limits<size_t>::max() / node_size;
}

template <typename T>
typename tree<T>::node *tree<T>::copy_tree(tree::node *cur_node) {
  if (!cur_node) {
    return nullptr;
  }
  node *node_tmp = new node(cur_node->node_data);
  node_tmp->left_node = copy_tree(cur_node->left_node);
  if (node_tmp->left_node) {
    node_tmp->left_node->parent_node = node_tmp;
  }
  node_tmp->right_node = copy_tree(cur_node->right_node);
  if (node_tmp->right_node) {
    node_tmp->right_node->parent_node = node_tmp;
  }

  return node_tmp;
}

} // namespace s21
