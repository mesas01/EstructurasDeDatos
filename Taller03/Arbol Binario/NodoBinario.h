/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

using namespace std;

template< class T >
class NodoBinario
{
  protected:
    T dato;
    NodoBinario<T> *hijoIzq;
    NodoBinario<T> *hijoDer;

  public:
    //Contructor
  	NodoBinario();
    //Geters y Seters
    T& obtenerDato();
    void fijarDato(T& val);
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario<T> *izq);
    void fijarHijoDer(NodoBinario<T> *der);
    //Función para saber la altura del nodo
    int altura();
    //Función para saber la tamaño del nodo
    int tamano();
    //Función para insertar un valor
    void insertar(T& val);
    //Función para buscar un valor
    NodoBinario<T>* buscar(T& val);
    //Funcón para recorrer el árbol en preOrden
    void preOrden();
    //Funcón para recorrer el árbol en inOrden
    void inOrden();
    //Funcón para recorrer el árbol en posOrden
    void posOrden();
    //Funcón para recorrer el árbol en nivelOrden
    void nivelOrden();
    //Funcón obtener el nodo mas a la izquierda
	  NodoBinario<T>* extremo_izq();
    //Funcón obtener el nodo mas a la derecha
	  NodoBinario<T>* extremo_der();
};

#include "NodoBinario.hxx"
#endif
