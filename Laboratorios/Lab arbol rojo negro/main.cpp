/********************************************************
 Fecha: 02 de abril de 2025
 Autores: Santiago Mesa
 Materia: Estructura de Datos.
 Tema: Árbol rojo negro
 Pontificia Universidad Javeriana
 Archivo: main.cpp

 Para compilar: g++ main.cpp rbtree.cpp -o rbtree
        *   ./rbtree

 ********************************************************/

// Este es el archivo principal para la implementación de una demostración de Árbol Rojo-Negro
// Un Árbol Rojo-Negro es un tipo de árbol binario de búsqueda auto-balanceado donde cada nodo
// tiene un atributo adicional de color (rojo o negro)

#include <iostream>  // Inclusión para operaciones de entrada/salida
#include "rbtree.h"  // Inclusión del encabezado de implementación del Árbol Rojo-Negro

int main() {
    // Crear una nueva instancia del Árbol Rojo-Negro
    RBTree tree;

    // Insertar valores del 7 al 1 en el árbol
    // El árbol se auto-balanceará después de cada inserción
    // para mantener las propiedades del Árbol Rojo-Negro
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    // Imprimir el árbol usando recorrido inorden
    // El recorrido inorden visita: subárbol izquierdo -> raíz -> subárbol derecho
    // Esto imprimirá los números en orden ascendente
    std::cout << "Recorrido Inorden del Árbol Creado\n";
    tree.inorder();

    // Imprimir el árbol usando recorrido por niveles
    // El recorrido por niveles visita el árbol nivel por nivel
    // Esto ayuda a visualizar la estructura real del árbol
    //std::cout << "\n\nRecorrido por Niveles del Árbol Creado\n";
    //tree.levelOrder();
    //std::cout << "\n";

    return 0;  // Finalizar programa con estado exitoso
}
/*
 * CONCLUSIÓN DE LA IMPLEMENTACIÓN DEL ÁRBOL ROJO-NEGRO
 * ==================================================
 * 
 * 
 * 1. PROPIEDADES FUNDAMENTALES:
 *    - Correcta implementación de nodos rojos y negros
 *    - Mantenimiento automático del balance
 *    - Cumplimiento de las reglas de coloración
 *    - Rotaciones apropiadas para mantener el equilibrio
 * 
 * 2. ESTRUCTURA DEL CÓDIGO:
 *    - Organización modular en archivos separados
 *    - Implementación clara de las operaciones básicas
 *    - Comentarios explicativos adecuados
 * 
 * 3. FUNCIONALIDAD:
 *    - Inserción correcta de elementos
 *    - Auto-balanceo después de cada inserción
 *    - Recorridos inorden y por niveles implementados
 * 
 * La implementación corresponde fielmente a lo explicado en clase
 * y demuestra el funcionamiento esperado de un árbol rojo-negro.
 */