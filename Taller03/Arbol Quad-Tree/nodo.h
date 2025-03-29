/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#ifndef __NODO__H__
#define __NODO__H__

using namespace std;

template< class T >
class Nodo
{
  protected:
    pair<T,T> dato;
    Nodo<T>* NW;
    Nodo<T>* NE;
    Nodo<T>* SW;
    Nodo<T>* SE;


  public:
  //Constructor
  	Nodo();
  	Nodo(pair<T,T> val);
    //Función para saber la altura del nodo
  	int altura();
    //Función para saber el tamaño del nodo
  	int tamano();
    //Función para obtener el dato del nodo
    pair<T,T> obtenerDato();
    //Función para insertar un nodo
    void insertar(pair<T,T>  val);
    //Función para ponerle un dato al nodo
    void fijarDato(pair<T,T> val);
    //Funcón para recorrer el árbol en preOrden
    void preOrden();
    //Funcón para recorrer el árbol en posOrden
    void posOrden();
    //Funcón para buscar un valor
    Nodo* buscar(pair<T,T> val);
};

#include "Nodo.hxx"
#endif
