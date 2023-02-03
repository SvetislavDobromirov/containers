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
            void erase(iterator pos) ;
            multiset();
            multiset(std::initializer_list<value_type> const &items);
        //     multiset(const multiset &ms);
        //     multiset(multiset &&ms);
        //     ~multiset();
        //     operator=(multiset &&ms);
            iterator begin();
            iterator end();

        
        private:
            node_m * go_to_left(node_m * cur) {
                while (cur->left != nullptr && cur->left != this->end_element)
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
    iterator it;
    if (this->head_element != this->end_element) {
        node_m *goal = this->head_element;
        goal = go_to_left(goal);
        // Проверяем есть и повторные элемент
        if (goal->right) {
            if (goal->right->data == goal->data) {
                Key check_value = goal->data;
                while (goal->right != nullptr)
                {
                    if (goal->right->data != check_value)
                        break;
                    goal = goal->right;
                }
            }
            else if (goal->right->left) {
                if (goal->data == goal->right->left->data)
                {
                    goal = goal->right->left;
                }
                goal = go_to_left(goal);
            }
        }
        it.ptr_ = goal;
    } else {
        std::cout << "Not find element" << std::endl;
        it.ptr_ = this->end_element;
    }
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator multiset<Key>::end() {
    iterator it;
    // if (this->head_element != this->end_element)
    // {
    //     node_m *goal = this->head_element;
    //     goal = go_to_right(goal);
    //     if (goal->right) {
    //         if (goal->right->data == goal->data) {
    //             goal = go_to_right(goal);
    //         } 
    //         if (goal->right->left) {
    //             if (goal->data == goal->right->left->data) {
    //                 goal = goal->right->left;
    //             }
    //             goal = go_to_right(goal);
    //         } 
    //     }
    //     it.ptr_ = goal;
    // } else {
    //     it.ptr_ = this->end_element;
    // }
    it.ptr_ = this->end_element;
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::insert(const value_type& value) {
    iterator it;
    it.ptr_ =  this->insert_to_tree(value);
    return it;
}

template <class Key>
void multiset<Key>::erase(iterator pos) {
    /*
       // 1.Если удаление головы единственной 
    // 2. Если только два элемента и ...
    // 2.1. Если удаление только с левым или правым лепестком и
    // 3.  Если элемкнт является последним
    // 4. Если элемент с двумя леппксками +
    */
   node_m * current = pos.ptr_;

  if (current != this->end_element) { // Защита от пустого списка
        if (current == this->head_element && 
            current->left == this->end_element && 
            current->right == this->end_element) { // тогда элемент первый
            delete current;
            this->head_element = this->end_element;
            return;
        } else if ( (current->left == nullptr || current->left == this->end_element) &&
                    (current->right == nullptr || current->right == this->end_element) ) {
            std::cout << "Условие: конечный элемент" << std::endl;
            
            // Данный элемент последний. 
            // Удаляем, если есть на него ссылки у родителя,  занулем
            // Если элемент крайний, присваиваем родителю ссылки на end
            if (current->parent) { 
                // определяем что является концом для текущего
                node_m * end = nullptr;
                if (current->left == this->end_element || current->right == this->end_element)
                end = this->end_element; 

                if (current->color == RED ) {
             
                    // связываем ссылку родителя на текущий либо с нулем или конечным
                    current->parent->left == current ? current->parent->left = end : current->parent->right = end;
               
                } else {
                    this->delete_one_child(current);
                    //this->delete_case1(current);
                    std::cout << "149:: " << std::endl;

                  //  this->print_element(current);
                    return;

                    // std::cout << "147:: " << std::endl;

                    // if (current == current->parent->left) current->parent->left = end;
                    // else current->parent->right = end;


                    // this->print_element(current->parent);
                    // this->delete_case1(current->parent);


                    
                //return;
                }
               // delete current;
                return;
            } else {
                std::cout << " ERROR erase foo" << std::endl;
                return;
            }
        } else if ((current->left &&  current->right) &&
                   (current->left != this->end_element &&  current->right != this->end_element)) {
            std::cout << "Условие оба предка" << std::endl;
            node_m *largest_left_node = current->left;
            largest_left_node =  go_to_right(largest_left_node); // Заменить find_max_node?

            // Заменяем значения нод, но оставляем цвет
            Key temp = current->data;
            current->data = largest_left_node->data;
            largest_left_node->data = temp;

            current = largest_left_node;
            this->delete_one_child(current);
            
        } else if ( (current->left &&  (!current->right || current->right == this->end_element))  ||
        ((!current->left || current->left == this->end_element) &&  current->right) ){
            std::cout << "Условие один предок" << std::endl;

            this->delete_one_child(current);
        } else {
              std::cout << " ERROR erase foo 2  условие не должно активироваться" << std::endl;
        }


  } else {
    return; // Нельзя удалить мнимый элемент
  }



   ///
   
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