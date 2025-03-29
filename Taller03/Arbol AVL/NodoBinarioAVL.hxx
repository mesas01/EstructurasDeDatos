/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#include "NodoBinarioAVL.h"

using namespace std;
//Contructores
template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}

template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL(){
}

//Geters y Seters
template <class T>
T& NodoBinarioAVL<T>::getDato(){
	return this->dato;
}

template <class T>
void NodoBinarioAVL<T>::setDato(T& val){
	this->dato=val;
	return;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq(){
	return this->hijoIzq;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer(){
	return this->hijoDer;
}

template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq){
	this->hijoIzq=izq;
	return;
}

template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der){
	this->hijoDer=der;
	return;
}
