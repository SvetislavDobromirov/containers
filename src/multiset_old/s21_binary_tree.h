#include <iostream>
#include <initializer_list>

namespace s21 {
enum node_colors { RED, BLACK, SERVICE, DELETE };

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
             Element*left, *right, *parent;
            value_type data;
            enum node_colors color;
        } node;

       node *get_head() { return head_element; }; // TEST
        
    private:
        node *add_new_element(node *current, Key Value, node_colors color, node *service);

    protected:
        node *head_element, *end_element;
        node *create_service_element(); // Создаем мнимый элемент при инициализации
        
        int insert_element(const value_type &value);
        node *insert_to_tree(const value_type &value);
        
       // void erase_main(node* n);

        

    public: // FOR SiLLy TESTS
        void print_element(node *El);
        // RED BLUE foos
        // bool is_both_children_black(node *n);
        // node *grandparent(node *n);
        // node *uncle(node *n);
        // void rotate_left(node *n);
        // void rotate_right(node *n);
        // void insert_case1(node *n);
        // void insert_case2(node *n);
        // void insert_case3(node *n);
        // void insert_case4(node *n);
        // void insert_case5(node *n);
        // void dump2(node  *node_);
        // node * sibling(node *n);

        // void replace_node(node* n, node* child);
        // void delete_one_child(node *n);
        // void delete_case1( node *n);
        // void delete_case2( node *n);
        // void delete_case3( node *n);
        // void delete_case4( node *n);
        // void delete_case5( node *n);
        // void delete_case6( node *n);

};


template <class Key>
BinaryTree<Key>::BinaryTree() {
        std::cout << "Конструктор дерева без инициализации" << std::endl;
}



template <class Key>
typename BinaryTree<Key>::node *BinaryTree<Key>::insert_to_tree(const value_type &value)
{

        // Крайний правый связываем с мнимым элемеетом.
        node *current = head_element;
        node *new_element = new node();

        //      Дело в том, что если голова является мнимым элементом, тогда голова меняется на новый элемент.
        //      Если же голова это действительный элемент, тогда идем от элемента головы
        //      Если элемент на место которого вставляем новый элемент ссылается на мнимый, то совершаем вставку нового элемента.
        if (current->color == SERVICE) {
            // Где current = SERVICE
       
            current = head_element = add_new_element(new_element, value, BLACK, end_element);
            current->left = end_element;
        } else {
            while (1)
            {
                if (value >= current->data)
                {
                 
                //    std::cout << "value >= current->data" << std::endl;
                    if (current->right == nullptr)
                    {
                        current->right = new_element;
                        current->right->parent = current;
                        current = current->right;
                        current = add_new_element(current, value, RED, nullptr);
                        break;
                    } else if (current->right == end_element)
                    {
                        //std::cout << "right element = end" << std::endl;
                        // вставляем элемент между текущим и конечным.
                        current->right = new_element;
                        current->right->parent = current;
                        current = current->right;
                        current = add_new_element(current, value, RED, end_element);
                        end_element->parent = current;
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
                else
                {
                    if (current->left == nullptr) {
                        current->left = new node();
                        current->left->parent = current;
                        current = current->left;
                        current = add_new_element(current, value, RED, nullptr);
                    //    current->left = end_element;
                        break;
                    } else if (current->left == end_element) {
                        // std::cout << "right element = end" << std::endl;
                        // вставляем элемент между текущим и конечным.
                        current->left = new_element;
                        current->left->parent = current;
                        current = current->left;
                        current = add_new_element(current, value, RED, nullptr);
                        current->left = end_element;
                        
                        break;
                    }  else {
                        current = current->left;
                    }
                }
            }
            // if (flag == 0) {
            //     //std::cout << "Текущий самый маленький элемент" << current->data << std::endl;
                
            // }
        }
    
        // print_element(current);
        //std::cout << "pre-insert point" << std::endl;
    
        insert_case1(current);
        return current;
}

template <class Key>
typename BinaryTree<Key>::node *BinaryTree<Key>::create_service_element()
{
    node *service = new node();
    service->left = nullptr;
    service->right = nullptr;
    service->parent = nullptr;
    service->color = SERVICE;
    service->data = 0;
    return service;
}


#include "s21_Red_Blue.tpp"
#include "s21_additional_foos.tpp"


}