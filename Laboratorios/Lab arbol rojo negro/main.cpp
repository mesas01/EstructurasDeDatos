// main.cpp
#include <iostream>
#include "rbtree.h"

int main() {
    RBTree tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    std::cout << "Inorder Traversal of Created Tree\n";
    tree.inorder();

    std::cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    std::cout << "\n";

    return 0;
}
