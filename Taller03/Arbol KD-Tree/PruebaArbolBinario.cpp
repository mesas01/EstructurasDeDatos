#include<iostream>
#include<set>
#include<map>
#include "kdtree.h"

using namespace std;

main(int argc, char* argv[])
{
    cout<<"ARBOL KD ORDENADO"<<endl;
    cout<<"****************************************************************"<<endl;
		kdtree<int> arbol;
		vector<int> a = {5, 4};
		vector<int> b = {3, 2};
		vector<int> c = {4, 1};
		vector<int> d = {8, 7};
		vector<int> e = {1, 2};
		vector<int> f = {9, 5};
		arbol.insertar(a);
		arbol.insertar(b);
		arbol.insertar(c);
		arbol.insertar(d);
		arbol.insertar(e);
		arbol.insertar(f);

		cout<<endl;
		cout<<"In Orden: "<<endl;
		arbol.inOrden();
	cout<<endl;
	cout<<"Pos Orden: "<<endl;
	arbol.posOrden();
	cout<<endl;

}
