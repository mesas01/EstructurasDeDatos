#ifndef MAPADECITACIONES_H
#define MAPADECITACIONES_H

#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
#include "Articulo.h"

class MapaDeCitaciones {
private:
    std::unordered_map<std::string, Articulo> articulos;  // ID → Artículo

    void dfs(const std::string& id, std::unordered_set<std::string>& visitados, bool usarCitadores) const;

public:
    void agregarArticulo(const Articulo& art);
    void agregarCita(const std::string& origenId, const std::string& destinoId);

    void cargarDesdeArchivo(MapaDeCitaciones& mapa, const std::string& ruta);

    std::string articuloMasCitado();                       // Algoritmo 1
    int contarGruposTrasEliminar(const std::string& id);   // Algoritmo 2
    double calcularIndiceReferenciacion(const std::string& id); // Algoritmo 3
    int contarCitacionesIndirectas(const std::string& id);      // Algoritmo 4
};

#endif
