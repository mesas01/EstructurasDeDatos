/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: ArbolBinario.h
 ********************************************************/
#ifndef __ARBOLBINARIO__H__
#define __ARBOLBINARIO__H__

#include "NodoBinario.h"

using namespace std;

template<class T>
class ArbolBinario {
  protected:
    NodoBinario<T> *raiz;
public:
    //Constructor
	  ArbolBinario();
    //Función para sabes si el árbol es vacío
    bool esVacio();
    //Función para saber el dato de la raíz
    T& datoRaiz();
    //Funión para saber la altura del árbol
    int altura();
    //Funión para saber el tamaño del árbol
    int tamano();
    //Función para ingresar un dato
    void insertar(T& val);
    //Función para eliminar un dato
    bool eliminar(T& val);
    //Función para buscar un dato
    NodoBinario<T>*  buscar(T& val);
    //Funcón para recorrer el árbol en preOrden
    void preOrden();
    //Funcón para recorrer el árbol en inOrden
    void inOrden();
    //Funcón para recorrer el árbol en posOrden
    void posOrden();
    //Funcón para recorrer el árbol en nivelOrden
    void nivelOrden();
};

#include "ArbolBinario.hxx"
#endif
