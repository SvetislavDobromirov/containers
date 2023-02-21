#include <iostream>
#include <initializer_list>

namespace s21 {


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
            // 	int key;
         	unsigned char height;
 //          enum node_colors color;
            Element(Key k) { data = k; left = right = 0; height = 1; }
        } node;

       node *get_head() { return head_element; }; // TEST
        node *head_element;
    private:
     //   node *add_new_element(node *current, Key Value, node_colors color, node *service);

    protected:
        
        node *create_service_element(); // Создаем мнимый элемент при инициализации
        
        int insert_element(const value_type &value);
        node *insert_to_tree(const value_type &value);
        
        void print_element(node *El);
        unsigned char height(node* p);
        int bfactor(node* p);
        void fixheight(node* p);
        node* rotateright(node* p);
        node* rotateleft(node* q); // левый поворот вокруг q
        node* balance(node* p); // балансировка узла p
        node* insert_avl(   node* p, 
                            Key k, 
			                node* merge_node, 
                            node **head_other, 
                            node** current); // вставка ключа k в дерево с корнем p
        node* findmin(node* p); // поиск узла с минимальным ключом в дереве p 
        node* removemin(node* p); // удаление узла с минимальным ключом из дерева p
        node* remove(node* p, const Key& k, bool del); // удаление ключа k из дерева p

        //TODO:: убрать?
        void dump2(node  *node_);
};


template <class Key>
BinaryTree<Key>::BinaryTree() {
        this->head_element = nullptr;
}



template <class Key>
typename BinaryTree<Key>::node *BinaryTree<Key>::insert_to_tree(const value_type &value)
{

      node *current = nullptr;
       this->head_element =  insert_avl(this->head_element, value, nullptr, nullptr, &current);
        this->head_element->parent = nullptr;
        // TODO:return current element
    return current;
}




//#include "s21_Red_Blue.tpp"
#include "s21_AVL.tpp"
#include "s21_additional_foos.tpp"


}