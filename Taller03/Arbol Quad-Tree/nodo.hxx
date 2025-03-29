/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#include "Nodo.h"
#include <bits/stdc++.h>

using namespace std;
//Constructor
template<class T>
Nodo<T>::Nodo()
{

    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

template<class T>
Nodo<T>::Nodo(pair<T,T> val)
{
    this->dato = val;
    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

//Función para obtener el dato del nodo
template<class T>
pair<T,T> Nodo<T>::obtenerDato()
{
    return this->dato;
}
//Función para ponerle un dato al nodo
template<class T>
void Nodo<T>::fijarDato(pair<T,T> val)
{
    this->dato = val;
    return;
}
//Función para saber la altura del nodo
template<class T>
int Nodo<T>::altura()
{
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return 1;

    int mayor=0,actual;
    if(NW != NULL)
    {
        actual= this->NW->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(NE != NULL)
    {
        actual = this->NE->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(SW != NULL)
    {
        actual = this->SW->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(SE != NULL)
    {
        actual = this->SE->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
}

//Función para saber el tamaño del nodo
template<class T>
int Nodo<T>::tamano()
{
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return 1;

    int cont=0;
    if(NW != NULL)
    {
        cont+= this->NW->altura()+1;
    }
    if(NE != NULL)
    {
        cont+= this->NE->altura()+1;
    }
    if(SW != NULL)
    {
        cont+= this->SW->altura()+1;
    }
    if(SE != NULL)
    {
        cont+= this->SE->altura()+1;
    }
    return cont;
}
//Función para insertar un nodo
template<class T>
void Nodo<T>:: insertar(pair<T,T> val)
{
    /*Norte*/
    if(this->dato.first < val.first)
    {
        if(this->dato.second < val.second)
        {
            if(this->NE!= NULL)
            {
                this->NE->insertar(val);
            }
            else
            {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->NE = nuevo;
            }
        }
        else
        {
            if(this->SE!= NULL)
            {
                this->SE->insertar(val);
            }
            else
            {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->SE = nuevo;
            }
        }
    }

    /*Sur*/
    if(this->dato.first > val.first )
    {
        if(this->dato.second < val.second)
        {
            if(this->NW!= NULL)
            {
                this->NW->insertar(val);
            }
            else
            {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->NW = nuevo;
            }
        }
        else
        {
            if(this->SW!= NULL)
            {
                this->SW->insertar(val);
            }
            else
            {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->SW = nuevo;
            }
        }
    }
}
//Funcón para buscar un valor
template<class T>
Nodo<T>* Nodo<T>:: buscar(pair<T,T> val)
{
    if(this->dato == val)
        return this;
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return NULL;

    if(this->dato.first < val.first)
    {
        if(this->dato.second < val.second)
        {
            if(this->NE!= NULL)
            {
                return this->NE->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            if(this->SE!= NULL)
            {
                return this->SE->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
    }

    /*Sur*/
    if(this->dato.first > val.first )
    {
        if(this->dato.second < val.second)
        {
            if(this->NW!= NULL)
            {
                return this->NW->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            if(this->SW!= NULL)
            {
                return this->SW->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
    }

    return NULL;

}
//Funcón para recorrer el árbol en preOrden
template<class T>
void Nodo<T>:: preOrden()
{
    cout << "("<<this->dato.first<<','<<this->dato.second <<")"<< endl;
    if(this->NW !=NULL)
        this->NW->preOrden();
    if(this->NE !=NULL)
        this->NE->preOrden();
    if(this->SW !=NULL)
        this->SW->preOrden();
    if(this->SE !=NULL)
        this->SE->preOrden();

    return;
}



//Funcón para recorrer el árbol en posOrden
template<class T>
void Nodo<T>:: posOrden()
{
    if(this->NW !=NULL)
        this->NW->preOrden();
    if(this->NE !=NULL)
        this->NE->preOrden();
    if(this->SW !=NULL)
        this->SW->preOrden();
    if(this->SE !=NULL)
        this->SE->preOrden();
    cout << "("<<this->dato.first<<','<<this->dato.second <<")"<< endl;
    return;

}




