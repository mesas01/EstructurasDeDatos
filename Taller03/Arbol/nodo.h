/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: nodo.h
 ********************************************************/
#ifndef __NODO__H__
#define __NODO__H__

#include <queue>

using namespace std;

template< class T >
class Nodo{
  protected:
    T dato;
    vector<Nodo <T> > hijos;

  public:
    //Constructor
  	Nodo();
    //Constructor
  	Nodo(T valor);
    //Función para saber la altura del nodo
  	int altura();
    //Función para hallar el tamaño
  	int tamano();
    //GetDato
    T& obtenerDato();
    //SetDato
    void fijarDato(T& val);
    //Función para limpiar la lista de nodos
    void limpiarLista();
    //Función para agregar nodos hijos
    void adicionarDesc(T& val);
    //Función para eliminar nodos hijos
    bool eliminarDesc(T &val);
    //Función para recorrer el árbol en preOrden
    void preOrden();
    //Función para recorrer el árbol en posOrden
    void posOrden();
    //Función para recorrer el árbol en nivelOrden
    void nivelOrden(std::queue<Nodo*> &cola);
    //Función para buscar un valor
    Nodo* buscar(T val);
};
#include "nodo.hxx"
#endif
