/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#ifndef ARBOLEXPRESION_H
#define  ARBOLEXPRESION_H
#include "NodoExpresion.h"
#include <string>

using namespace std;

class ArbolExpresion {
  protected:
    NodoExpresion* raiz;
public:
    //Contructores
    ArbolExpresion();
    ~ArbolExpresion();
    //Geters y Seters
    NodoExpresion* getRaiz();
    void setRaiz(NodoExpresion* nod);
    //Funcón para ingresar una eccuación al árbol en preOrden
    void llenarDesdePrefija(string &expresion);
    //Funcón para ingresar una eccuación al árbol en posOrden
    void llenarDesdePosfija (string &expresion);
    //Funcón para recorrer el árbol en preOrden
    void  obtenerPrefija(NodoExpresion* inicio);
     //Funcón para recorrer el árbol en inOrden
    void  obtenerInfija(NodoExpresion* inicio);
     //Funcón para recorrer el árbol en posOrden
    void  obtenerPosfija(NodoExpresion* inicio);
    //Función para obtener el reusltado de la eccuación
    int evaluar(NodoExpresion* nodi);
    //Función para saber si el dato es un operando
    bool siOperando(char car);
};
#include "ArbolExpresion.hxx"

#endif

