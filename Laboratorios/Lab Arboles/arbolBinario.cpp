/********************************************************
 Fecha: 04 de marzo de 2025
 Autores: Santiago Mesa
 Materia: Estructura de Datos.
 Tema: Arboles binarios
 Pontificia Universidad Javeriana
 Archivo: arbolBinario.cpp
 ********************************************************/
#include <iostream>
#include "arbolBinario.h"
using namespace std;

btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}
/**Función para insertar un valor en el arbol binario**/
void btree::insert(int key, node *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}
/**Función para insertar un valor en el arbol binario**/
void btree::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}
/**Función para la busqueda de un valor en el arbol binario**/
node *btree::search(int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}
/**Función para la busqueda de un valor en el arbol binario**/
node *btree::search(int key){
	return search(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}
/**Función que imprime el orden del árbol binario en orden: LDR **/
void btree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}
/**Función sobre cargada que imprime el orden del árbol binario en orden: LDR, a partir de un apuntador a un nodo **/
void btree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}
/**Función que imprime el orden del árbol binario en orden: LRD **/
void btree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}
/**Función sobre cargada que imprime el orden del árbol binario en orden: LRD, a partir de un apuntador a un nodo **/
void btree::postorder_print(node *leaf){
	if(leaf != NULL){
		postorder_print(leaf->left);
		postorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}
/**Función que imprime el orden del árbol binario en orden: DLR **/
void btree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}
/**Función sobre cargada que imprime el orden del árbol binario en orden: DLR, a partir de un apuntador a un nodo **/
void btree::preorder_print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		preorder_print(leaf->left);
		preorder_print(leaf->right);
	}
}