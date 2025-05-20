#ifndef ARTICULO_H
#define ARTICULO_H

#include <string>
#include <vector>
#include <unordered_set>

class Articulo {
private:
    std::string id;
    std::string titulo;
    std::vector<std::string> autores;
    std::string revista;
    std::string volumen;
    int año;

    std::unordered_set<std::string> citados;
    std::unordered_set<std::string> citadores;

public:
    Articulo() = default; 

    Articulo(const std::string& id,
             const std::string& titulo,
             const std::vector<std::string>& autores,
             const std::string& revista,
             const std::string& volumen,
             int año);
             
    std::string getId() const;
    std::string getTitulo() const;
    const std::unordered_set<std::string>& getCitados() const;
    const std::unordered_set<std::string>& getCitadores() const;

    void agregarCitado(const std::string& destinoId);
    void agregarCitador(const std::string& origenId);
};

#endif
