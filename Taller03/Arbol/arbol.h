/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#ifndef __ARBOL__H__
#define __ARBOL__H__

#include "nodo.h"

using namespace std;

template<class T> class Arbol {
	protected:
    	Nodo<T> *raiz;
	public:
		//Constructor
		Arbol();
		//Constructor
		Arbol(T val);
		//Función para saber si el árbol esta vacío	
	    bool esVacio();
		//GetRaíz
   	 	T obtenerRaiz();
		//SetRaíz
   	 	void fijarRaiz(Nodo<T>* root);
		//Función para insertar un nodo
   	 	bool insertarNodo(T padre, T val);
		//Función para saber la altura del árbol
    	int altura();
		//Función para saber el tamaño del árbol
	    int tamano();
		//Función para insertar un valor
   		void insertar(T& val);
		//Función para eliminar un nodo
    	bool eliminar(T& val);
		//Función para buscar un valor
    	Nodo<T>*  buscar(T val);
		//Función para recorrer el árbol en preOrden
    	void preOrden();
		//Función para recorrer el árbol en inOrden
    	void inOrden();
		//Función para recorrer el árbol en posOrden
    	void posOrden();
		//Función para recorrer el árbol en nivelOrden
    	void nivelOrden();
};
#include "arbol.hxx"
#endif
