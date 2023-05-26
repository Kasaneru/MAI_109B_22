#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

template<typename T>
class Tree;

template<typename T>
class Node {
    friend class Tree<T>;
private:
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
    size_t depth = 0;
public:
    Node() = default;
    Node(const T& data);
    Node(const T& data, Node* left, Node* right);

    T get_data() const;
    
    ~Node() = default;
};

#include "../src/Node.cpp"

#endif
