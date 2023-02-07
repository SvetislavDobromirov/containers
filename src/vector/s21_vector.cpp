#include "s21_vector.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>

// Constrictors and destructors

template <class T>
vector<T>::vector() : m_size(0),
    m_capacity(1), arr(nullptr) {
    arr = new T[m_capacity];
}

template <class T>
vector<T>::vector(size_t n) : m_size(n) {
    m_capacity = size_type(pow(2, ceil(log2(n))));
arr = new T[m_capacity];
};


template <class T>
vector<T>::vector(std::initializer_list<T> const &items) {
    m_capacity = size_type(pow(2, ceil(log2(items.size()))));
    m_size = items.size();
    arr = new T[m_capacity];
    unsigned long count = 0;
    for (auto p = items.begin(); p != items.end(); p++)
        *(arr+count++) = *p;
}

template <class T>
vector<T>::vector(const vector &other) :
        m_size(other.m_size),
        m_capacity(other.m_capacity) {
    arr = new T[m_capacity];
    memcpy(arr, other.arr, m_size * sizeof(T));
}



template <class T>
vector<T>::~vector()  { delete[] arr; }

template <class T>
vector<T>& vector<T>::operator=(vector &&other)  {
    if (this != &other) {
       std::swap(this->arr, other.arr);
       std::swap(this->m_size, other.m_size);
        std::swap(this->m_capacity, other.m_capacity);
    }
    return *this;
}

template <class T>
vector<T>::vector(vector &&other) : vector(){
  *this = std::move(other);
}
/// 

template <class T>
void vector<T>::add_memory() {
    T *tmp = new T[m_capacity+2]; 
    //ЕTODO:
    if (m_capacity < m_size)
        exit(1);
    
    for(unsigned long int i = 0; i < m_size; i ++)
        tmp[i] = arr[i];

    std::swap(arr, tmp);
    delete [] tmp;
}

// методы вызова
template <class T>
T& vector<T>::operator[](size_t index) {
    if (index > m_size ) throw std::out_of_range("Out of range");
    return *(arr + index);
}

template <class T>
 T& vector<T>::at(size_t index) {
    if (index > m_size ) throw std::out_of_range("Out of range");
    return *(arr + index);
}

template <class T>
 const T & vector<T>::front() noexcept {
    return *arr;
}

template <class T>
 const T & vector<T>::back() noexcept {
    return *(arr + m_size - 1);
}
////

template <class T>
 T* vector<T>::data() noexcept {
    return arr;
}

template <class T>
 void vector<T>::push_back(const T& new_element) {
    if (m_size >= m_capacity) {
        m_capacity *= 2;
        add_memory();
    }
    arr[m_size] = new_element;
    m_size++;
}

template <class T>
 void vector<T>::pop_back() noexcept {
    if (m_size > 0) m_size--;
}


// vector Capacity
template <class T>
 bool vector<T>::empty() noexcept {
    return m_size == 0 ? 1 : 0;
}

template <class T>
 void vector<T>::clear() noexcept {
    m_size = 0;
}

template <class T>
 size_t vector<T>::size() noexcept {
    return m_size;
}

template <class T>
 size_t vector<T>::capacity() noexcept { 
    return m_capacity; 
};

template <class T>
 size_t vector<T>::max_size() noexcept {
    size_t pppow = 2;
    for (long unsigned int  i = 0; i < 64-sizeof(T); i++) pppow = pppow*2;
    return (pppow - 1);
}


// vector Iterators
template <class T>
 T* vector<T>::begin () noexcept {
   
    return arr;
}

template <class T>
 T* vector<T>::end () noexcept {
    return arr+m_size;
}



template <class T>
void vector<T>::reserve(size_t __n) {
    if (__n > m_size) {
        m_capacity = __n;
        add_memory();
    }
}

template <class T>
 void vector<T>::shrink_to_fit() {
    m_capacity = m_size;
    add_memory();
}

template <class T>
T*  vector<T>::insert(iterator pos, const_reference value) noexcept{
    if (m_size >= m_capacity) {
        m_capacity *= 2;
        add_memory();
    }

    m_size++;
    T temp1 = 0, temp2 = value;
    T* ret = pos;
    for (int i = 0; pos+i != end(); ) {
        temp1 =  *(pos+i); 
        *(pos+i) = temp2; 
        i++;
        if (pos+i == end()) break;
        temp2 = *(pos+i); 
       *(pos+i) = temp1;
        i++;
        std::cout << "SSS: "<< *pos << std::endl;
    }    
    return pos;
}
