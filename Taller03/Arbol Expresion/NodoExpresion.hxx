/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: NodoExpresion.hxx
 ********************************************************/
#include "NodoExpresion.h"
#include <string>

using namespace std;
//Constructores
NodoExpresion::NodoExpresion(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}
NodoExpresion::~NodoExpresion(){
}
//Setes y Geters
char NodoExpresion::getDato(){
	return this->dato;
}

void NodoExpresion::setDato(char val){
	this->dato=val;
	return;
}

NodoExpresion* NodoExpresion::getHijoIzq(){
	return this->hijoIzq;
}

NodoExpresion* NodoExpresion::getHijoDer(){
	return this->hijoDer;
}

void NodoExpresion::setHijoIzq(NodoExpresion* izq){
	this->hijoIzq=izq;
	return;
}
void NodoExpresion::setOperando(bool op){
	this->operando=op;
	return;
}
bool NodoExpresion::getOperando(){
	return this->operando;
}
void NodoExpresion::setHijoDer(NodoExpresion* der){
	this->hijoDer=der;
	return;
}
