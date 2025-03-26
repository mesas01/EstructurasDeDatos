#include<iostream>
#include "ArbolExpresion.h"
#include "NodoExpresion.h"
#include <string>

using namespace std;

 main(int argc, char* argv[])
{
  cout<<"EJERCICIO 1 "<<endl;
  cout<<endl;
  cout<<"1. Construir Arbol Expresion: "<<endl;
  cout<<"-*/5-7+113-+2+1*43*2-68"<< endl;
  ArbolExpresion* arbexp =new ArbolExpresion();
  string exp="-*/5-7+113-+2+1*43*2-68";
  arbexp->llenarDesdePrefija(exp);


  cout<<"2. Imprimir Version Posfija"<<"=" << endl;
  arbexp->obtenerPosfija(arbexp->getRaiz());
  cout<<endl;
  cout<<"3. Imprimir Resultado"<<"=" << endl;
  cout<<arbexp->evaluar(arbexp->getRaiz())<<endl;

  cout<<"EJERCICIO 2"<<endl;
  cout<<endl;
  cout<<"1. Construir Arbol Expresion: "<<endl;
  ArbolExpresion* arbexp2 =new ArbolExpresion();
  cout<< "45+23+*6+87+/12+3*6+23+/*"<< endl;
  string exp2="45+23+*6+87+/12+3*6+23+/*";
  arbexp2->llenarDesdePosfija(exp2);

  cout<<"2. Imprimir Version Prefija"<<"=" << endl;
  arbexp2->obtenerPrefija(arbexp2->getRaiz());
  cout<<endl;

  cout<<"3. Imprimir Resultado"<<"=" << endl;
  cout<<arbexp2->evaluar(arbexp2->getRaiz())<<endl;

}
