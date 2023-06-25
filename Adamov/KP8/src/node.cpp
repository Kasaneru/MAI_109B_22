#include "../include/node.hpp"

template<typename T>
Node<T>::Node(const T& _data) {
    data = _data;
}

template<typename T>
Node<T>::Node(const T& _data, Node* _next) {
    data = _data;
    next = _next;
}
