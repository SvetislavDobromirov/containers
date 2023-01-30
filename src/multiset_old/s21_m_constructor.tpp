using namespace s21;

template <class Key>
multiset<Key>::multiset() : BinaryTree<Key>()
{
    // Мнимый элемент создается в конструкторе дерева
    if (this->head_element == nullptr)
    {
        std::cout << "Голова нулевая. Создаем мнимый.  " << std::endl;
    }
}

