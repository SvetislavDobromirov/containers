using namespace s21;


template <class T>
list<T>::list() :  m_size(0) {
    head_of_list_ = new element_list();
    head_of_list_->next_ = nullptr;
    head_of_list_->before_ = nullptr;
    //head_of_list_->data_ = 0;
    end_of_list_ = head_of_list_;
}


template<class T>
list<T>::list(const list &other) : list() {
  // Конструктор копирования 
  // При копировании создадим новый лист и скопируем в него все элементы
  // Копируем каждый объект и создаем ноду
  
  element_list * now = other.head_of_list_;
  for (size_t i = 0; i < other.m_size; i++) {
    this->push_back(now->data_);
    now = now->next_;
  }
}



template <class T>
list<T>::list(std::initializer_list<T> const &items) : list() {
  for (auto p = items.begin(); p != items.end(); p++)
    push_back(*p);
}

template <class T>
list<T>::list(size_type n) : list() {

  for (size_t i = 0; i < n; i++) push_back(0);
}

template <class T>
list<T>::~list() {
  if (m_size > 0) this->clear();  
  if (end_of_list_ != nullptr) delete end_of_list_;
}

template <class T>
list<T>::list(list &&l) : list() {
     *this = (list<T> &&) l;
}

template <class T>
list<T>& list<T>::operator= (list &&l) {

  if (this != &l) {
    std::swap(m_size, l.m_size);
    std::swap(head_of_list_, l.head_of_list_);
    std::swap(end_of_list_, l.end_of_list_);
  }
  return *this;
}

