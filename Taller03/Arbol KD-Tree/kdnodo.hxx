/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#include "kdnodo.h"
#include <bits/stdc++.h>

using namespace std;
//Contructor
template<class T>
kdnodo<T>::kdnodo()
{
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->tag = 0;
}
 //Geters y Seters
template<class T>
vector<T>& kdnodo<T>::obtenerDato()
{
    return this->datos;
}

template<class T>
void kdnodo<T>::fijarDato(vector<T>& val)
{
    this->datos = val;
}

template<class T>
void kdnodo<T>::fijarTag(int value)
{
    this->tag = value;
}

template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}

template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoDer()
{
    return this->hijoDer;
}

template<class T>
void kdnodo<T>::fijarHijoIzq(kdnodo<T> *izq)
{
    this->hijoIzq = izq;
}

template<class T>
void kdnodo<T>::fijarHijoDer(kdnodo<T> *der)
{
    this->hijoDer = der;
}
//Función para saber la altura del nodo
template<class T>
int kdnodo<T>::altura()
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

//Función para saber el tamaño del nodo
template<class T>
int kdnodo<T>::tamano()
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
//Función para insertar un nodo
template<class T>
void kdnodo<T>::insertar(vector<T>& val)
{
    if(val[this->tag] > this->datos[this->tag])
    {
        if(this->hijoDer == NULL)
        {
            kdnodo* nuevo = new kdnodo();
            nuevo->fijarTag((this->tag + 1) % val.size());
            nuevo->fijarDato(val);
            this->fijarHijoDer(nuevo);
        }
        else
        {
            this->hijoDer->insertar(val);
        }
    }
    else // incluye caso val[tag] <= datos[tag]
    {
        if(this->hijoIzq == NULL)
        {
            kdnodo* nuevo = new kdnodo();
            nuevo->fijarTag((this->tag + 1) % val.size());
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
kdnodo<T>* kdnodo<T>:: buscar(vector < T >& val)
{
	if(this->iguales(val))
  {
		return this;
	}

	if(val[this->tag] < this->datos[this->tag])
  {
		return this->hijoIzq->buscar(val);
	}
	else
  {
		return this->hijoDer->buscar(val);
	}
}
//Funcón para recorrer el árbol en preOrden
template<class T>
void kdnodo<T>:: preOrden()
{
this->imprimir();
  if(this->hijoIzq != NULL)
		this->hijoIzq->preOrden();
	if(this->hijoDer != NULL)
		this->hijoDer->preOrden();
	return;
}

 //Funcón para recorrer el árbol en inOrden
template<class T>
void kdnodo<T>:: inOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->inOrden();

  this->imprimir();

	if(this->hijoDer != NULL)
		this->hijoDer->inOrden();
	return;

}


//Funcón para recorrer el árbol en posOrden
template<class T>
void kdnodo<T>:: posOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->posOrden();

	if(this->hijoDer != NULL)
		this->hijoDer->posOrden();

  this->imprimir();
  return;

}

//Funcón para recorrer el árbol en nivelOrden
template<class T>
void kdnodo<T>:: nivelOrden()
{
	queue<kdnodo*> cola;
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

//Función para hallar el valor mínimo 
template<class T>
void kdnodo<T>:: maximo(int &maxi)
{
	if(maxi < this->obtenerDato())
	{
		maxi = this->obtenerDato();
	}
	if(this->hijoIzq != NULL)
		this->hijoIzq->maximo(maxi);

	if(this->hijoDer != NULL)
		this->hijoDer->maximo(maxi);
	return;

}
//Función para hallar el valor máximo 
template<class T>
void kdnodo<T>:: minimo(int &mini)
{
	if(mini > this->obtenerDato())
	{
		mini = this->obtenerDato();
	}
	if(this->hijoIzq != NULL)
		this->hijoIzq->minimo(mini);

	if(this->hijoDer != NULL)
		this->hijoDer->minimo(mini);
	return;

}

//Función para imprimir el nodo
template<class T>
void kdnodo<T>:: imprimir()
{
  cout<<"( ";
  for(int i = 0 ; i < this->datos.size() ; ++i)
  {
    cout<<this->datos[i];
    if(i!=this->datos.size()-1)
      cout<<", ";

  }
  cout<<" )\n";
}
