/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#ifndef NODOEXPRESION_H
#define NODOEXPRESION_H
#include <string.h>
using namespace std;


class NodoExpresion{
  protected:
    char dato;
    bool operando;
    NodoExpresion *hijoIzq;
    NodoExpresion *hijoDer;
  public:
  //Constructores
  NodoExpresion();
  ~NodoExpresion();
  //Setes y Getters
  char getDato();
  void setDato(char val);

  void setOperando(bool op);
  bool getOperando();

  NodoExpresion* getHijoIzq();
  NodoExpresion* getHijoDer();

  void setHijoIzq(NodoExpresion* izq);
  void setHijoDer(NodoExpresion* der);
};
#include "NodoExpresion.hxx"

#endif //NODOBINARIO_H
