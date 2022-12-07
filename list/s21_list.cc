


template <class T>
class S21_list {

    public:
        // members types
        using value_type = T;
        using reference = T&;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_t = unsigned long;

        S21_list();
        void push_back();

    private:
        iterator head;
        size_t m_size;

        class element {
            unsigned long number;
            iterator last;
            iterator next;
            T data;
        };
};

template <class T>
S21_list<T>::S21_list() : head(nullptr), m_size(0) {
}

template <class T>
void S21_list<T>::push_back() {
    // iterate from fisr

}


int main() {
    S21_list<int> element;
    return 0;
}