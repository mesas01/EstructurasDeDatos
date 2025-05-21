#ifndef ARTICULO_H
#define ARTICULO_H

#include <string>
#include <vector>
#include <unordered_set>

// Clase que representa un artículo científico
class Articulo {
private:
    std::string id;                        // ID único del artículo
    std::string titulo;                    // Título del artículo
    std::vector<std::string> autores;      // Lista de autores
    std::string revista;                   // Nombre de la revista
    std::string volumen;                   // Volumen de la revista
    int año;                               // Año de publicación

    std::unordered_set<std::string> citados;    // IDs de artículos citados por este artículo
    std::unordered_set<std::string> citadores;  // IDs de artículos que citan a este artículo

public:
    Articulo() = default; // Constructor por defecto

    // Constructor con parámetros
    Articulo(const std::string& id,
             const std::string& titulo,
             const std::vector<std::string>& autores,
             const std::string& revista,
             const std::string& volumen,
             int año);
             
    // Devuelve el ID del artículo
    std::string getId() const;
    // Devuelve el título del artículo
    std::string getTitulo() const;
    // Devuelve el conjunto de artículos citados por este artículo
    const std::unordered_set<std::string>& getCitados() const;
    // Devuelve el conjunto de artículos que citan a este artículo
    const std::unordered_set<std::string>& getCitadores() const;

    // Agrega un artículo al conjunto de citados
    void agregarCitado(const std::string& destinoId);
    // Agrega un artículo al conjunto de citadores
    void agregarCitador(const std::string& origenId);
};

#endif
