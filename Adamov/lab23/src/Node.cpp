#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T &data) {
    this->data = data;
}

template<typename T>
Node<T>::Node(const T &data, Node<T>* left, Node<T>* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}

template<typename T>
T Node<T>::get_data() const {
    return this->data;
}
