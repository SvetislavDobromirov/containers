#include "s21_rbtree.h"

#include <iostream>
#include <vector>

using namespace s21;

template <class Key>
RBTree<Key>::RBTree() {
  root = new RBTree<Key>::Node;
}

template <class Key>
RBTree<Key>::~RBTree() {
  delete_tree(root);
}

template <class Key>
void RBTree<Key>::delete_tree(Node *node) {
  if (node == nullptr) return;
  Node *right = node->right;
  Node *left = node->left;
  delete node;
  if (!right && !left) return;
  delete_tree(left);
  delete_tree(right);
}

template <class Key>
RBTree<Key> &RBTree<Key>::operator=(RBTree &other) {
  this = other;
  return this;
}

template <typename Key>
typename RBTree<Key>::Node *RBTree<Key>::insert(const Key data) {
  Node *current_node = root;
  while (current_node->left && current_node->right) {
    if (current_node->data > data) {
      // std::cout << current_node->data << '\n';
      current_node = current_node->left;
    } else {
      // std::cout << current_node->data << '\n';
      current_node = current_node->right;
    }
  }
  current_node->data = data;
  current_node->color = RED;

  current_node->left = new RBTree<Key>::Node;
  current_node->left->parent = current_node;
  current_node->right = new RBTree<Key>::Node;
  current_node->right->parent = current_node;
  std::cout << current_node->data << '\n';
  insert_case1(current_node);
  return current_node;
}

template <class Key>
typename RBTree<Key>::Node *RBTree<Key>::find_grandparent(
    RBTree<Key>::Node *node) {
  if (node && (node->parent != NULL))
    return node->parent->parent;
  else
    return nullptr;
}

template <class Key>
typename RBTree<Key>::Node *RBTree<Key>::get_root() {
  return root;
}

template <class Key>
typename RBTree<Key>::Node *RBTree<Key>::find_uncle(RBTree<Key>::Node *n) {
  Node *g = find_grandparent(n);
  if (!g) return nullptr;
  if (n->parent == g->left)
    return g->right;
  else
    return g->left;
}

template <class Key>
void RBTree<Key>::rotate_left(RBTree<Key>::Node *n) {
  Node *pivot = n->right;
  pivot->parent = n->parent;
  if (n->parent) {
    if (n->parent->left == n)
      n->parent->left = pivot;
    else
      n->parent->right = pivot;
  } else {
    root = pivot;
  }
  n->right = pivot->left;
  if (pivot->left) pivot->left->parent = n;
  n->parent = pivot;
  pivot->left = n;
}

template <class Key>
void RBTree<Key>::rotate_right(RBTree<Key>::Node *n) {
  Node *pivot = n->left;
  pivot->parent = n->parent;
  if (n->parent != NULL) {
    if (n->parent->left == n)
      n->parent->left = pivot;
    else
      n->parent->right = pivot;
  } else {
    root = pivot;
  }
  n->left = pivot->right;
  if (pivot->right) pivot->right->parent = n;
  n->parent = pivot;
  pivot->right = n;
}

template <class Key>
void RBTree<Key>::insert_case1(RBTree<Key>::Node *n) {
  // std::cout << "insert_case1 \n";
  if (!n->parent)
    n->color = BLACK;
  else
    insert_case2(n);
}

template <class Key>
void RBTree<Key>::insert_case2(RBTree<Key>::Node *n) {
  // std::cout << "insert_case2 \n";
  if (n->parent->color == BLACK)
    return; /* Tree is still valid */
  else
    insert_case3(n);
}

template <class Key>
void RBTree<Key>::insert_case3(RBTree<Key>::Node *n) {
  // std::cout << "insert_case3 \n";
  Node *u = find_uncle(n), *g;
  if (u && (u->color == RED)) {
    n->parent->color = BLACK;
    u->color = BLACK;
    g = find_grandparent(n);
    g->color = RED;
    insert_case1(g);
  } else {
    insert_case4(n);
  }
}

template <class Key>
void RBTree<Key>::insert_case4(RBTree<Key>::Node *n) {
  // std::cout << "insert_case4 \n";
  Node *g = find_grandparent(n);
  if ((n == n->parent->right) && (n->parent == g->left)) {
    rotate_left(n->parent);
    n = n->left;
  } else if ((n == n->parent->left) && (n->parent == g->right)) {
    rotate_right(n->parent);
    n = n->right;
  }
  insert_case5(n);
}

template <class Key>
void RBTree<Key>::insert_case5(RBTree<Key>::Node *n) {
  // std::cout << "insert_case5 \n";
  Node *g = find_grandparent(n);
  n->parent->color = BLACK;
  g->color = RED;
  if ((n == n->parent->left) && (n->parent == g->left)) {
    rotate_right(g);
  } else {
    rotate_left(g);
  }
}

template <class Key>
typename RBTree<Key>::Node *RBTree<Key>::find_sibling(RBTree<Key>::Node *n) {
  if (n == n->parent->left)
    return n->parent->right;
  else
    return n->parent->left;
}

template <class Key>
void RBTree<Key>::print_tree(RBTree<Key>::Node const *node,
                             std::string const &prefix, bool root, bool last) {
  std::cout << prefix << (root ? "" : (last ? "/-" : "|-"))
            << (node ? std::to_string(node->data) + ":" +
                           (node->color == BLACK ? "B" : "R")
                     : "")
            << std::endl;
  if (!node || (!node->left && !node->right)) return;
  std::vector<Node *> v{node->left, node->right};
  for (size_t i = 0; i < v.size(); ++i)
    print_tree(v[i], prefix + (root ? "" : (last ? "  " : "| ")), false,
               i + 1 >= v.size());
}

template <class Key>
size_t RBTree<Key>::calc_leafs(RBTree<Key>::Node const *node) {
  std::cout << node->data << '\n';
  size_t leafs = 0;
  if (!node || (!node->left && !node->right)) return 1;
  leafs += calc_leafs(node->left);
  leafs += calc_leafs(node->right);
  return leafs;
}

template <class Key>
void RBTree<Key>::print_tree_my(RBTree<Key>::Node const *node) {}

template <class Key>
void RBTree<Key>::replace_node(RBTree<Key>::Node *n, RBTree<Key>::Node *child) {
  child->parent = n->parent;
  if (n == n->parent->left) {
    n->parent->left = child;
  } else {
    n->parent->right = child;
  }
}

template <class Key>
void RBTree<Key>::erase(Key data) {
  if (root->data == data) {
    if (!root->left->right && !root->left->left && !root->right->left &&
        !root->right->right) {
      std::cout << "if with 3 deletes \n";
      delete root->right;
      delete root->left;
      delete root;
      root = nullptr;
      return;
    } else if (!root->left->right && !root->left->left) {
      std::cout << "if with delete left \n";
      Node *right = root->right;
      delete root->left;
      delete root;
      root = right;
      return;
    } else if (root->right->left && !root->right->right) {
      std::cout << "if with delete right \n";
      Node *left = root->left;
      delete root->right;
      delete root;
      root = left;
      return;
    }
  }
  Node *current_node = root;
  while (current_node->left && current_node->right) {
    if (current_node->data > data) {
      current_node = current_node->left;
    } else if (current_node->data < data) {
      current_node = current_node->right;
    } else if (current_node->data == data) {
      break;
    }
  }
  if (current_node->right) delete_one_child(current_node);
}

template <class Key>
void RBTree<Key>::delete_one_child(RBTree<Key>::Node *n) {
  std::cout << "delete_one_child \n";
  Node *child = (!n->right->left && !n->right->right) ? n->left : n->right;
  replace_node(n, child);
  if (n->color == BLACK) {
    if (child->color == RED)
      child->color = BLACK;
    else
      delete_case1(child);
  }
  delete n;
}

template <class Key>
void RBTree<Key>::delete_case1(RBTree<Key>::Node *n) {
  std::cout << "delete_case1 \n";
  if (n->parent) delete_case2(n);
}

template <class Key>
void RBTree<Key>::delete_case2(RBTree<Key>::Node *n) {
  std::cout << "delete_case2 \n";
  Node *s = find_sibling(n);
  if (s->color == RED) {
    n->parent->color = RED;
    s->color = BLACK;
    if (n == n->parent->left)
      rotate_left(n->parent);
    else
      rotate_right(n->parent);
  }
  delete_case3(n);
}

template <class Key>
void RBTree<Key>::delete_case3(RBTree<Key>::Node *n) {
  std::cout << "delete_case3 \n";
  Node *s = find_sibling(n);

  if ((n->parent->color == BLACK) && (s->color == BLACK) &&
      (s->left->color == BLACK) && (s->right->color == BLACK)) {
    s->color = RED;
    delete_case1(n->parent);
  } else
    delete_case4(n);
}

template <class Key>
void RBTree<Key>::delete_case4(RBTree<Key>::Node *n) {
  std::cout << "delete_case4 \n";
  Node *s = find_sibling(n);

  if ((n->parent->color == RED) && (s->color == BLACK) &&
      (s->left->color == BLACK) && (s->right->color == BLACK)) {
    s->color = RED;
    n->parent->color = BLACK;
  } else
    delete_case5(n);
}

template <class Key>
void RBTree<Key>::delete_case5(RBTree<Key>::Node *n) {
  std::cout << "delete_case5 \n";
  Node *s = find_sibling(n);

  if (s->color == BLACK) { /* this if statement is trivial,
due to case 2 (even though case 2 changed the sibling to a sibling's child,
the sibling's child can't be red, since no red parent can have a red
child).
*/
    /* the following statements just force the red to be on the left of the
    left
       of the parent, or right of the right, so case six will rotate
       correctly.
     */
    if ((n == n->parent->left) && (s->right->color == BLACK) &&
        (s->left->color == RED)) {
      /* this last test is trivial too due to cases 2-4. */
      s->color = RED;
      s->left->color = BLACK;
      rotate_right(s);
    } else if ((n == n->parent->right) && (s->left->color == BLACK) &&
               (s->right->color == RED)) {
      /* this last test is trivial too due to cases 2-4. */
      s->color = RED;
      s->right->color = BLACK;
      rotate_left(s);
    }
  }
  delete_case6(n);
}

template <class Key>
void RBTree<Key>::delete_case6(RBTree<Key>::Node *n) {
  std::cout << "delete_case6 \n";
  Node *s = find_sibling(n);

  s->color = n->parent->color;
  n->parent->color = BLACK;

  if (n == n->parent->left) {
    s->right->color = BLACK;
    rotate_left(n->parent);
  } else {
    s->left->color = BLACK;
    rotate_right(n->parent);
  }
}

int main() {
  s21::RBTree<int> tree;
  size_t m = 4;
  for (size_t i = 1; i < m; i++) {
    tree.insert(i);
    tree.print_tree(tree.get_root());
  }
  for (size_t i = 1; i < m; i++) {
    tree.erase(i);
    tree.print_tree(tree.get_root());
  }
  return 0;
}
