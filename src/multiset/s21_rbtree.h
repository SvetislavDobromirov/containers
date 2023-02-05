#include <initializer_list>
#include <iostream>
#include <vector>

enum Color { RED, BLACK };

namespace s21 {
template <class Key>
class RBTree {
 public:
  // Member types
  using value_type = Key;
  using reference = Key &;
  using const_reference = const Key &;
  using iterator = Key *;
  using const_iterator = const Key *;
  using size_type = size_t;

  typedef struct Element {
    struct Element *left = nullptr;
    struct Element *right = nullptr;
    struct Element *parent = nullptr;
    value_type data;
    Color color = BLACK;
    size_type repeats = 0;
  } Node;

  RBTree();
  ~RBTree();
  void delete_tree(Node *node);
  RBTree &operator=(RBTree &other);

  Node *insert(const Key data);
  void erase(Key data);

  Node *find_grandparent(Node *node);
  Node *get_root();
  void print_tree(Node const *node, std::string const &prefix = "",
                  bool root = true, bool last = true);
  size_t calc_tree_leaves(Node const *root);
  size_t calc_node_leaves(Node const *root);
  void print_tree_my(Node const *root);
  Node *find_max(Node const *node_start);
  Node *find_min(Node const *node_start);

 private:
  Node *find_uncle(Node *n);
  Node *find_sibling(Node *node);
  void rotate_left(Node *node);
  void rotate_right(Node *node);
  void insert_case1(Node *node);
  void insert_case2(Node *node);
  void insert_case3(Node *node);
  void insert_case4(Node *node);
  void insert_case5(Node *node);

  void replace_node(Node *node, Node *child);
  void delete_one_child(Node *node);
  void delete_no_childs(Node *node);
  void delete_case1(Node *node);
  void delete_case2(Node *node);
  void delete_case3(Node *node);
  void delete_case4(Node *node);
  void delete_case5(Node *node);
  void delete_case6(Node *node);

  Node *root, *min, *max;
  size_t size;
};
}  // namespace s21
