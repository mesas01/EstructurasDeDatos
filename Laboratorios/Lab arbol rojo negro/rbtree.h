// rbtree.h
#pragma once
#include "node.hxx"

class RBTree {
private:
    Node* root;

    // Métodos auxiliares
    void rotateLeft(Node*& root, Node*& pt);
    void rotateRight(Node*& root, Node*& pt);
    void fixViolation(Node*& root, Node*& pt);
    void inorderHelper(Node* root);
    Node* BSTInsert(Node* root, Node* pt);
    void levelOrderHelper(Node* root);

public:
    // Constructor
    RBTree();

    // Métodos públicos
    void insert(const int& n);
    void inorder();
    void levelOrder();
};
