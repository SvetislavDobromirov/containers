#include <iostream>

namespace s21 {
enum node_colors { RED, BLACK };

template <class Key>
class BinaryTree {
    public:
        class iterator;
        class const_iterator;
        using key_type = Key;
        using value_type = key_type;
        using reference = Key &;

        BinaryTree();
        
        typedef struct ElementЧ {
            struct Node *left, *right, *parent;
            Key data;
            enum node_colors color;
        } node;

        class iterator {

            reference operator*() {
              //  return ptr->data;
            }
            iterator operator++(){

            }
           node* ptr_;
        };

    protected:
        node *head_element;
        node* get_head(){return head_element;};
        
}; 

template <class Key>
BinaryTree<Key>::BinaryTree() : head_element(nullptr){
    std::cout << "Конструктор дерева без инициализации" << std::endl;
}

}
