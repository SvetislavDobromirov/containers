using namespace s21;

template <class T> void list<T>::unique() {
  element_list *now = head_of_list_;
  while (1) {
    if (now->next_ != nullptr) {
      if (now->data_ == now->next_->data_) {
        // Удаляем следующий элемент.
        //// Два случая:
        ////// следующий элемент последний
        ////// следующий элемент не последний
        if (now->next_->next_ == nullptr) {
          delete now->next_;
          now->next_ = nullptr;
          m_size--;
        } else {
          element_list *tmp_next = now->next_;
          now->next_ = tmp_next->next_;
          tmp_next->next_->before_ = now;
          delete tmp_next;
          m_size--;
        }
      } else {
        now = now->next_;
      }
    }
    if (now->next_ == end_of_list_)
      break;
  }
}

template <class T> void list<T>::reverse() noexcept {
  element_list *now = head_of_list_; // Now == head

  while (1) {
    // Если элемент first
    element_list *next = now->next_;
    if (now->before_ == nullptr) { // If element first
      now->before_ = now->next_;
      now->next_ = end_of_list_;
      end_of_list_->before_ = now;
    } else if (now->next_ == end_of_list_) { // If element end
      element_list *tmp = (now->before_);
      head_of_list_ = now;
      now->before_ = nullptr;
      now->next_ = tmp;
    } else {
      element_list *tmp = (now->before_);
      now->before_ = now->next_;
      now->next_ = tmp;
    }
    now = next;
    if (now == end_of_list_) {

      now->next_ = nullptr;
      break;
    }
  }
}

template <class T> void list<T>::clear() noexcept {
  //  If I will call this on empty list, what will happen?
  // will delete service element only // ok
  element_list *now = head_of_list_;
  while (1) {
    element_list *tmp = now;
    if (now == end_of_list_) {
      head_of_list_ = end_of_list_;
      head_of_list_->before_ = nullptr;
      break;
    };
    now = now->next_;
    delete tmp;
  }
  m_size = 0;
}

template <class T> void list<T>::merge(list &other) {
  // FOR CHECKING
  for (auto it = other.begin(); it != other.end(); it++)
    this->push_back(*it);
  other.clear();
}

template <class T> void list<T>::swap(list &other) noexcept {
  // Проверка на пустоты не предусмотрена в оригинале

  auto tmp_this_size = this->m_size;
  auto tmp_this_head = this->head_of_list_;
  auto tmp_end_of_list_ = this->end_of_list_;

  this->m_size = other.m_size;
  this->head_of_list_ = other.head_of_list_;
  this->end_of_list_ = other.end_of_list_;

  other.m_size = tmp_this_size;
  other.head_of_list_ = tmp_this_head;
  other.end_of_list_ = tmp_end_of_list_;
}

template <class T> size_t list<T>::size() const noexcept { return m_size; }

template <class T> size_t list<T>::max_size() const noexcept {
  return std::numeric_limits<std::ptrdiff_t>().max() / sizeof(element_list);
}

template <class T> bool list<T>::empty() const { return m_size ? 0 : 1; }

template <class T>
typename list<T>::ListIterator list<T>::insert(list<T>::ListIterator pos,
                                               list<T>::const_reference value) {
  if (pos.ptr_ == nullptr)
    throw std::out_of_range("Iterator does not belong to the given list");

  element_list *new_node = new element_list();
  new_node->data_ = value;

  // If iterator with last element
  if (pos.ptr_ == end_of_list_) {
    new_node->before_ = pos.ptr_->before_;
    new_node->next_ = pos.ptr_;
    // If list no elements
    if (pos.ptr_->before_ == nullptr)
      head_of_list_ = new_node;
    else
      pos.ptr_->before_->next_ = new_node;

    pos.ptr_->before_ = new_node;
  } else if (pos.ptr_ == head_of_list_ && pos.ptr_ != end_of_list_) {
    new_node->next_ = pos.ptr_;
    pos.ptr_->before_ = new_node;
    head_of_list_ = new_node;
  } else {
    new_node->before_ = pos.ptr_->before_;
    new_node->next_ = pos.ptr_;
    pos.ptr_->before_->next_ = new_node;
    pos.ptr_->before_ = new_node;
  }
  ++m_size;
  return pos--;
}
template <class T> void list<T>::erase(list<T>::ListIterator pos) {
  // Удаляем текущий по итератору элеиент из листа.
  // Не трогаем мнимый
  // Учитываем первый
  if (pos == end())
    throw std::out_of_range("Out of range in erase");
  if (pos == begin() && m_size > 0) {
    element_list *del = head_of_list_;
    head_of_list_ = head_of_list_->next_;
    delete del;
    --m_size;
  } else {
    element_list *next = pos.ptr_->next_;
    element_list *before = pos.ptr_->before_;
    pos.ptr_->before_->next_ = next;
    pos.ptr_->next_->before_ = before;
    delete pos.ptr_;
    --m_size;
  }
}

template <class T> typename list<T>::ListIterator list<T>::begin() {
  list::ListIterator it;
  it.ptr_ = head_of_list_;
  return it;
}

template <class T> typename list<T>::ListIterator list<T>::end() {
  list::ListIterator it;
  it.ptr_ = end_of_list_;
  return it;
}

template <class T> const T &list<T>::front() { return head_of_list_->data_; }

template <class T> const T &list<T>::back() {
  return end_of_list_ == head_of_list_ ? head_of_list_->data_
                                       : end_of_list_->before_->data_;
}

template <class T> void list<T>::splice(const_iterator pos, list &other) {

  // Чекаем является ли входящий список пустой
  if (other.head_of_list_ == end_of_list_)
    return;
  // Чекаем корректеность итератора (является ли он конечным)
  if (pos.ptr_ == end().ptr_)
    return;

  // Если все ок, запускаем балалайку.
  // Запоминаем следующий элемент
  element_list *next = pos.ptr_->next_;

  // Создаем первое соединение
  pos.ptr_->next_ = other.head_of_list_;
  other.head_of_list_->before_ = pos.ptr_;

  // Создаем второе соединение
  other.end_of_list_->before_->next_ = next;
  next->before_ = other.end_of_list_->before_;

  // увеличиваем size
  m_size += other.m_size;

  // Зачищаем хвосты
  delete[] other.end_of_list_;
  other.head_of_list_ = nullptr;
  other.end_of_list_ = nullptr;
  other.m_size = 0;
}

template <class T>
template <class... Args>
void list<T>::emplace_back(Args &&... args) {
  vector<T> temp{args...};
  auto it = temp.begin();
  for (it; it != temp.end(); it++) {
    this->push_back(*it);
  }
}

template <class T>
template <class... Args>
void list<T>::emplace_front(Args &&... args) {
  vector<T> temp{args...};
  auto it = temp.end() - 1;
  for (it; it != temp.begin() - 1; it--) {
    this->push_front(*it);
  }
}

template <class T>
template <typename... Args>
typename list<T>::iterator list<T>::emplace(iterator pos, Args &&... args) {
  vector<T> temp{args...};
  auto it = temp.begin();
  s21::list<T>::iterator it_ret;
  for (it; it != temp.end(); it++) {
    it_ret = this->insert(pos, *it);
    std::cout << "274: " << *it << std::endl;
  }

  return it_ret;
}
