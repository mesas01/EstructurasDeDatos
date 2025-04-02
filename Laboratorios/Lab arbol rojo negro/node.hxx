/********************************************************
 * Fecha: 02 de abril de 2025
 * Autores: Santiago Mesa
 * Materia: Estructura de Datos.
 * Tema: Árbol rojo negro
 * Pontificia Universidad Javeriana
 * Archivo: node.hxx
 *
 * Para compilar: g++ main.cpp rbtree.cpp -o rbtree
 *        *   ./rbtree
 *
 ********************************************************/

// Archivo de encabezado para la definición del nodo del árbol rojo-negro
#pragma once  

// Enumeración que define los posibles colores de un nodo
enum Color { RED, BLACK };  // Rojo y Negro son los únicos colores permitidos

// Estructura que define un nodo del árbol rojo-negro
struct Node {
    int data;      // Valor almacenado en el nodo
    bool color;    // Color del nodo (verdadero para negro, falso para rojo)
    Node *left,    // Puntero al hijo izquierdo
         *right,   // Puntero al hijo derecho
         *parent;  // Puntero al nodo padre

    // Constructor del nodo que inicializa un nuevo nodo con el valor proporcionado
    Node(int data);
};