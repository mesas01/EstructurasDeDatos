#include "Articulo.h"

Articulo::Articulo(const std::string& id,
                   const std::string& titulo,
                   const std::vector<std::string>& autores,
                   const std::string& revista,
                   const std::string& volumen,
                   int año)
    : id(id), titulo(titulo), autores(autores),
      revista(revista), volumen(volumen), año(año) {}

std::string Articulo::getId() const {
    return id;
}

std::string Articulo::getTitulo() const {
    return titulo;
}

const std::unordered_set<std::string>& Articulo::getCitados() const {
    return citados;
}

const std::unordered_set<std::string>& Articulo::getCitadores() const {
    return citadores;
}

void Articulo::agregarCitado(const std::string& destinoId) {
    citados.insert(destinoId);
}

void Articulo::agregarCitador(const std::string& origenId) {
    citadores.insert(origenId);
}
