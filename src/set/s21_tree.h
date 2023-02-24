#ifndef __SRC_TREE_H__
#define __SRC_TREE_H__

#include <initializer_list>
#include <vector>

namespace s21 {
typedef unsigned long size_t;

template <typename T> class tree {
public:
  using size_type = size_t;

  tree();
  tree(std::initializer_list<T> const &items);
  tree(const tree &other);
  tree(tree &&other) noexcept;
  ~tree();

  void erase(const T &value);
  size_type size();
  size_type max_size() const;
  bool empty();
  void clear();

protected:
  class node;
  int tree_insert(T value);
  node *root_;
  size_type size_;
  void erase(node *current_node);
  void deallocate_node(node *current_node);
  node *copy_tree(node *cur_node);

  class node {
  public:
    explicit node(T data = T(), node *r_node = nullptr, node *l_node = nullptr,
                  node *p_node = nullptr) {
      this->node_data = data;
      this->parent_node = p_node;
      this->right_node = r_node;
      this->left_node = l_node;
    }
    node *left_node;
    node *right_node;
    node *parent_node;
    T node_data;
  };
};

} // namespace s21

#include "s21_tree.tpp"

#endif // __SRC_TREE_H__
