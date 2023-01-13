#ifndef __SRC_QUEUE_QUEUE_H__
#define __SRC_QUEUE_QUEUE_H__

#include "../list/s21_list.h"
#include <initializer_list>
namespace s21 {

template <class T>
class queue
{
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_t = unsigned long;

    queue();
    queue(std::initializer_list<value_type> const &items);
    queue(const queue &q) = default;
    queue(queue &&q) = default;
    ~queue();
    queue &operator=(queue &&q) = default;

     void push(const_reference value);
     void pop();
    void swap(queue &other);
     const_reference front();
     const_reference back();
     bool empty() const;
    size_t size();

private:
    list<T> obj;
};

// Constructors

template <class T>
queue<T>::queue() = default;
template <class T>
queue<T>::queue(std::initializer_list<T> const &items)
{
    for (auto it = items.begin(); it != items.end(); it++)
        obj.push_back(*it);
}



// template <class T>
// queue<T>::queue(queue &&q){
// obj = std::move(q.obj);
// }

template <class T>
queue<T>::~queue() = default;



////

// Methods
template <class T>
 void queue<T>::push(const_reference value)
{
    obj.push_back(value);
}

template <class T>
 void queue<T>::pop()
{
    if (obj.size() != 0)
        obj.pop_front();
}

template <class T>
void queue<T>::swap(queue &other)
{
    obj.swap(other.obj);
}

template <class T>
 const T &queue<T>::front()
{
    return *(obj.begin());
}

template <class T>
 const T &queue<T>::back()
{
    return *(--obj.end());
}

template <class T>
 bool queue<T>::empty() const
{
    return obj.empty();
}

template <class T>
unsigned long queue<T>::size()
{
    return obj.size();
}
}

#endif