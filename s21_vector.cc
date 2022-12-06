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
    memcpy(arr, other.arr, sizeof(T));
}


template <class T>
Vector<T>::Vector(Vector &&other) {
    CopyC(other);
    // m_size(other.m_size), 
    // m_capacity(other.m_capacity), arr(other.arr) {
    // other.m_size = 0;
    // other.m_capacity = 0;
    // other.arr = nullptr;
}

template <class T>
Vector<T>::~Vector()  { delete[] arr; }

template <class T>
void Vector<T>::operator=(Vector &&other) {
    CopyC(other);
}

/// 

template <class T>
void Vector<T>::CopyC(Vector && other) {
    m_size =other.m_size, 
    m_capacity = other.m_capacity;
    arr = other.arr;
    other.m_size = 0;
    other.m_capacity = 0;
    other.arr = nullptr;
}

///

template <class T>
void Vector<T>::add_memory() {

    // CHECK FORMULA!!!
    T* tmp = new T(m_capacity); 
    if (arr != NULL) {
        memcpy(tmp, arr, sizeof(T));
        delete[] arr;
    }
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
        add_memory();
    }
    arr[m_size] = *new_element;
    m_size++;
}

template <class T>
inline void Vector<T>::pop_back() noexcept {
    if (m_size > 0) m_size--;
}


// Vector Capacity
template <class T>
inline bool Vector<T>::empty() noexcept {
    return m_size == 0 ? 0 : 1;
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
/*
int main() {
    Vector<int> obj{9,2,3};
    Vector<int> obj_vector(obj);

    for (auto p = obj.begin(); p != obj.end(); p++)
        std::cout << "d " << *p << std::endl;

   // std::cout << obj_vector.max_size() << std::endl;

   std::cout << obj_vector.empty() << std::endl;
    obj_vector.push_back(0);
    obj_vector.pop_back();
    std::cout << obj_vector.empty() << std::endl;
    obj_vector.push_back(8);
    //std::cout << (obj_vector.front()) << std::endl;
    //std::cout << (obj_vector.back()) << std::endl;
    std::cout << obj_vector.empty() << std::endl;
 

    //std::cout << "size: " << obj_vector.size() << endl;
    //std::cout << obj_vector[1];

   // std::cout << 

    
    
    return 0;
}*/