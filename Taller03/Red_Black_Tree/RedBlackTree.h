
/********************************************************
 Fecha: 18 de marzo de 2025

 Materia: Estructura de Datos.
 Tema: Arboles Red-Black
 Pontificia Universidad Javeriana
 Archivo: RedBlackTree.h
 ********************************************************/
#ifndef RedBlackTree_h
#define RedBlackTree_h
#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    explicit Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void fixInsert(Node* z);
    void transplant(Node* u, Node* v);
    void deleteNode(Node* z);
    void fixDelete(Node* x);
    Node* minimum(Node* node);
    void printHelper(Node* root, int space);

    void inOrderHelper(Node* node);
    void preOrderHelper(Node* node);
    void postOrderHelper(Node* node);

public:
    RedBlackTree();

    void insert(int val);
    void remove(int val);
    void printTree();

    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
};

// Implementación de métodos

RedBlackTree::RedBlackTree() : root(nullptr) {}

void RedBlackTree::leftRotate(Node* x) {
    if (x == nullptr || x->right == nullptr) return;

    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node* y) {
    if (y == nullptr || y->left == nullptr) return;

    Node* x = y->left;
    y->left = x->right;
    if (x->right != nullptr) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr) root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void RedBlackTree::fixInsert(Node* z) {
    while (z != root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if (v != nullptr) v->parent = u->parent;
}

Node* RedBlackTree::minimum(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

void RedBlackTree::deleteNode(Node* z) {
    if (z == nullptr) return;

    Node* y = z;
    Node* x = nullptr;
    Color y_original_color = y->color;

    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            if (y->right) y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        if (y->left) y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK && x != nullptr)
        fixDelete(x);

    delete z;
}

void RedBlackTree::fixDelete(Node* x) {
    while (x != root && x != nullptr && x->color == BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w->left == nullptr || w->left->color == BLACK) &&
                (w->right == nullptr || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right == nullptr || w->right->color == BLACK) {
                    if (w->left) w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right) w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == BLACK) &&
                (w->left == nullptr || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left == nullptr || w->left->color == BLACK) {
                    if (w->right) w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left) w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    if (x != nullptr) x->color = BLACK;
}

void RedBlackTree::printHelper(Node* root, int space) {
    constexpr int COUNT = 5;
    if (root == nullptr) return;
    space += COUNT;
    printHelper(root->right, space);
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++) std::cout << " ";
    std::cout << root->data << "(" << ((root->color == RED) ? "RED" : "BLACK") << ")" << std::endl;
    printHelper(root->left, space);
}

void RedBlackTree::insert(int val) {
    Node* newNode = new Node(val);
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (newNode->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    newNode->parent = y;
    if (y == nullptr)
        root = newNode;
    else if (newNode->data < y->data)
        y->left = newNode;
    else
        y->right = newNode;

    fixInsert(newNode);
}

void RedBlackTree::remove(int val) {
    Node* z = root;
    while (z != nullptr) {
        if (val < z->data) z = z->left;
        else if (val > z->data) z = z->right;
        else {
            deleteNode(z);
            return;
        }
    }
    std::cout << "Node with value " << val << " not found in the tree." << std::endl;
}

void RedBlackTree::printTree() {
    printHelper(root, 0);
}

void RedBlackTree::inOrderTraversal() {
    inOrderHelper(root);
    std::cout << std::endl;
}

void RedBlackTree::preOrderTraversal() {
    preOrderHelper(root);
    std::cout << std::endl;
}

void RedBlackTree::postOrderTraversal() {
    postOrderHelper(root);
    std::cout << std::endl;
}

void RedBlackTree::inOrderHelper(Node* node) {
    if (node == nullptr) return;
    inOrderHelper(node->left);
    std::cout << node->data << " ";
    inOrderHelper(node->right);
}

void RedBlackTree::preOrderHelper(Node* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    preOrderHelper(node->left);
    preOrderHelper(node->right);
}

void RedBlackTree::postOrderHelper(Node* node) {
    if (node == nullptr) return;
    postOrderHelper(node->left);
    postOrderHelper(node->right);
    std::cout << node->data << " ";
}

#endif
