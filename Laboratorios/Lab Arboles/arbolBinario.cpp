/********************************************************
 Fecha: 04 de marzo de 2025
 Autor: Santiago Mesa
 Materia: Estructura de Datos
 Tema: Implementación de Árboles Binarios
 Universidad: Pontificia Universidad Javeriana
 Descripción: Este archivo contiene la implementación de 
 una estructura de árbol binario con operaciones básicas 
 como inserción, búsqueda y recorridos en distintos órdenes.
 Archivo: arbolBinario.cpp
 ********************************************************/

 #include <iostream>
 #include "arbolBinario.h"
 
 using namespace std;
 
 // Constructor de la clase btree. Inicializa la raíz como NULL.
 btree::btree() {
	 root = NULL;
 }
 
 // Destructor de la clase btree. Llama a destroy_tree para liberar memoria.
 btree::~btree() {
	 destroy_tree();
 }
 
 // Función recursiva que destruye el árbol liberando la memoria de cada nodo.
 void btree::destroy_tree(node *leaf) {
	 if (leaf != NULL) {
		 destroy_tree(leaf->left);  // Elimina el subárbol izquierdo.
		 destroy_tree(leaf->right); // Elimina el subárbol derecho.
		 delete leaf;               // Elimina el nodo actual.
	 }
 }
 
 // Función recursiva para insertar un valor en el árbol binario.
 void btree::insert(int key, node *leaf) {
	 if (key < leaf->value) {  // Si el valor es menor, va al subárbol izquierdo.
		 if (leaf->left != NULL) {
			 insert(key, leaf->left);
		 } else {
			 // Crea un nuevo nodo en la izquierda si está vacío.
			 leaf->left = new node;
			 leaf->left->value = key;
			 leaf->left->left = NULL;
			 leaf->left->right = NULL;
		 }
	 } else {  // Si el valor es mayor o igual, va al subárbol derecho.
		 if (leaf->right != NULL) {
			 insert(key, leaf->right);
		 } else {
			 // Crea un nuevo nodo en la derecha si está vacío.
			 leaf->right = new node;
			 leaf->right->value = key;
			 leaf->right->right = NULL;
			 leaf->right->left = NULL;
		 }
	 }
 }
 
 // Función pública para insertar un valor en el árbol.
 void btree::insert(int key) {
	 if (root != NULL) {
		 insert(key, root);
	 } else {
		 // Si el árbol está vacío, crea un nuevo nodo raíz.
		 root = new node;
		 root->value = key;
		 root->left = NULL;
		 root->right = NULL;
	 }
 }
 
 // Función recursiva para buscar un valor en el árbol.
 node *btree::search(int key, node *leaf) {
	 if (leaf != NULL) {
		 if (key == leaf->value) {
			 return leaf;  // Se encontró el valor.
		 }
		 if (key < leaf->value) {
			 return search(key, leaf->left);  // Busca en el subárbol izquierdo.
		 } else {
			 return search(key, leaf->right); // Busca en el subárbol derecho.
		 }
	 } else {
		 return NULL; // No se encontró el valor.
	 }
 }
 
 // Función pública para buscar un valor en el árbol.
 node *btree::search(int key) {
	 return search(key, root);
 }
 
 // Función que destruye completamente el árbol llamando a la versión recursiva.
 void btree::destroy_tree() {
	 destroy_tree(root);
 }
 
 // Función que imprime los valores del árbol en orden "LDR" (inorden).
 void btree::inorder_print() {
	 inorder_print(root);
	 cout << "\n";
 }
 
 // Versión recursiva de la función inorder_print.
 // Recorre el árbol en orden: Izquierda, Nodo, Derecha.
 void btree::inorder_print(node *leaf) {
	 if (leaf != NULL) {
		 inorder_print(leaf->left);  // Recorre el subárbol izquierdo.
		 cout << leaf->value << ","; // Imprime el valor del nodo actual.
		 inorder_print(leaf->right); // Recorre el subárbol derecho.
	 }
 }
 
 // Función que imprime los valores del árbol en orden "LRD" (postorden).
 void btree::postorder_print() {
	 postorder_print(root);
	 cout << "\n";
 }
 
 // Versión recursiva de la función postorder_print.
 // Recorre el árbol en orden: Izquierda, Derecha, Nodo.
 void btree::postorder_print(node *leaf) {
	 if (leaf != NULL) {
		 postorder_print(leaf->left);  // Recorre el subárbol izquierdo.
		 postorder_print(leaf->right); // Recorre el subárbol derecho.
		 cout << leaf->value << ",";   // Imprime el valor del nodo actual.
	 }
 }
 
 // Función que imprime los valores del árbol en orden "DLR" (preorden).
 void btree::preorder_print() {
	 preorder_print(root);
	 cout << "\n";
 }
 
 // Versión recursiva de la función preorder_print.
 // Recorre el árbol en orden: Nodo, Izquierda, Derecha.
 void btree::preorder_print(node *leaf) {
	 if (leaf != NULL) {
		 cout << leaf->value << ",";   // Imprime el valor del nodo actual.
		 preorder_print(leaf->left);   // Recorre el subárbol izquierdo.
		 preorder_print(leaf->right);  // Recorre el subárbol derecho.
	 }
 }
 