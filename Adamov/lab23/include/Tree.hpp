#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"

template<typename T>
class Tree {
private:
    Node<T>* root = nullptr;
public:
    Tree() = default;
    Tree(const T& data);

    Node<T>* get_root();

    void insert_node(Node<T>* pred, const T& new_data);
    Node<T>* get_min_node(Node<T>* node);
    Node<T>* delete_node(Node<T>* node, const T& data);
    void print_tree(Node<T>* node) const;
    void bypass() const;

    Node<T>* get_min_depth_node(Node<T>* node);
    Node<T>* bypass_min_depth_node(Node<T>* node, Node<T>* min_depth_node);

    void delete_tree(Node<T>* node);
    ~Tree();
};

#include "../src/Tree.cpp"

#endif
