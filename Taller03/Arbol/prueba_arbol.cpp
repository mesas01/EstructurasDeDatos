/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.h
 ********************************************************/

#include <iostream>
#include <string>
/*#include <bits/stdc++.h>*/
#include "arbol.h"

using namespace std;

int main(){
        Arbol<int> arbol(5);
        arbol.insertarNodo(5,6);
        arbol.insertarNodo(5,7);
        arbol.insertarNodo(5,8);

        arbol.insertarNodo(6,9);
        arbol.insertarNodo(6,10);
        arbol.insertarNodo(7,11);

        //arbol.nivelOrden();
        arbol.posOrden();
}
