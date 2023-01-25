#include <iostream>

namespace s21 {
enum node_colors { RED, BLACK, SERVICE };

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
            struct Element*left, *right, *parent;
            value_type data;
            enum node_colors color;
        } node;

        node *get_head() { return head_element; }; // TEST

        class iterator {
            friend BinaryTree;
            public:
                reference operator*() {
                  return ptr_->data;
                }
                iterator operator++() {
                    if (!ptr_->parent) { //  1
                        std::cout << "1   33" << std::endl;
                        if (ptr_->right) {
                            ptr_ = ptr_->right;
                        } else {
                            // Или возвращаем текущий, или идем налево, или конечный
                            // enf
                        }
                    } else if (ptr_->right ) { // 2
                    // налево до упора
                    // Два случая : либо родитель меньше, лбо равен
                        std::cout << "2   43" << std::endl;
                        
                        //if (ptr_->parent->data <= ptr_->data){
                            ptr_ = ptr_->right;
                            while (ptr_->left != nullptr)
                                ptr_ = ptr_->left;
                        // } else {
                        //     std::cout << "2   48" << std::endl;
                        //     ptr_ = ptr_ ->parent;
                        // }
                    } else if (ptr_->parent->data >= ptr_->data) { // 3
                      std::cout << "3  50" << std::endl;
                        ptr_ = ptr_->parent;
                    } else  { // 4
                      std::cout << "4   53" << std::endl;
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


    private:
        node *create_service_element(); // Создаем мнимый элемент при инициализации
        node *add_new_element(node *current, Key Value, node_colors color, node *service);

    protected:
        node *head_element, *end_element;
        node *min_element;
        node *max_element;
        
        int insert_element(const value_type &value);
        node *insert_to_tree(const value_type &value);
        void print_element(node *El);
        

    public: // FOR SiLLy TESTS
        // RED BLUE foos
        node *grandparent(node *n);
        node *uncle(node *n);
        void rotate_left(node *n);
        void rotate_right(node *n);
        void insert_case1(node *n);
        void insert_case2(node *n);
        void insert_case3(node *n);
        void insert_case4(node *n);
        void insert_case5(node *n);
        void dump2(node  *node_);
};

template <class Key>
typename BinaryTree<Key>::node *BinaryTree<Key>::create_service_element()
{
        node *service = new node();
        service->left = nullptr;
        service->right = nullptr;
        service->parent = nullptr;
        service->color = SERVICE;
        service->data = -1;  // E
        //TODO: DELETE Test Service info
        return service;
}

template <class Key>
BinaryTree<Key>::BinaryTree() {
        head_element = end_element = create_service_element();
        std::cout << "Конструктор дерева без инициализации" << std::endl;
}

template <class Key>
int BinaryTree<Key>::insert_element(const value_type& value){
    int result = 0;
    insert_to_tree(value);

    return result;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::insert_to_tree (const value_type& value) {

    // Крайний правый связываем с мнимым элемеетом.

    // Идем от головы.
    //// Если текущее >= головы тогда смотрим право
    // если право пустое, вставляем
    // иначе переходим налево. Повторяем
    //// Иначе - смотрим лево
    // если левое пустое, вставляем
   
    node* current = head_element; 
    node *new_element = new node(); 
    //      Дело в том, что если голова является мнимым элементом, тогда голова меняется на новый элемент.
    //      Если же голова это действительный элемент, тогда идем от элемента головы
    //      Если элемент на место которого вставляем новый элемент ссылается на мнимый, то совершаем вставку нового элемента. 
    if (current->color == SERVICE) {
        // Где current = SERVICE
                printf("end = %p\n", end_element);
                current = head_element = add_new_element(new_element, value, BLACK, end_element);
    } else {
        while(1) {
            if (value >= current->data)
            {
                        std::cout << "value >= current->data" << std::endl;
                        if (current->right == nullptr)
                        {
                            current->right = new_element;
                            current->right->parent = current;
                            current = current->right;
                            current = add_new_element(current, value, RED, nullptr);
                            break;
                        }
                        else if (current->right == end_element)
                        {
                            std::cout << "right element = end" << std::endl;
                            // вставляем элемент между текущим и конечным.
                            current->right = new_element;
                            current->right->parent = current;
                            current = current->right;
                            current = add_new_element(current, value, RED, end_element);
                            break;
                        }
                        else
                        {
                            current = current->right;
                        }
            }
            else
            {
                        if (current->left == nullptr)
                        {
                            current->left = new node();
                            current->left->parent = current;
                            current = current->left;
                            current = add_new_element(current, value, RED, nullptr);
                            break;
                        }

                        // C этим куском работает частично
                        else if (current->right == end_element)
                        {
                            std::cout << "right element = end" << std::endl;
                            // вставляем элемент между текущим и конечным.
                            current->right = new_element;
                            current->right->parent = current;
                            current = current->right;
                            current = add_new_element(current, value, RED, end_element);
                            break;
                        }

                        else
                        {
                            current = current->left;
                        }
            }
        }

        
    }
   // print_element(current);
    std::cout << "pre-insert point" << std::endl;
    insert_case1(current);
    return current;
} 

#include "s21_Red_Blue.h"
#include "s21_additional_foos.h"

}