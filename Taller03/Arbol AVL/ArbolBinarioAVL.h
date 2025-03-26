/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: ArbolBinarioAVL.h
 ********************************************************/
#ifndef _ARBOLBINARIOAVL_H_
#define _ARBOLBINARIOAVL_H_

#include "NodoBinarioAVL.h"
template <class T>

class ArbolBinarioAVL{
	protected:
		NodoBinarioAVL<T> *raiz;
	public:
		//Constructor
		ArbolBinarioAVL();
		//Constructor
		~ArbolBinarioAVL();
		//SetRaíz
		void setRaiz(NodoBinarioAVL<T>* raiz);
		//GetRaíz
		NodoBinarioAVL<T>* getRaiz();
		//Función para saber si el árbol está vacío
		bool esVacio();
		//Devuelve el dato de la raíz
		T& datoRaiz();
		//Devuelve la altura del árbol
		int altura(NodoBinarioAVL<T> *inicio);
		//Devuelve el tamaño del árbol
		int tamano(NodoBinarioAVL<T> *inicio);
		//Función para hacer un giro a la derecha sobre un conjunto de nodos
		NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>*& inicio);
		//Función para hacer un giro a la izquierda y luego derecha sobre un conjunto de nodos
		NodoBinarioAVL<T>* giroIzquierdaDerecha(NodoBinarioAVL<T>* &padre);
		//Función para hacer un giro a la izquierda sobre un conjunto de nodos
		NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>*& inicio);
		//Función para hacer un giro a la derecha y luego a la izquierda sobre un conjunto de nodos
		NodoBinarioAVL<T>* giroDerechaIzquierda(NodoBinarioAVL<T>* &padre);
		//Función para insertar un valor
		bool insertar(T& val);
		//Función para eliminar un valor
		bool eliminar(T& val);
		//Función para buscar un valor
		bool buscar(T& val);
		//Función para recorrer el árbol en preOrden
		void preOrden(NodoBinarioAVL<T> *inicio);
		//Función para recorrer el árbol en inOrden
		void inOrden(NodoBinarioAVL<T> *inicio);
		//Función para recorrer el árbol en posOrden
		void posOrden(NodoBinarioAVL<T> *inicio);
		//Función para recorrer el árbol en nivelOrden
		void nivelOrden(NodoBinarioAVL<T> *inicio);
};
#include "ArbolBinarioAVL.hxx"

#endif //ARBOLBINARIOAVL_H
