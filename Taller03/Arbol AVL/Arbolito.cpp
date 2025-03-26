#include<iostream>
#include "ArbolBinarioAVL.h"

using namespace std;

main(int argc, char* argv[])
{
    ArbolBinarioAVL<int> arbol;
	
	int a=1, b=2, c=3, d=4, e=5, f=6;
	arbol.insertar(a);
	arbol.insertar(b);
	arbol.insertar(c);
	arbol.insertar(d);
	arbol.insertar(e);
	arbol.insertar(f);
	
	
	cout << endl <<"Nivel Raiz: " << endl;
	arbol.nivelOrden(arbol.getRaiz());
	
}