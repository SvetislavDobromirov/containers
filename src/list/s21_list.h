#ifndef __SRC_LIST_S21_VECTOR_H__
#define __SRC_LIST_S21_VECTOR_H__

#include <iostream>
#include <stdio.h>
#include <initializer_list>
#include <limits>

namespace s21
{
    template <class T>
    class list
    {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;

        using size_type = size_t;
        using difference_type = std::ptrdiff_t;

        list();
        list(const list &l);
        list(std::initializer_list<T> const &items);
        list &operator=(list &&l);
        list(list &&l);
        list(size_type n);

        ~list();

        void push_front(const_reference value);
        void push_back(const_reference value);
        void pop_front();
        void pop_back();
        void sort();
        void unique();
        void reverse() noexcept;
        void merge(list &other);
        void swap(list &other) noexcept;
        void clear() noexcept;

        const_reference front();
        const_reference back();

        size_type size() const noexcept;
        size_type max_size() const noexcept;
        bool empty() const;

    private:
        size_type m_size;
        typedef struct Element
        {
            struct Element *before_;
            struct Element *next_;
            T data_;
        } element_list;

        element_list *head_of_list_;
        element_list *end_of_list_;

        void swap_elements(element_list *a, element_list *b);

    public:
        class ListIterator
        {
            friend list;

        public:
            element_list *Data() { return ptr_; };

            ListIterator(){};
            
            ListIterator operator--()
            {
                ptr_ = ptr_->before_;
                return *this;
            }

            ListIterator operator--(int i)
            {
                i = 0;
                i++;
                ListIterator tmp(*this);
                ptr_ = ptr_->before_;
                return tmp;
            }

            ListIterator operator++()
            {
                ptr_ = ptr_->next_;
                return *this;
            }

            ListIterator operator++(int i)
            {
                i = 0;
                i++;
                ListIterator tmp(*this);
                ptr_ = ptr_->next_;
                return tmp;
            }

            reference operator*()
            {
                return this->Data()->data_;
            }

            bool operator!=(const ListIterator &other) const
            {
                return this->ptr_ != other.ptr_;
            }
            bool operator==(const ListIterator &other) const
            {
                return this->ptr_ == other.ptr_;
            }

        protected:
            element_list *ptr_;
        };

        class ListConstIterator
        {
            friend list;

        public:
            element_list *Data() { return ptr_; };

            ListConstIterator(){};

            ListConstIterator operator--() const
            {
                ptr_ = ptr_->before_;
                return *this;
            }

            ListConstIterator(list<T>::ListIterator l) : ptr_(l.ptr_) {}

            ListConstIterator
            operator--(int i) const
            {
                i = 0;
                ListIterator tmp(*this);
                ptr_ = ptr_->before_;
                return tmp;
            }

            ListConstIterator operator++() const
            {
                ptr_ = ptr_->next_;
                return *this;
            }

            ListConstIterator operator++(int i) const
            {
                i = 0;
                ListIterator tmp(*this);
                ptr_ = ptr_->next_;
                return tmp;
            }

            const_reference operator*() const
            {
                return this->Data()->data_;
            }

            bool operator!=(const ListConstIterator &other) const
            {
                return this->ptr_ != other.ptr_;
            }
            bool operator==(const ListConstIterator &other) const
            {
                return this->ptr_ == other.ptr_;
            }

            template <typename... Args>
            iterator emplace(const_iterator pos, Args&&... args);
            template <typename... Args>
            void emplace_back(Args&&... args);
            template <typename... Args>
            void emplace_front(Args&&... args);

        protected:
            element_list *ptr_;
        };

        using iterator = ListIterator;
        using const_iterator = ListConstIterator;

        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;

        void splice(const_iterator pos, list &other);
        iterator insert(iterator pos, const_reference value);
        void erase(iterator pos);
    };

}

#include "s21_list_methods.tpp"
#include "s21_list_class.tpp"
#include "s21_list_pop_push.tpp"
#include "s21_list_sort.tpp"
#endif