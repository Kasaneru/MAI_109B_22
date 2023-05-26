#include "../include/Tree.hpp"
#include <iostream>

// 4. Определить значение листа дваичного дерева, имеющего минимальную глубину

int main() {
    {
        Tree<int64_t> tree(8);
        tree.insert_node(tree.get_root(), 5);
        tree.insert_node(tree.get_root(), 11);
        tree.insert_node(tree.get_root(), 2);
        tree.insert_node(tree.get_root(), 1);
        tree.insert_node(tree.get_root(), 9);
        tree.insert_node(tree.get_root(), 8);
        tree.insert_node(tree.get_root(), 12);

        tree.print_tree(tree.get_root());
        Node<int64_t>* minimal = tree.get_min_depth_node(tree.get_root());
        std::cout << "Answer: " << minimal->get_data() << "\n\n";
    }
    {
        Tree<int64_t> tree(15);
        tree.insert_node(tree.get_root(), 10);
        tree.insert_node(tree.get_root(), 12);
        tree.insert_node(tree.get_root(), 14);
        tree.insert_node(tree.get_root(), 8);
        tree.insert_node(tree.get_root(), 4);
        tree.insert_node(tree.get_root(), 9);
        tree.insert_node(tree.get_root(), 18);

        tree.print_tree(tree.get_root());
        Node<int64_t>* minimal = tree.get_min_depth_node(tree.get_root());
        std::cout << "Answer: " << minimal->get_data() << "\n\n";
    }
    {
        Tree<int64_t> tree(4);
        tree.insert_node(tree.get_root(), 6);
        tree.insert_node(tree.get_root(), 5);
        tree.insert_node(tree.get_root(), 8);
        tree.insert_node(tree.get_root(), 7);
        tree.insert_node(tree.get_root(), 9);
        tree.insert_node(tree.get_root(), 3);

        tree.print_tree(tree.get_root());
        Node<int64_t>* minimal = tree.get_min_depth_node(tree.get_root());
        std::cout << "Answer: " << minimal->get_data() << '\n';
    }
}
