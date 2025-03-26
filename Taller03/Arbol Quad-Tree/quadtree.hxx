/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: quadtree.hxx
 ********************************************************/
#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;
//Construcotres
template<class T>
Arbol<T>::Arbol()
{
    Nodo<T>* root = NULL;
}

template<class T>
Arbol<T>::Arbol(pair<T,T> val)
{
    Nodo<T>* root =new  Nodo<T>(val);
    this->raiz=root;
}
/*
template<class T>
Arbol<T>::~Arbol()
{
    delete(this->raiz);
}
*/
//Función para saber si el árbol está vacío
template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==NULL)
        return true;
    return false;
}
//Función para saber el dato de la raíz
template<class T>
pair<T,T> Arbol<T>:: obtenerRaiz()
{
    return this->raiz;
}
//Función para asignarle un valor a la raiz
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}
//Función para saber la altura del nodo
template<class T>
int Arbol<T>:: altura()
{
    return this->raiz->altura();
}
//Función para saber el tamaño del nodo
template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}
//Función para insertar un nodo
template<class T>
void Arbol<T>:: insertar(pair<T,T> val)
{
    this->raiz->insertar(val);
}

//Función para buscar un valor
template<class T>
Nodo<T>* Arbol<T>::  buscar(pair<T,T> val)
{
    return this->raiz->buscar(val);
}
//Función para recorrer el árbol en preOrden
template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}
//Función para recorrer el árbol en posOrden
template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}

