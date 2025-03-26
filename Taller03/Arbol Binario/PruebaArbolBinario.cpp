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
