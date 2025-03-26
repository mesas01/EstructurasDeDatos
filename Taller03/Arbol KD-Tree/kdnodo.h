/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: kdnodo.h
 ********************************************************/
#ifndef __KDNODO__H__
#define __KDNODO__H__
#include <vector>
using namespace std;

template<class T>
class kdnodo
{
  protected:
    vector <T> datos;
    kdnodo<T> *hijoIzq;
    kdnodo<T> *hijoDer;
    int tag;

  public:
    //Contructor
  	kdnodo();
    //Geters y Seters
    T& obtenerDato();
    void fijarDato(vector<T>& val);
    kdnodo<T>* obtenerHijoIzq();
    kdnodo<T>* obtenerHijoDer();
    void fijarHijoIzq(kdnodo<T> *izq);
    void fijarHijoDer(kdnodo<T> *der);
    void fijarTag(int value);
    //Función para saber la altura del nodo
    int altura();
    //Función para saber el tamaño del nodo
    int tamano();
    //Función para insertar un nodo
    void insertar(vector < T > & val);
    //Función para buscar un valor
    kdnodo<T>* buscar(vector < T > & val);
    //Funcón para recorrer el árbol en preOrden
    void preOrden();
    //Funcón para recorrer el árbol en inOrden
    void inOrden();
    //Funcón para recorrer el árbol en posOrden
    void posOrden();
    //Funcón para recorrer el árbol en nivelOrden
    void nivelOrden();
    //Función para hallar el valor mínimo 
    void maximo(int &maxi);
    //Función para hallar el valor máximo 
    void minimo(int &mini);
    //Función para imprimir el nodo
    void imprimir();
};
#include "kdnodo.hxx"
#endif
