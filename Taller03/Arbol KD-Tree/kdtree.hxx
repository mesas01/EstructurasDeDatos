/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#include "kdtree.h"
using namespace std;

//Constructor
template<class T>
kdtree<T>::kdtree(){
	this->raiz=NULL;
}

//Función para saber si el árbol está vacío
template<class T>
bool kdtree<T>::esVacio()
{
   if(this==NULL)
   {
      return true;
   }
   else
   {
     return false;
   }
}
//Función para saber el dato de la raíz
template<class T>
T& kdtree<T>::datoRaiz()
{
   return this->raiz->obtenerDato();
}
//Función para saber la altura del nodo
template<class T>
int kdtree<T>::altura()
{
   return this->raiz->altura();
}
//Función para saber el tamaño del nodo
template<class T>
int kdtree<T>::tamano()
{
	return this->raiz->tamano() ;
}
//Función para insertar un nodo
template<class T>
void kdtree<T>::insertar(vector < T >& val)
{
	if(this->raiz!=NULL){
		this->raiz->insertar(val);
	}
	else{
		kdnodo<T>* nuevo= new kdnodo<T>();
		nuevo->fijarDato(val);
		this->raiz=nuevo;
	}


}

//Función para buscar un valor
template<class T>
kdnodo<T>* kdtree<T>::buscar(T& val)
{
	return this->raiz->buscar(val);
}
//Funcón para recorrer el árbol en preOrden
template<class T>
void kdtree<T>::preOrden()
{
	this->raiz->preOrden();
}
//Funcón para recorrer el árbol en inOrden
template<class T>
void kdtree<T>::inOrden()
{
	this->raiz->inOrden();
}
//Funcón para recorrer el árbol en posOrden
template<class T>
void kdtree<T>::posOrden()
{
	this->raiz->posOrden();
}
//Funcón para recorrer el árbol en nivelOrden
template<class T>
void kdtree<T>::nivelOrden()
{
	this->raiz->nivelOrden();
}
//Función para hallar el valor máximo
template<class T>
void kdtree<T>::maximo(int &maxi)
{
	this->raiz->maximo(maxi);
}
//Función para hallar el valor mínimo 
template<class T>
void kdtree<T>::minimo(int &mini)
{
	this->raiz->minimo(mini);
}
