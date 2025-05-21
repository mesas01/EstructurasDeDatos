#include "MapaDeCitaciones.h"
#include <queue>     // No se usa aquí, pero podría ser útil para BFS
#include <stack>     // Se usa para DFS
#include <algorithm> // Funciones STL (no se usa explícitamente aquí)
#include <iostream>  // Para depuración o mensajes

// ======================= MÉTODO: Agregar Artículo =========================
void MapaDeCitaciones::agregarArticulo(const Articulo& art) {
    // Inserta un artículo en el mapa con su ID como clave
    articulos[art.getId()] = art;
}

// ======================= MÉTODO: Agregar Citación =========================
void MapaDeCitaciones::agregarCita(const std::string& origenId, const std::string& destinoId) {
    // Verifica que ambos artículos existan
    if (articulos.find(origenId) != articulos.end() && articulos.find(destinoId) != articulos.end()) {
        // Añade destino como citado por origen
        articulos[origenId].agregarCitado(destinoId);
        // Añade origen como citador del destino
        articulos[destinoId].agregarCitador(origenId);
    }
}

// ======================= ALGORITMO 1 ============================
// Encuentra el artículo que más veces ha sido citado
std::string MapaDeCitaciones::articuloMasCitado() {
    int maxCitaciones = -1;
    std::string idMasCitado;

    for (const auto& [id, articulo] : articulos) {
        int cantidad = articulo.getCitadores().size(); // cantidad de citadores del artículo
        if (cantidad > maxCitaciones) {
            maxCitaciones = cantidad;
            idMasCitado = articulo.getTitulo(); // guarda el título del más citado
        }
    }

    return idMasCitado; // retorna el título del artículo más citado
}

// ======================= ALGORITMO 2 ============================
// DFS para recorrer el grafo a partir de un nodo
void MapaDeCitaciones::dfs(const std::string& id, std::unordered_set<std::string>& visitados, bool usarCitadores) const {
    std::stack<std::string> pila;
    pila.push(id);
    visitados.insert(id); // Marca como visitado

    while (!pila.empty()) {
        std::string actual = pila.top();
        pila.pop();

        // Escoge vecinos según dirección: citadores o citados
        const auto& vecinos = usarCitadores ?
            articulos.at(actual).getCitadores() :
            articulos.at(actual).getCitados();

        for (const auto& vecino : vecinos) {
            // Solo visitar vecinos existentes no visitados
            if (articulos.find(vecino) != articulos.end() && visitados.find(vecino) == visitados.end()) {
                visitados.insert(vecino);
                pila.push(vecino);
            }
        }
    }
}

// Cuenta cuántos grupos (componentes conectados) quedan tras eliminar un nodo
int MapaDeCitaciones::contarGruposTrasEliminar(const std::string& id) {
    std::unordered_set<std::string> visitados;
    int grupos = 0;

    for (const auto& [otroId, _] : articulos) {
        if (otroId == id) continue; // saltar el nodo eliminado
        if (visitados.find(otroId) == visitados.end()) {
            // Realiza DFS desde este nodo si no ha sido visitado
            dfs(otroId, visitados, false); // false → usa citados como vecinos
            grupos++; // nuevo componente encontrado
        }
    }

    return grupos; // total de componentes conectados
}

// ======================= ALGORITMO 3 ============================
// Calcula el índice de referenciación de un artículo
double MapaDeCitaciones::calcularIndiceReferenciacion(const std::string& id) {
    // Si no existe el artículo, retorna 0
    if (articulos.find(id) == articulos.end()) return 0;

    int citadores = articulos[id].getCitadores().size();
    int citados = articulos[id].getCitados().size();

    // Evita división por cero
    if (citados == 0) return 0;

    // Fórmula: citadores / (0.5 * citados)
    return static_cast<double>(citadores) / (0.5 * citados);
}

// ======================= ALGORITMO 4 ============================
// Cuenta las citaciones indirectas de un artículo
int MapaDeCitaciones::contarCitacionesIndirectas(const std::string& id) {
    // Verifica si el artículo existe
    if (articulos.find(id) == articulos.end()) return 0;

    std::unordered_set<std::string> directos = articulos[id].getCitados();  // artículos citados directamente
    std::unordered_set<std::string> indirectos;  // artículos citados indirectamente

    // Recorre cada artículo citado directamente
    for (const auto& intermedio : directos) {
        if (articulos.find(intermedio) != articulos.end()) {
            // Obtiene los citados por ese intermedio
            const auto& segundoNivel = articulos[intermedio].getCitados();

            for (const auto& candidato : segundoNivel) {
                // Si no es el artículo original ni está en los citados directos
                if (candidato != id && directos.find(candidato) == directos.end()) {
                    indirectos.insert(candidato);
                }
            }
        }
    }

    // Por seguridad, quitar duplicados y autoloops
    indirectos.erase(id);
    for (const auto& directo : directos) {
        indirectos.erase(directo);
    }

    return indirectos.size(); // Retorna la cantidad de citaciones indirectas
}
