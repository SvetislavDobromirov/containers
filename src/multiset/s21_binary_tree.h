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
        
        typedef struct Node {
            struct Node *left, *right, *parent;
            Key data;
            enum node_colors color;
        } node;

        class iterator {
            reference operator*(){
                return 0;
            }
            iterator operator++(){

            }
        };

    private:
        node *head;
        
}; 

template <class Key>
BinaryTree<Key>::BinaryTree(){
    std::cout << "Конструктор дерева" << std::endl;
    head = nullptr;
}

}