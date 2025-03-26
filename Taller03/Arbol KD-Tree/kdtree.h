/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: kdtree.h
 ********************************************************/
#ifndef __KDTREE__H__
#define __KDTREE__H__
#include "kdnodo.h"

using namespace std;

template<class T>
class kdtree {
  protected:
    kdnodo<T> *raiz;
public:
  //Constructor
	kdtree();
  //Función para saber si el árbol está vacío
    bool esVacio();
    //Función para saber el dato de la raíz
    T& datoRaiz();
    //Función para saber la altura del nodo
    int altura();
    //Función para saber el tamaño del nodo
    int tamano();
    //Función para insertar un nodo
    void insertar(vector < T >& val);
    //Función para buscar un valor
    kdnodo<T>* buscar(T& val);
    //Funcón para recorrer el árbol en preOrden
    void preOrden();
    //Funcón para recorrer el árbol en inOrden
    void inOrden();
    //Funcón para recorrer el árbol en posOrden
    void posOrden();
    //Funcón para recorrer el árbol en nivelOrden
    void nivelOrden();
    //Función para hallar el valor máximo 
    void maximo(int &maxi);
    //Función para hallar el valor mínimo 
    void minimo(int &mini);
};
#include "kdtree.hxx"

#endif
