/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: quadtree.h
 ********************************************************/
#ifndef __QUADTREE__H__
#define __QUADTREE__H__

#include "Nodo.h"

using namespace std;

template<class T>
class Arbol {
  protected:
    Nodo<T> *raiz;
  public:
  //Construcotres
	Arbol();
	Arbol(pair<T,T> val);
  //Función para saber si el árbol está vacío
    bool esVacio();
    //Función para saber el dato de la raíz
    pair<T,T> obtenerRaiz();
     //Función para asignarle un valor a la raiz nodo
    void fijarRaiz(Nodo<T>* root);
    //Función para insertar un nodo
    void insertar(pair<T,T>);
    //Función para saber la altura del nodo
    int altura();
    //Función para saber el tamaño del nodo
    int tamano();
    //Función para insertar un nodo
    void insertar(T& val);
    //Función para eliminar un nodo
    bool eliminar(T& val);
    //Función para buscar un valor
    Nodo<T>*  buscar(pair<T,T> val);
    //Función para recorrer el árbol en preOrden
    void preOrden();
    //Función para recorrer el árbol en preOrden
    void posOrden();
};

#include "quadtree.hxx"
#endif
