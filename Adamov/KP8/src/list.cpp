#include "../include/list.hpp"

template<typename T>
List<T>::List(const List<T>& other) {
    head = other.head;
    sz = other.sz;
}

template<typename T>
Iterator<T> List<T>::begin() {
    Iterator<T> beg(head);
    return beg;
}

template<typename T>
Iterator<T> List<T>::end() {
    Node<T>* last_node = head;
    while (last_node->next != head) {
        last_node = last_node->next;
    }
    return Iterator<T>(last_node);
}

template<typename T>
void List<T>::push_back(const T& data) {
    if (head == nullptr) {
        head = new Node<T>(data);
        head->next = head;
        ++sz;
        return;
    }
    Node<T>* last_node = this->end().get_node();
    Node<T>* new_node = new Node<T>(data, head);
    last_node->next = new_node;
    ++sz;
}

template<typename T>
void List<T>::push_front(const T& data) {
    if (head == nullptr) {
        head = new Node<T>(data);
        head->next = head;
        ++sz;
        return;
    }
    Node<T>* last_node = this->end().get_node();
    Node<T>* new_node = new Node<T>(data, head);
    head = new_node;
    last_node->next = head;
    ++sz;
}

template<typename T>
template<typename ...Args>
void List<T>::emplace_back(const T& first, const Args&... args) {
    this->push_back(T(args...));
}

template<typename T>
template<typename ...Args>
void List<T>::emplace_front(const T& first, const Args&... args) {
    this->push_front(T(args...));
}

template<typename T>
void List<T>::pop_back() {
    if (sz == 0) {
        return;
    }
    if (sz == 1) {
        delete head;
        head = nullptr;
        --sz;
        return;
    }
    Node<T>* pred_last_node = head;
    while (pred_last_node->next->next != head) {
        pred_last_node = pred_last_node->next;
    }
    Node<T>* last_node = pred_last_node->next;

    delete last_node;
    pred_last_node->next = head;
    --sz;
}

template<typename T>
void List<T>::pop_front() {
    if (sz == 0) {
        return;
    }
    if (sz == 1) {
        delete head;
        head = nullptr;
        --sz;
        return;
    }
    Node<T>* new_head = head->next;
    Node<T>* last_node = this->end().get_node();
    delete head;
    head = new_head;
    last_node->next = head;
    --sz;
}

template<typename T>
void List<T>::insert(const Iterator<T>& pos, const T& data) {
    pos.get_node()->next = new Node<T>(data, pos.get_node()->next);
}

template<typename T>
void List<T>::erase(const Iterator<T>& begin_pos, const Iterator<T>& end_pos) {
    Iterator<T> it = begin_pos;
    ++it;
    begin_pos.get_node()->next = end_pos.get_node();

    while (it != end_pos) {
        if (it == this->begin()) {
            head = end_pos.get_node();
        }
        Node<T>* deleted_node = it.get_node();
        ++it;
        delete deleted_node;
        --sz;
    }
}

template<typename T>
bool List<T>::empty() {
    return (sz == 0);
}

template<typename T>
void List<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

template<typename T>
bool List<T>::check_order() {
    Node<T>* cur_node = head;
    while (cur_node->next != head) {
        if (cur_node->data > cur_node->next->data)
            return false;
        cur_node = cur_node->next;
    }
    return true;
}

template<typename T>
std::ostream& List<T>::operator<<(std::ostream& out) {
    Node<T>* cur_node = head;
    while (cur_node->next != head) {
        out << cur_node->data << ' ';
        cur_node = cur_node->next;
    }
    out << cur_node->data << ' ';
    return out;
}

template<typename T>
List<T>::~List<T>() {
    if (head == nullptr)
        return;
    Node<T>* cur_node = head->next;
    while (cur_node != head) {
        Node<T>* temp = cur_node;
        cur_node = cur_node->next;
        delete temp;
    }
    delete head;
}
