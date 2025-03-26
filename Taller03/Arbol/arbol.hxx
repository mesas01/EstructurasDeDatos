/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.hxx
 ********************************************************/
#include <iostream>
#include <queue>
#include "arbol.h"

using namespace std;
//Constructor
template<class T>
Arbol<T>::Arbol()
{
    Nodo<T>* root = NULL;
}
//Constructor
template<class T>
Arbol<T>::Arbol(T val)
{
    Nodo<T>* root =new  Nodo<T>(val);
    this->raiz=root;
}
//Función para saber si el árbol esta vacío
template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==NULL)
        return true;
    return false;
}
//GetRaíz
template<class T>
T Arbol<T>:: obtenerRaiz()
{
    return this->raiz;
}
//SetRaíz
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}
//Función para saber la altura del árbol
template<class T>
int Arbol<T>:: altura()
{
    return this->raiz->altura();
}
//Función para saber el tamaño del árbol
template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}
//Función para insertar un nodo
template<class T>
bool Arbol<T>:: insertarNodo(T padre, T val)
{
    Nodo<T>* aux = this->raiz->buscar(padre);
    if(aux == NULL)
        return false;
    aux->adicionarDesc(val);
    return true;
}
//Función para eliminar un nodo
template<class T>
bool Arbol<T>:: eliminar(T& val)
{
    return this->raiz->eliminar(val);
}
//Función para buscar un valor
template<class T>
Nodo<T>* Arbol<T>::  buscar(T val)
{
    return this->raiz->buscar(val);
}
//Función para recorrer el árbol en preOrden
template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}
//Función para recorrer el árbol en inOrden
template<class T>
void Arbol<T>:: inOrden()
{
    this->raiz->inOrden();
}
//Función para recorrer el árbol en posOrden
template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}
//Función para recorrer el árbol en nivelOrden
template<class T>
void Arbol<T>:: nivelOrden()
{
    this->raiz->nivelOrden();
}
