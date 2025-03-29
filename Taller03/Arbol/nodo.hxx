/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: nodo.hxx
 ********************************************************/
#include <iostream>
#include "nodo.h"

using namespace std;
//Constructor
template<class T>
Nodo<T>::Nodo(){

}

//Constructor
template<class T>
Nodo<T>::Nodo(T valor){
    this->dato = valor;
}
//Función para obtener el dato del nodo
template<class T>
T& Nodo<T>::obtenerDato(){
    return this->dato;
}
//Función para fijar el dato del nodo
template<class T>
void Nodo<T>::fijarDato(T& val){
    this->dato = val;
    return;
}
//Función para obtener la altura del nodo
template<class T>
int Nodo<T>::altura(){
	if(hijos.size()==0)
	{
		return 0;
	}
	int maximo = 0, aux_altura;
	for(int i = 0;i<hijos.size() ; i++){
	    aux_altura = hijos[i].altura();
        if(aux_altura> maximo)
            maximo = aux_altura;
	}
	return maximo + 1;
}

//Función para hallar el tamaño
template<class T>
int Nodo<T>::tamano(){
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	int conta = 0;
	for( int i = 0; i<hijos.size() ; ++i){
        conta+=hijos[i].tamano();
	}
	return conta+1;
}

//Funcion para limpiar la lista
template<class T>
void Nodo<T>:: limpiarLista(){
    if(hijos.size()==0){
        delete(this);
        return;

    }

    for(int i=0; i<hijos.size(); i++){
        hijos[i].limpiarLista();
    }

}


//Función para agregar descendencia
template<class T>
void Nodo<T>:: adicionarDesc(T &val){
    Nodo* hijo = new Nodo(val);
    hijos.push_back(*hijo);
}

//Función para eliminar descendencia
template<class T>
bool Nodo<T>:: eliminarDesc(T &val){
    bool correr=false;
    for(int i=0;i<hijos.size();i++){
        if(correr){
            hijos[i-1]=hijos[i];
        }
        if(hijos[i] == val)
            correr=true;
    }

    if(!correr)
        return false;
    hijos.pop_back();
    return true;
}

//Función para buscar un valor
template<class T>
Nodo<T>* Nodo<T>:: buscar(T val){
    if(this->dato == val)
        return this;
    if(this->hijos.size() == 0)
        return NULL;
    Nodo* aux;
    for(int i = 0; i<hijos.size() ; i++){
        aux = hijos[i].buscar(val);
        if(aux!=NULL)
            return aux;
    }

    return NULL;

}

//Función para recorrer el árbol en preOrden
template<class T>
void Nodo<T>:: preOrden(){
	cout << "\t"<<this->obtenerDato() << endl;
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i].preOrden();
	}
	return;
}

//Función para recorrer el árbol en posOrden
template<class T>
void Nodo<T>::posOrden(){
	for(int i = 0; i < hijos.size(); i++){
        hijos[i].posOrden();
	}
	cout << "\t" << this->obtenerDato() << endl;
}

//Función para recorrer el árbol en nivelOrden
template<class T>
void Nodo<T>::nivelOrden(int nivel, int lvActual){
    if(nivel == lvActual){
        cout << "\t" << this->obtenerDato() << endl;
        return;
    }

    for(int i = 0; i < hijos.size(); i++){
        hijos[i].nivelOrden(nivel, lvActual + 1);
    }
}
