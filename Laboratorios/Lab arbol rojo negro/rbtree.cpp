// rbtree.cpp
#include <iostream>
#include <queue>
#include <algorithm>
#include "rbtree.h"

using namespace std;

// Implementación del constructor de Node
Node::Node(int data) {
    this->data = data;
    color = RED;
    left = right = parent = nullptr;
}

// Constructor de RBTree
RBTree::RBTree() {
    root = nullptr;
}

// Rotación a la izquierda
void RBTree::rotateLeft(Node*& root, Node*& pt) {
    Node* pt_right = pt->right;
    pt->right = pt_right->left;

    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

// Rotación a la derecha
void RBTree::rotateRight(Node*& root, Node*& pt) {
    Node* pt_left = pt->left;
    pt->left = pt_left->right;

    if (pt->left != nullptr)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

// Arregla las violaciones del árbol rojo-negro después de insertar
void RBTree::fixViolation(Node*& root, Node*& pt) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED)) {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            Node* uncle_pt = grand_parent_pt->right;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            Node* uncle_pt = grand_parent_pt->left;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

// Inserción estilo BST
Node* RBTree::BSTInsert(Node* root, Node* pt) {
    if (root == nullptr)
        return pt;

    if (pt->data < root->data) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->data > root->data) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    return root;
}

// Recorrido inorden
void RBTree::inorderHelper(Node* root) {
    if (root == nullptr) return;
    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}

// Recorrido por niveles
void RBTree::levelOrderHelper(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << "  ";
        q.pop();

        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

// Inserción pública
void RBTree::insert(const int& data) {
    Node* pt = new Node(data);
    root = BSTInsert(root, pt);
    fixViolation(root, pt);
}

// Llamadas públicas de recorrido
void RBTree::inorder() {
    inorderHelper(root);
}

void RBTree::levelOrder() {
    levelOrderHelper(root);
}
