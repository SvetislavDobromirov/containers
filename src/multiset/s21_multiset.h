#include "s21_binary_tree.h"
#include <initializer_list>

namespace s21 {
    template <class Key>
    class multiset : public BinaryTree<Key>{
        public:
            using key_type = Key;
            using value_type = key_type;
        
            using const_reference = const Key &;
            using iterator = typename BinaryTree<Key>::iterator;
            using node_m = typename BinaryTree<Key>::node;
        // using const_iterator = typename BinaryTree<Key>::const_iterator;
            iterator insert(const value_type& value);

            multiset();
            multiset(std::initializer_list<value_type> const &items);
            //multiset(const multiset &ms);
            //multiset(multiset &&ms);
            //~multiset();
            //operator=(multiset &&ms);


            iterator begin();
            iterator end();

        
        private:
        // typename s21::BinaryTree<Key>::node *head;
    };

template <class Key>
multiset<Key>::multiset() : BinaryTree<Key>() {
    if (this->head_element  == nullptr) {
        std::cout << "Голова нулевая. Все под контролем" << std::endl;
    }
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::insert(const value_type& value) {
    // Надо обратиться к дереву и вставить новый элемент по правилам
    // Переходим к дереву, и кидаем в него элемент. Магия происходит внутри дерева
    if (this->head_element == nullptr) { // Если в дереве нет элементов, то помещаем в голову
        this->head_element = (node_m*) new (node_m);
        this->head_element->data = value;
        this->head_element->color = BLACK;
        this->head_element->left = nullptr;
        this->head_element->right = nullptr;       
    } else {
        // Запускаем функцию вставки в нужную ветвь дерева.
        this.insert_element(value);
    }
    auto it = BinaryTree<Key>::iterator();
    return it;
}


}
// template <class Key>
// multiset<Key>::multiset(std::initializer_list<value_type> const &items){
//     // Здесь есть смысл использовать insert 
// }



