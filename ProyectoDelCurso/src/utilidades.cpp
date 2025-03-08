/************************************************
 * PROYECTO 1
 * FECHA: 12-02-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: UTILIDADES.CPP
 ***********************************************/
#include <sstream>
#include "utilidades.h"

//Funcion para dividir las palabras de un string en un arreglo
std::vector<std::string> dividirComando(const std::string& comando) {
    std::vector<std::string> partes;
    std::stringstream ss(comando);
    std::string parte;

    while (ss >> parte) {
        partes.push_back(parte);
    }

    return partes;
}