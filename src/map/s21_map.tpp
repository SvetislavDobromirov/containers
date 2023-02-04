#include "s21_map.h"

namespace s21 {

    template<class Key, class T>
    map<Key, T>::map(const map &other) : set<std::pair<Key, T>>(other) { }

    template<class Key, class T>
    map<Key, T>::map(map &&other) noexcept : set<std::pair<Key, T>>(std::move(other)) { }

    template<class Key, class T>
    std::pair<typename set<std::pair<Key, T>>::iterator, bool> map<Key, T>::insert_or_assign(const Key &key, const T &obj) {
        bool flag = true;
        std::pair<typename set<std::pair<Key, T>>::iterator, bool> result_pair;
        for (auto it = set<value_type>::begin(); it != set<value_type>::end(); it++) {
            if ((*it).first == key) {
                at(key) = obj;
                flag = false;
                result_pair.second = false;
                result_pair.first = it;
                break;
            }
        }
        
        if (flag) {
            result_pair = set<value_type>::insert({key, obj});
        }

        return result_pair;
    }

    template<class Key, class T>
    std::pair<typename set<std::pair<Key, T>>::iterator, bool> map<Key, T>::insert(const key_type &key, const mapped_type &obj) {
        return set<value_type>::insert({key, obj});
    }

    template<class Key, class T>
    std::pair<typename set<std::pair<Key, T>>::iterator, bool> map<Key, T>::insert(const map::value_type &value) {
        return set<value_type>::insert({value.first, value.second});
    }

    template<class Key, class T>
    T &map<Key, T>::operator[](const key_type &key) {
        try {
            return at(key);
        } catch (...) {
            set<value_type>::insert({key, mapped_type()});
            return at(key);
        }
    }

    template<class Key, class T>
    T &map<Key, T>::at(const key_type &key) {
        iterator result;

        typename tree<value_type>::node *current_node = tree<value_type>::root_;
        bool success = false;
        while (current_node != nullptr) {
            if (key > current_node->node_data.first) {
                current_node = current_node->right_node;
            } else if (key < current_node->node_data.first) {
                current_node = current_node->left_node;
            } else {
                result.it_current_node = current_node;
                success = true;
                break;
            }
        }
        if (!success) {
            throw std::out_of_range("mapped_type &at(const key_type &key), key is invalid");
        }

        return result.it_current_node->node_data.second;
    }

    template<class Key, class T>
    bool map<Key, T>::contains(const key_type &key) {
        typename tree<value_type>::node *current_node = tree<value_type>::root_;
        while (current_node != nullptr) {
            if (key > current_node->node_data.first) {
                current_node = current_node->right_node;
            } else if (key < current_node->node_data.first) {
                current_node = current_node->left_node;
            } else {
                return true;
            }
        }

        return false;
    }

    template<class Key, class T>
    map<Key, T>::map(const std::initializer_list<value_type> &items):set<value_type>(items) {
        tree<value_type>::root_ = nullptr;
        tree<value_type>::size_ = 0;
        for (auto p = items.begin(); p != items.end(); p++) {
            insert((*p).first, (*p).second);
        }
    }

}  // namespace s21
