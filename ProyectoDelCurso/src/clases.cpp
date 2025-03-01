/************************************************
 * PROYECTO 1
 * FECHA: 01-03-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: CLASES.CPP
 ***********************************************/
#include "clases.h"

Imagen::~Imagen(){
    lista.clear();
}
void Imagen::setNombre(std::string nombre){
    this->nombre = nombre;
}
void Imagen::setCodigo(std::string codigo){
    this->codigo = codigo;
}
void Imagen::setXTamano(int xTamano){
    this->xTamano = xTamano;
}
void Imagen::setYTamano(int yTamano){
    this->yTamano = yTamano;
}
void Imagen::setMaxIntensidad(int maxIntensidad){
    this->maxIntensidad = maxIntensidad;
}
void Imagen::setLista(std::list<std::list<int>> lista){
    this->lista = lista;
}
std::string Imagen::getNombre(){
    return nombre;
}
std::string Imagen::getCodigo(){
    return codigo;
}
int Imagen::getXTamano(){
    return xTamano;
}
int Imagen::getYTamano(){
    return yTamano;
}
int Imagen::getMaxIntensidad(){
    return maxIntensidad;
}
std::list<std::list<int>> Imagen::getLista(){
    return lista;
}
