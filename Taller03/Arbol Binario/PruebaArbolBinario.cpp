/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/

#include<iostream>
#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

main(int argc, char* argv[])
{
    ArbolBinario<int> arbol;
	int a=1, b=2, c=3, d=4, e=5, f=6;
	arbol.insertar(a);
	arbol.insertar(b);
	arbol.insertar(c);
	arbol.insertar(d);
	arbol.insertar(e);
	arbol.insertar(f);
	arbol.eliminar(c);
	arbol.inOrden();
}
