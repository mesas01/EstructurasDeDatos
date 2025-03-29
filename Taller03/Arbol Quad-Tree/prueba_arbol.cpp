/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/

#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

int main(int argc, char* argv[]){
    Arbol<int> arbol;
    pair<int, int> a = {5, 4};
    pair<int, int> b = {3, 2};
    pair<int, int> c = {4, 1};
    pair<int, int> d = {8, 7};
    pair<int, int> e = {1, 2};
    pair<int, int> f = {9, 5};

	arbol.insertar(a);
	arbol.insertar(b);
	arbol.insertar(c);
	arbol.insertar(d);
	arbol.insertar(e);
	arbol.insertar(f);

	cout<<"Pre Orden: "<<endl;
	arbol.preOrden();
	cout<<endl;
	
	cout<<endl;
	cout<<"Pos Orden: "<<endl;
	arbol.posOrden();
	cout<<endl;
}
