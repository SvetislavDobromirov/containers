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
        
        typedef struct Element {
            struct Element*left, *right, *parent, *repeate;
            value_type data;
            enum node_colors color;
        } node;

        
        
        class iterator {
            friend BinaryTree;
            public:
                reference operator*() {
                  return ptr_->data;
                }
                iterator operator++() {
                    if (!ptr_->parent) { //  1

                        if (ptr_->right) {
                            ptr_ = ptr_->right;
                        } else {
                            // Или возвращаем текущий, или идем налево, или конечный
                            // enf
                        }
                    } else if (ptr_->right) { // 2
                    // налево до упора
                        ptr_ = ptr_->right;
                        while (ptr_->left != nullptr)
                            ptr_ = ptr_->left;
                    } else if (ptr_->parent->data >= ptr_->data) { // 3
                        ptr_ = ptr_->parent;
                    } else  { // 4
                        ptr_ = ptr_->parent;
                        if (ptr_->parent) {
                            ptr_ = ptr_->parent;
                        } else if (ptr_->right){
                            ptr_ = ptr_->right;
                        } else {
                            // тогда конечный результат
                        }
                    }
                    return *this;
                }

                bool operator!=(iterator in) {
                    return in.ptr_ != this->ptr_;
                }

                iterator operator--() {
                    std::cout << "33" << std::endl;
                    while (ptr_->left != nullptr) {
                         std::cout << "34" << std::endl;
                        ptr_ = ptr_->left;
                    }
                    return *this;
                }
                void checking_repeate(){

                };
                node* ptr_;

        };

    protected:
        node *head_element;
        node *get_head(){return head_element;};
        int insert_element(const value_type& value);
        node *insert_to_tree(const value_type& value);
}; 

template <class Key>
BinaryTree<Key>::BinaryTree() : head_element(nullptr){
    std::cout << "Конструктор дерева без инициализации" << std::endl;
}

template <class Key>
int BinaryTree<Key>::insert_element(const value_type& value){
    int result = 0;
    //node *insert_place = 
    insert_to_tree(value);

    return result;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::insert_to_tree (const value_type& value) {
    // От головы 
    // Если поинтер на голову нулевой, тогда поместить элементы
    // Возвращаем ссылку на новый элемент
    node *result  =  nullptr;
   // std::cout << "62 " << std::endl;
    if (!head_element) {
       // std::cout << "64 " << std::endl;
        head_element  = new node();
        head_element -> right == nullptr;
        head_element -> left == nullptr;
        head_element ->color = BLACK;
        head_element->data = value;
       //  printf("78: %p\n", head_element);

    } else { 
        // Идем от головы.
            //// Если текущее >= головы тогда смотрим право
            // если право пустое, вставляем
            // иначе переходим налево. Повторяем
            //// Иначе - смотрим лево
            // если левое пустое, вставляем
            node* current = head_element;
            while(1) {
                if (value >= current->data) {
                    if (current->right == nullptr) {
                        current->right = new node();
                        current->right->parent = current;
                        current = current->right;
                        current->color = RED;
                        current->left = nullptr;
                        current->right = nullptr;
                        current->data = value;
                        result = current;
                       //  printf("98: %p\n", current);
                        break;
                    } else {
                        current = current->right;
                    }
                } else {
                    if (current->left == nullptr) {

                        current->left = new node();
                        current->left->parent = current;

                        current = current->left;
                        current->color = RED;
                        current->left = nullptr;
                        current->right = nullptr;
                        current->data = value;
                        result = current;
                    //     printf("113: %p\n", current);
                        break;
                    } else {
                         current = current->left;
                    }
                }
            }
    }
    return result;
} 

}
