/************************************************
 * PROYECTO 1
 * FECHA: 12-02-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: COMANDOS.H
 ***********************************************/
#ifndef COMANDOS_H
#define COMANDOS_H

#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>
//Todas las funciones de los comandos
void cargarImagen(const std::vector<std::string>& argumentos);
void cargarVolumen(const std::vector<std::string>& argumentos);
void infoImagen();
void infoVolumen();
void proyeccion2D(const std::vector<std::string>& argumentos);
void guardarPGM(const std::list<std::list<int>>& proyeccion, const std::string& nombreArchivo);
void codificarImagen(const std::vector<std::string>& argumentos);
void decodificarArchivo(const std::vector<std::string>& argumentos);
void segmentar(const std::vector<std::string>& argumentos);

#endif