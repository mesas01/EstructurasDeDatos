/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: NodoBinario.hxx
 ********************************************************/
#include "NodoBinario.h"
#include <bits/stdc++.h>

using namespace std;
//Contructor
template<class T>
NodoBinario<T>::NodoBinario()
{
    this->hijoIzq=NULL;
    this->hijoDer=NULL;
}
//Geters y Seters
template<class T>
T& NodoBinario<T>::obtenerDato()
{
    return this->dato;
}

template<class T>
void NodoBinario<T>::fijarDato(T& val)
{
    this->dato = val;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer()
{
    return this->hijoDer;
}

template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq)
{
    this->hijoIzq = izq;
}

template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der)
{
    this->hijoDer = der;
}
//Función para saber la altura del nodo
template<class T>
int NodoBinario<T>::altura()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->altura();
	else if(this->hijoDer==NULL)
		return this->hijoIzq->altura();


	return max(this->hijoIzq->altura() , this->hijoDer->altura());
}

//Función para saber la tamaño del nodo
template<class T>
int NodoBinario<T>::tamano()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->tamano() +1 ;
	else if(this->hijoDer==NULL)
		return this->hijoIzq->tamano() +1 ;


	return this->hijoIzq->tamano() + this->hijoDer->tamano() +1 ;
}
//Función para insertar un valor
template<class T>
void NodoBinario<T>:: insertar(T& val)
{

	if(val > this->obtenerDato()){
		if(this->hijoDer==NULL)
		{
			NodoBinario* nuevo= new NodoBinario();
			nuevo->fijarDato(val);
			this->fijarHijoDer(nuevo);
		}
		else
		{
			this->hijoDer->insertar(val);
		}
	}

	if(val < this->obtenerDato()){
		if(this->hijoIzq==NULL)
		{
			NodoBinario* nuevo= new NodoBinario();
			nuevo->fijarDato(val);
			this->fijarHijoIzq(nuevo);
		}
		else
		{
			this->hijoIzq->insertar(val);
		}
	}

}

//Función para buscar un valor
template<class T>
NodoBinario<T>* NodoBinario<T>:: buscar(T& val)
{
	if(this->obtenerDato()==val){
		return this;
	}

	if(val < this-> obtenerDato()){
        if(this->hijoIzq != NULL)
            return this->hijoIzq->buscar(val);
        else
            return NULL;
	}
	else{
        if(this->hijoDer != NULL)
            return this->hijoDer->buscar(val);
        else
            return NULL;
	}
}

//Funcón obtener el nodo mas a la derecha
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_der()
{
    if(this->hijoDer != NULL)
        return this->hijoDer->extremoDer();
    else
        return this;
}
//Funcón obtener el nodo mas a la izquierda
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_izq()
{
    if(this->hijoIzq != NULL)
        return this->hijoIzq->extremo_izq();
    else
        return this;
}

//Funcón para recorrer el árbol en preOrden
template<class T>
void NodoBinario<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	if(this->hijoIzq != NULL)
		this->hijoIzq->preOrden();
	if(this->hijoDer != NULL)
		this->hijoDer->preOrden();
	return;
}

//Funcón para recorrer el árbol en inOrden
template<class T>
void NodoBinario<T>:: inOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->inOrden();

	cout << "\t"<<this->obtenerDato() << endl;

	if(this->hijoDer != NULL)
		this->hijoDer->inOrden();
	return;

}

//Funcón para recorrer el árbol en posOrden
template<class T>
void NodoBinario<T>:: posOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->posOrden();

	if(this->hijoDer != NULL)
		this->hijoDer->posOrden();

	cout << "\t"<<this->obtenerDato() << endl;
	return;

}

//Funcón para recorrer el árbol en nivelOrden
template<class T>
void NodoBinario<T>:: nivelOrden()
{
	queue<NodoBinario*> cola;
	cola.push(this);
	while(!cola.empty()){
		cout<<"\t"<<cola.front()->obtenerDato()<<endl;
		if(cola.front()->hijoIzq != NULL){
			cola.push(cola.front()->hijoIzq);
		}

		if(cola.front()->hijoDer != NULL){
			cola.push(cola.front()->hijoDer);
		}
		cola.pop();
	}
}




