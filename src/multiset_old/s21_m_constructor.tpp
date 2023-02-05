

using namespace s21;


template <class Key>
multiset<Key>::multiset() : BinaryTree<Key>()
{

        std::cout << "Голова нулевая. Создаем мнимый.  " << std::endl;
       // this->head_element = this->end_element =  this->create_service_element();

}

template <class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items) : BinaryTree<Key>()
{
  //  this->head_element = this->end_element = this->create_service_element();
    std::cout << "Конструктор параметризированный" << std::endl;
   for (auto p = items.begin(); p != items.end(); p++){
         this->insert_to_tree(*p);
   }
}