/********************************************************
 Fecha: 02 de abril de 2025
 Autores: Santiago Mesa
 Materia: Estructura de Datos.
 Tema: Árbol rojo negro
 Pontificia Universidad Javeriana
 Archivo: rbtree.cpp
 ********************************************************/

 #include <iostream>
 #include <queue>
 #include <algorithm>
 #include "rbtree.h"
 
 using namespace std;
 
 // Constructor de Nodo: inicializa un nuevo nodo con el dato proporcionado
 // Por defecto, los nuevos nodos son ROJOS en un árbol rojo-negro
 Node::Node(int data) {
     this->data = data;
     color = RED;
     left = right = parent = nullptr;
 }
 
 // Constructor del árbol: inicializa un árbol vacío
 RBTree::RBTree() {
     root = nullptr;
 }
 
 // Realiza una rotación hacia la izquierda en el árbol
 // Esta operación es fundamental para mantener el balance del árbol
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
 
 // Realiza una rotación hacia la derecha en el árbol
 // Operación simétrica a rotateLeft
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
 
 // Corrige las violaciones de las propiedades del árbol rojo-negro después de una inserción
 // Las propiedades incluyen: raíz negra, nodos rojos no pueden tener hijos rojos, etc.
 void RBTree::fixViolation(Node*& root, Node*& pt) {
     Node *parent_pt = nullptr;
     Node *grand_parent_pt = nullptr;
 
     while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
         parent_pt = pt->parent;
         grand_parent_pt = pt->parent->parent;
 
         // Caso 1: El padre es hijo izquierdo del abuelo
         if (parent_pt == grand_parent_pt->left) {
             Node* uncle_pt = grand_parent_pt->right;
 
             // Caso 1.1: El tío es rojo - solo recoloración
             if (uncle_pt != nullptr && uncle_pt->color == RED) {
                 grand_parent_pt->color = RED;
                 parent_pt->color = BLACK;
                 uncle_pt->color = BLACK;
                 pt = grand_parent_pt;
             } else {
                 // Caso 1.2: El tío es negro
                 if (pt == parent_pt->right) {
                     rotateLeft(root, parent_pt);
                     pt = parent_pt;
                     parent_pt = pt->parent;
                 }
                 rotateRight(root, grand_parent_pt);
                 swap(parent_pt->color, grand_parent_pt->color);
                 pt = parent_pt;
             }
         }
         // Caso 2: El padre es hijo derecho del abuelo (simétrico al caso 1)
         else {
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
 
     // Asegura que la raíz siempre sea negra
     root->color = BLACK;
 }
 
 // Realiza una inserción normal de BST (árbol binario de búsqueda)
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
 
 // Función auxiliar para el recorrido inorden (izquierda-raíz-derecha)
 void RBTree::inorderHelper(Node* root) {
     if (root == nullptr) return;
     inorderHelper(root->left);
     cout << root->data << "  ";
     inorderHelper(root->right);
 }
 
 // Función auxiliar para el recorrido por niveles
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
 
 // Método público para insertar un nuevo valor en el árbol
 void RBTree::insert(const int& data) {
     Node* pt = new Node(data);
     root = BSTInsert(root, pt);
     fixViolation(root, pt);
 }
 
 // Métodos públicos para realizar los recorridos del árbol
 void RBTree::inorder() {
     inorderHelper(root);
 }
 
 void RBTree::levelOrder() {
     levelOrderHelper(root);
 }