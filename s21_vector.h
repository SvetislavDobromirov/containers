#ifndef __SRC_S21_VECTOR_H__
#define __SRC_S21_VECTOR_H__


#define print cout
typedef unsigned long size_t;
#include <initializer_list>

#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>


template <class T>
class Vector {
    public:
        // members types
        using value_type = T;
        using reference = T&;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;

        // Constrictors and destructors
        Vector();
        Vector(size_type n);
        Vector(std::initializer_list<value_type> const &items);
        Vector(const Vector &other);
        Vector(Vector &&v);
        ~Vector();
        void operator=(Vector &&other);

        // методы вызова // Vector Element Access
        reference operator[](size_type index);
        inline reference at(size_type index);
        inline const_reference front() noexcept;
        inline const_reference back() noexcept;
        inline T* data() noexcept;

        inline void push_back(const_reference new_element);
        inline void pop_back() noexcept;

        // Vector Capacity
        inline void clear() noexcept;
        inline bool empty() noexcept;
        inline size_type size() noexcept;
        inline size_type max_size() noexcept;
        void reserve(size_type __n);
        inline void shrink_to_fit();
        inline size_type capacity() noexcept;
    

        // methods iterators
        inline iterator begin() noexcept;
        inline iterator end() noexcept;


    private:
        size_type m_size;
        size_type m_capacity;
        T *arr;
        void add_memory();
        void CopyC(Vector && other);
};


///

#include "s21_vector.cpp"
#endif