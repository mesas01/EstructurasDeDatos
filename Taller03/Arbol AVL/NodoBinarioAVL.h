/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/
#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

template <class T>

class NodoBinarioAVL{
	public:
		T dato;
		NodoBinarioAVL<T> *hijoIzq;
		NodoBinarioAVL<T> *hijoDer;

	public:
		//Contructores
		NodoBinarioAVL();
		~NodoBinarioAVL();
		//Geters y Seters
		T& getDato();
		void setDato(T& val);
		NodoBinarioAVL<T>* getHijoIzq();
		NodoBinarioAVL<T>* getHijoDer();
		void setHijoIzq(NodoBinarioAVL<T>* izq);
		void setHijoDer(NodoBinarioAVL<T>* der);
};

#include "NodoBinarioAVL.hxx"

#endif //NODOBINARIOAVL_H
