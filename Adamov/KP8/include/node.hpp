#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
class List;
template<typename T>
class Iterator;

template<typename T>
class Node {
    friend class List<T>;
    friend class Iterator<T>;
private:
    T data;
    Node* next = nullptr;

public:
    Node() = default;
    explicit Node(const T& _data);
    Node(const T& _data, Node* _next);
    ~Node() = default;
};

#include "../src/node.cpp"
#endif // NODE_HPP
