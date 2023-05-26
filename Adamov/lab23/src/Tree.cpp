#include "../include/Tree.hpp"
#include <iostream>
#include <cstddef>

template<typename T>
Tree<T>::Tree(const T& data) {
    this->root = new Node<T>(data);
}

template<typename T>
Node<T>* Tree<T>::get_root() {
    return this->root;
}

template<typename T>
void Tree<T>::insert_node(Node<T>* pred, const T& new_data) {
    if (pred == nullptr) {
        return;
    }
    if (pred->data > new_data) {
        if (pred->left == nullptr) {
            pred->left = new Node<T>(new_data);
            pred->left->depth = pred->depth + 1;
        } else {
            insert_node(pred->left, new_data);
        }
    }
    else if (pred->data <= new_data) {
        if (pred->right == nullptr) {
            pred->right = new Node<T>(new_data);
            pred->right->depth = pred->depth + 1;
        } else {
            insert_node(pred->right, new_data);
        }
    }
}

template<typename T>
Node<T>* Tree<T>::get_min_node(Node<T>* node) {
    Node<T>* min_node = node;
    while (min_node->left != nullptr) {
        min_node = min_node->left;
    }
    return min_node;
}

template<typename T>
Node<T>* Tree<T>::delete_node(Node<T>* node, const T& data) {
    if (node == nullptr) {
        return node;
    }
    else if (data < node->data) {
        node->left = delete_node(node->left, data);
    }
    else if (data > node->data) {
        node->right = delete_node(node->right, data);
    }
    else {
        if (node->left == nullptr and node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }
        Node<T>* temp = get_min_node(node->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data);
    }
    return node;
}

template<typename T>
void Tree<T>::print_tree(Node<T>* node) const {
    if (node == nullptr) {
        return;
    }
    print_tree(node->left);
    for (size_t cur_depth = 0; cur_depth < node->depth; ++cur_depth) {
        std::cout << '\t';
    }
    std::cout << node->get_data() << '\n';
    print_tree(node->right);
}

template<typename T>
Node<T>* Tree<T>::get_min_depth_node(Node<T>* node) {
    if (node == nullptr) {
        return node;
    }
    else if (node->left == nullptr and node->right == nullptr) {
        return node;
    }
    else { 
        return this->bypass_min_depth_node(node, nullptr);
    }
}

template<typename T>
Node<T>* Tree<T>::bypass_min_depth_node(Node<T>* node, Node<T>* min_depth_node) {
    if (node == nullptr) {
        return min_depth_node;
    }
    min_depth_node = bypass_min_depth_node(node->left, min_depth_node);
    if (node->left == nullptr and node->right == nullptr) {
        if (min_depth_node == nullptr) {
            min_depth_node = node;
        }
        else if (node->depth < min_depth_node->depth and node->depth != 0) {
            min_depth_node = node;
        }
    }
    min_depth_node = bypass_min_depth_node(node->right, min_depth_node);
    return min_depth_node;
} 

template<typename T>
void Tree<T>::delete_tree(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template<typename T>
Tree<T>::~Tree() {
    delete_tree(this->root);
    this->root = nullptr;
}
