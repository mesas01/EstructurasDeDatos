/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

//Constructor
template<class T>
ArbolBinario<T>::ArbolBinario()
{
    this->raiz=NULL;
}

//Función para sabes si el árbol es vacío
template<class T>
bool ArbolBinario<T>::esVacio()
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
T& ArbolBinario<T>::datoRaiz()
{
    return this->raiz->obtenerDato();
}
//Funión para saber la altura del árbol
template<class T>
int ArbolBinario<T>::altura()
{
    return this->raiz->altura();
}
//Funión para saber el tamaño del árbol
template<class T>
int ArbolBinario<T>::tamano()
{
    return this->raiz->tamano() ;
}
//Función para ingresar un dato
template<class T>
void ArbolBinario<T>::insertar(T& val)
{
    if(this->raiz!=NULL)
    {
        this->raiz->insertar(val);
    }
    else
    {
        NodoBinario<T>* nuevo= new NodoBinario<T>();
        nuevo->fijarDato(val);
        this->raiz=nuevo;
    }


}


//Función para eliminar un dato
template<class T>
bool ArbolBinario<T>::eliminar(T& val)
{ 
	//Nodo* borrar = this->buscar(val);
	NodoBinario<T>* borrar = this->buscar(val);
    if(borrar == NULL)
        return false;

    if(borrar->hijoIzq != NULL)
    {
        //Nodo* nuevo = borrar->hijoIzq->extremo_der();
		NodoBinario<T>* nuevo = borrar->hijoIzq->extremo_der();
        borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);
    }
    else if(borrar->hijoDer != NULL)
    {
		
        //Nodo* nuevo = borrar->hijoDer->extremo_izq();
		NodoBinario<T>* nuevo = borrar->hijoDer->extremo_izq();
        borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);
    }
    return true;
}


//Función para buscar un dato
template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val)
{
    return this->raiz->buscar(val);
}
//Funcón para recorrer el árbol en preOrden
template<class T>
void ArbolBinario<T>::preOrden()
{
    this->raiz->preOrden();
}
//Funcón para recorrer el árbol en inOrden
template<class T>
void ArbolBinario<T>::inOrden()
{
    this->raiz->inOrden();
}
//Funcón para recorrer el árbol en posOrden
template<class T>
void ArbolBinario<T>::posOrden()
{
    this->raiz->posOrden();
}
//Funcón para recorrer el árbol en nivelOrden
template<class T>
void ArbolBinario<T>::nivelOrden()
{
    this->raiz->nivelOrden();
}

