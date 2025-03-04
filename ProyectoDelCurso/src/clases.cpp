/************************************************
 * PROYECTO 1
 * FECHA: 01-03-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: CLASES.CPP *
 ***********************************************/
#include "clases.h"

//Clase Imagen
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
std::string Imagen::getNombre() const {
    return nombre;
}
std::string Imagen::getCodigo() const {
    return codigo;
}
int Imagen::getXTamano()const{
    return xTamano;
}
int Imagen::getYTamano()const{
    return yTamano;
}
int Imagen::getMaxIntensidad()const{
    return maxIntensidad;
}
const std::list<std::list<int>>& Imagen::getLista() const {
    return lista;
}

//Clase Volumen
Volumen::~Volumen(){
    lista.clear();
}
void Volumen::setNombre(std::string nombre){
    this->nombre = nombre;
}
void Volumen::setNImagenes(int nImagenes){
    this->nImagenes = nImagenes;
}
void Volumen::setLista(std::list<Imagen> lista){
    this->lista = lista;
}
std::string Volumen::getNombre(){
    return nombre;
}
int Volumen::getNImagenes(){
    return nImagenes;
}
const std::list<Imagen>& Volumen::getLista() const {
    return lista;
}
