/********************************************************
 Fecha: 22 de febrero de 2025
 Autores: Santiago Mesa y Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Taller 2
 Pontificia Universidad Javeriana
 Archivo: Main.cpp
 ********************************************************/
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Clases.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "Error en los argumentos.\n";
        return 1;
    }
    
    ColaP colaP; //Creación de un objeto de la clase ColaP
    ArchivoTexto archivoTexto; //Cración de un objeto de la clase ArchivoTexto
    archivoTexto.setNombreArchivo(argv[1]); //Asignación del nombre del archivo a leer
    archivoTexto.leerArchivo(); //Lectura del archivo y guardado de las líneas en la lista de líneas y la subcadena en el dato subcadena
    
    colaP.setArchivoTexto(archivoTexto); //Asignación del objeto archivoTexto al objeto colaP
    colaP.llenarCola(); //Llenado de la cola con las palabras del archivo y la linea en la que aparecen
    
    cout << "\nCon la Subcadena |" << colaP.getArchivoTexto().getSubcadena() << "| ordenada: \n";
    //Se llama a la función imprimirOrdenada
    colaP.imprimirOrdenada();

    colaP.llenarCola();
    colaP.invertirSubcadena();
    cout << "\nCon la Subcadena |" << colaP.getInvSubcadena() << "| invertida: \n";
    //Se llama a la función imprimirReversa
    colaP.imprimirInvertida();
    
    return 0;
}