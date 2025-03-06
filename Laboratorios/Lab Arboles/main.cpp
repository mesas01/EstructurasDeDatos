/********************************************************
 Fecha: 04 de marzo de 2025
 Autores: Santiago Mesa
 Materia: Estructura de Datos.
 Tema: Árboles binarios
 Pontificia Universidad Javeriana
 Archivo: main.cpp

 Para compilar: g++ main.cpp arbolBinario.cpp -o programa
     *   ./programa

 También se puede compilar en Linux con el comando:
     *   make run
 ********************************************************/
#include <iostream>
#include "arbolBinario.h"
using namespace std;

int main(){
    // Creación del árbol binario dinámicamente
    btree *tree = new btree();

    // Inserción de valores en el árbol binario
    tree->insert(7);
    tree->insert(3);
    tree->insert(0);
    tree->insert(5);
    tree->insert(-3);
    tree->insert(1);
    tree->insert(4);
    tree->insert(6);
    tree->insert(20);    
    tree->insert(15);
    tree->insert(25);
    tree->insert(30);

    // Recorridos del árbol binario
    cout << "Recorrido Preorder (DLR): ";
    tree->preorder_print();

    cout << "Recorrido Inorder (LDR): ";
    tree->inorder_print();

    cout << "Recorrido Postorder (LRD): ";
    tree->postorder_print();

    // Liberación de memoria
    delete tree;
}
