#include "s21_binary_tree.h"
#include <initializer_list>

namespace s21 {
    template <class Key>
    class multiset : public BinaryTree<Key> {
        public:
            using key_type = Key;
            using value_type = key_type;
        
            using const_reference = const Key &;
            using iterator = typename BinaryTree<Key>::iterator;
            using node_m = typename BinaryTree<Key>::node;
            // using const_iterator = typename BinaryTree<Key>::const_iterator;
            iterator insert(const value_type& value);

            multiset();
        //    multiset(std::initializer_list<value_type> const &items);
        //     multiset(const multiset &ms);
        //     multiset(multiset &&ms);
        //     ~multiset();
        //     operator=(multiset &&ms);
            iterator begin();
            iterator end();

        
        private:
            node_m * go_to_left(node_m * cur) {
                while (cur->left != nullptr)
                    cur = cur->left;
                return cur;
            }
            node_m * go_to_right(node_m * cur) {
               
                while (cur->right != nullptr)
                    cur = cur->right;
                return cur;
            }

        protected:

            // typename s21::BinaryTree<Key>::node *head;
    };


template <class Key>
typename BinaryTree<Key>::iterator multiset<Key>::begin() {
    node_m * goal = this->head_element;
    goal = go_to_left(goal);
    //Проверяем есть и повторные элемент 
    if (goal->right) {
        if (goal->right->data == goal->data) {
             Key check_value = goal->data;
            while (goal->right != nullptr) {
                if (goal->right->data != check_value) break;
                goal = goal->right;
            }
        }  else if (goal->right->left) {
            if (goal->data == goal->right->left->data) {
                goal = goal->right->left;
            }
            goal = go_to_left(goal);
        } 
    }
    iterator it;
    it.ptr_ = goal;
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator multiset<Key>::end(){
    node_m *goal = this->head_element;
    goal = go_to_right(goal);
    if (goal->right){
        if (goal->right->data == goal->data) {
            goal = go_to_right(goal);
        } 
        if (goal->right->left) {
            if (goal->data == goal->right->left->data) {
                goal = goal->right->left;
            }
            goal = go_to_right(goal);
        } 
    }
    iterator it;
    it.ptr_ = goal;
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::insert(const value_type& value) {
    iterator it;
    it.ptr_ =  this->insert_to_tree(value);
    return it;
}

template <class Key>
class BinaryTree<Key>::iterator
{
    friend BinaryTree;

public:
    reference operator*() {
        return ptr_->data;
    }

    iterator operator++()
    {
        // Сначала надо определить на какой ветке находится текущий поинтер
        //// первый случай если текущий элемент == мнимому элементу
        //// второй случай когда текущий элемент равен голове
        //// третий и четвертый случай это сравнения

    //if (head_element) {
        if (!this->ptr_) {
       // this->ptr_ = nullptr; //
        while (this->ptr_->right) this->ptr_ = this->ptr_->right;
        } else if ((!this->ptr_->parent ||
                    this->ptr_ == this->ptr_->parent->right) &&
                !this->ptr_->right) {
        while (this->ptr_->parent && this->ptr_->parent->right == this->ptr_)
            this->ptr_ = this->ptr_->parent;
        if (!this->ptr_->parent)
            this->ptr_ = nullptr;
        else
            this->ptr_ = this->ptr_->parent;
        } else {
        if (this->ptr_->right) {
            this->ptr_ = this->ptr_->right;
            while (this->ptr_->left) this->ptr_ = this->ptr_->left;
        } else {
            if (this->ptr_ == this->ptr_->parent->left)
            this->ptr_ = this->ptr_->parent;
            else
            this->ptr_ = this->ptr_->parent->parent;
        }
        }
//     } else {
//         this->ptr_ = nullptr;
//   }
  return *this;

        return *this;
    }

    bool operator!=(iterator in)
    {
        return in.ptr_ != this->ptr_;
    }

    iterator operator--()
    {
        std::cout << "33" << std::endl;
        while (ptr_->left != nullptr)
        {
            std::cout << "34" << std::endl;
            ptr_ = ptr_->left;
        }
        return *this;
    }
   
    //multiset<Key> *link_multi;
    node *ptr_;
};


}


#include "s21_m_constructor.tpp"