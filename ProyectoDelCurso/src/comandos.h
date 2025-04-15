/************************************************
 * PROYECTO 1
 * FECHA: 12-02-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: COMANDOS.H
 ***********************************************/
#ifndef COMANDOS_H
#define COMANDOS_H

#include <vector>   // Para manejar vectores
#include <string>   // Para manejar cadenas de texto
#include <list>     // Para manejar listas enlazadas
#include <algorithm> // Para funciones de manipulación de datos (e.g., sort)
#include <sstream>  // Para manipulación de flujos de texto
#include <cstring>  // Para funciones de manejo de cadenas de C

// Declaración de todas las funciones utilizadas en los comandos

// Carga una imagen desde un archivo y la almacena en memoria
void cargarImagen(const std::vector<std::string>& argumentos);

// Carga un volumen compuesto por múltiples imágenes
void cargarVolumen(const std::vector<std::string>& argumentos);

// Muestra información de la imagen cargada en memoria
void infoImagen();

// Muestra información del volumen cargado en memoria
void infoVolumen();

// Genera una proyección 2D de un volumen en una dirección específica
void proyeccion2D(const std::vector<std::string>& argumentos);

// Guarda una proyección 2D en un archivo PGM
void guardarPGM(const std::list<std::list<int>>& proyeccion, const std::string& nombreArchivo);

// Codifica una imagen cargada en memoria utilizando el algoritmo de Huffman
void codificarImagen(const std::vector<std::string>& argumentos);

// Decodifica un archivo comprimido y lo convierte en una imagen PGM
void decodificarArchivo(const std::vector<std::string>& argumentos);

// Realiza la segmentación de una imagen utilizando semillas
void segmentar(const std::vector<std::string>& argumentos);

#endif