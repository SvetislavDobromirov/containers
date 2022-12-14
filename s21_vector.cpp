#include "s21_vector.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>

// Constrictors and destructors

template <class T>
Vector<T>::Vector() : m_size(0),
    m_capacity(1), arr(nullptr) {
    // Выделить память под одну ячейку
    arr = new T(m_capacity);
}

template <class T>
Vector<T>::Vector(size_t n) : m_size(n) {
    m_capacity = ceil(log2(m_size));
    arr = new T(m_capacity);
};




template <class T>
Vector<T>::Vector(std::initializer_list<T> const &items) {
    // NO TESTING
    m_capacity = int(pow(2, ceil(log2(items.size()))));
    m_size = items.size();
    arr = new T(m_capacity);
    T* p_arr = arr;
    for (auto p = items.begin(); p != items.end(); p++)
        *p_arr++ = *p;
}

template <class T>
Vector<T>::Vector(const Vector &other) :
        m_size(other.m_size),
        m_capacity(other.m_capacity) {
    arr = new T(m_capacity);
    memcpy(arr, other.arr, m_size * sizeof(T));
}



template <class T>
Vector<T>::~Vector()  { delete[] arr; }

template <class T>
void Vector<T>::operator=(Vector &&other) {
    if (this != &other) { // Not fully correct, but should work
        if (this->arr) delete[] arr;
        this->arr = other.arr;
        this->m_size = other.m_size;
        this->m_capacity = other.m_capacity;
        other.m_size = 0;
        other.m_capacity = 1;
        other.arr = nullptr;
    }
}

template <class T>
Vector<T>::Vector(Vector &&other) {
  *this = other;
}
/// 

template <class T>
void Vector<T>::add_memory() {

    // CHECK FORMULA!!!
    
   //  T* tmp = operator new (tmp, m_capacity); 
    T* tmp = new T[m_capacity]; 

    memcpy(tmp, arr, m_size* sizeof(T));
   
    delete[] arr;
    arr = tmp;
 
    
}

// методы вызова
template <class T>
T& Vector<T>::operator[](size_t index) {
    if (index > m_size || index < 0) throw std::out_of_range("Out of range");
    return *(arr + index);
}

template <class T>
inline T& Vector<T>::at(size_t index) {
    if (index > m_size || index < 0 ) throw std::out_of_range("Out of range");
    return *(arr + index);
}

template <class T>
inline const T & Vector<T>::front() noexcept {
    return *arr;
}

template <class T>
inline const T & Vector<T>::back() noexcept {
    return *(arr + m_size - 1);
}
////

template <class T>
inline T* Vector<T>::data() noexcept {
    return arr;
}

template <class T>
inline void Vector<T>::push_back(const T& new_element) {
    // NEED FOR CHECK
    if (m_size >= m_capacity) {
        m_capacity *= 2;
        m_capacity = int(pow(2, ceil(log2(m_size))));
        add_memory();
    }
    arr[m_size] = new_element;
    m_size++;
}

template <class T>
inline void Vector<T>::pop_back() noexcept {
    if (m_size > 0) m_size--;
}


// Vector Capacity
template <class T>
inline bool Vector<T>::empty() noexcept {
    return m_size == 0 ? 1 : 0;
}

template <class T>
inline void Vector<T>::clear() noexcept {
    m_size = 0;
}

template <class T>
inline size_t Vector<T>::size() noexcept {
    return m_size;
}

template <class T>
inline size_t Vector<T>::capacity() noexcept { 
    return m_capacity; 
};

template <class T>
inline size_t Vector<T>::max_size() noexcept {
    size_t pppow = 2;
    for (int i = 0; i < 64-sizeof(T); i++) pppow = pppow*2;
    return (pppow - 1);
}


// Vector Iterators
template <class T>
inline T* Vector<T>::begin () noexcept {
    // NO TESTING
   // std::iterator it = arr;
    return arr;
}

template <class T>
inline T* Vector<T>::end () noexcept {
    // NO TESTING 
    //std::iterator it = arr+m_size;
    return arr+m_size;
}
//


template <class T>
void Vector<T>::reserve(size_t __n) {
    // NO TESTING
    if (__n > m_size) {
        m_capacity = __n;
        add_memory();
    }
}

template <class T>
inline void Vector<T>::shrink_to_fit() {
    // NO TESTING
    m_capacity = m_size;
    add_memory();
}