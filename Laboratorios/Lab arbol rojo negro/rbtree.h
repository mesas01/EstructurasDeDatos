/********************************************************
 Fecha: 02 de abril de 2025
 Autores: Santiago Mesa
 Materia: Estructura de Datos.
 Tema: Árbol rojo negro
 Pontificia Universidad Javeriana
 Archivo: rbtree.h

 Para compilar: g++ main.cpp rbtree.cpp -o rbtree
        *   ./rbtree

 ********************************************************/

// Archivo de encabezado para la clase árbol rojo-negro
#pragma once  // Directiva para prevenir inclusiones múltiples
#include "node.hxx"

// Clase principal que implementa el árbol rojo-negro
class RBTree {
private:
    Node* root;  // Puntero al nodo raíz del árbol

    // Métodos auxiliares privados
    void rotateLeft(Node*& root, Node*& pt);     // Realiza rotación izquierda para balancear el árbol
    void rotateRight(Node*& root, Node*& pt);    // Realiza rotación derecha para balancear el árbol
    void fixViolation(Node*& root, Node*& pt);   // Corrige violaciones de las propiedades del árbol
    void inorderHelper(Node* root);              // Auxiliar para recorrido inorden
    Node* BSTInsert(Node* root, Node* pt);       // Inserción básica como árbol binario de búsqueda
    void levelOrderHelper(Node* root);           // Auxiliar para recorrido por niveles

public:
    // Constructor de la clase
    RBTree();

    // Métodos públicos
    void insert(const int& n);  // Inserta un nuevo valor en el árbol
    void inorder();            // Realiza recorrido inorden del árbol
    void levelOrder();         // Realiza recorrido por niveles del árbol
};