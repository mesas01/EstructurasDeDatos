#include "Articulo.h"

// Constructor de la clase Articulo
Articulo::Articulo(const std::string& id,
                   const std::string& titulo,
                   const std::vector<std::string>& autores,
                   const std::string& revista,
                   const std::string& volumen,
                   int año)
    : id(id), titulo(titulo), autores(autores),
      revista(revista), volumen(volumen), año(año) {}

// Devuelve el ID del articulo
std::string Articulo::getId() const {
    return id;
}

// Devuelve el titulo del articulo
std::string Articulo::getTitulo() const {
    return titulo;
}

// Devuelve el conjunto de articulos citados por este articulo
const std::unordered_set<std::string>& Articulo::getCitados() const {
    return citados;
}

// Devuelve el conjunto de articulos que citan a este articulo
const std::unordered_set<std::string>& Articulo::getCitadores() const {
    return citadores;
}

// Agrega un articulo al conjunto de citados
void Articulo::agregarCitado(const std::string& destinoId) {
    citados.insert(destinoId);
}

// Agrega un articulo al conjunto de citadores
void Articulo::agregarCitador(const std::string& origenId) {
    citadores.insert(origenId);
}
