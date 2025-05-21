#include "MapaDeCitaciones.h"
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

void MapaDeCitaciones::agregarArticulo(const Articulo& art) {
    articulos[art.getId()] = art;
}

void MapaDeCitaciones::agregarCita(const std::string& origenId, const std::string& destinoId) {
    if (articulos.find(origenId) != articulos.end() && articulos.find(destinoId) != articulos.end()) {
        articulos[origenId].agregarCitado(destinoId);
        articulos[destinoId].agregarCitador(origenId);
    }
}

// ======================= ALGORITMO 1 ============================
std::string MapaDeCitaciones::articuloMasCitado() {
    int maxCitaciones = -1;
    std::string idMasCitado;

    for (const auto& [id, articulo] : articulos) {
        int cantidad = articulo.getCitadores().size();
        if (cantidad > maxCitaciones) {
            maxCitaciones = cantidad;
            idMasCitado = articulo.getTitulo();
        }
    }
    return idMasCitado;
}

// ======================= ALGORITMO 2 ============================
void MapaDeCitaciones::dfs(const std::string& id, std::unordered_set<std::string>& visitados, bool usarCitadores) const {
    std::stack<std::string> pila;
    pila.push(id);
    visitados.insert(id);

    while (!pila.empty()) {
        std::string actual = pila.top();
        pila.pop();

        const auto& vecinos = usarCitadores ?
            articulos.at(actual).getCitadores() :
            articulos.at(actual).getCitados();

        for (const auto& vecino : vecinos) {
            if (articulos.find(vecino) != articulos.end() && visitados.find(vecino) == visitados.end()) {
                visitados.insert(vecino);
                pila.push(vecino);
            }
        }
    }
}

int MapaDeCitaciones::contarGruposTrasEliminar(const std::string& id) {
    std::unordered_set<std::string> visitados;
    int grupos = 0;

    for (const auto& [otroId, _] : articulos) {
        if (otroId == id) continue;
        if (visitados.find(otroId) == visitados.end()) {
            dfs(otroId, visitados, false); // dfs por vecinos citados
            grupos++;
        }
    }

    return grupos;
}

// ======================= ALGORITMO 3 ============================
double MapaDeCitaciones::calcularIndiceReferenciacion(const std::string& id) {
    if (articulos.find(id) == articulos.end()) return 0;

    int citadores = articulos[id].getCitadores().size();
    int citados = articulos[id].getCitados().size();

    if (citados == 0) return 0; // evita división por cero

    return static_cast<double>(citadores) / (0.5 * citados);
}

// ======================= ALGORITMO 4 ============================
int MapaDeCitaciones::contarCitacionesIndirectas(const std::string& id) {
    if (articulos.find(id) == articulos.end()) return 0;

    std::unordered_set<std::string> directos = articulos[id].getCitados();
    std::unordered_set<std::string> indirectos;

    for (const auto& intermedio : directos) {
        if (articulos.find(intermedio) != articulos.end()) {
            const auto& segundoNivel = articulos[intermedio].getCitados();

            for (const auto& candidato : segundoNivel) {
                if (candidato != id && directos.find(candidato) == directos.end()) {
                    indirectos.insert(candidato);
                }
            }
        }
    }

    // Quitar cualquier posible autor ya citado directamente o a sí mismo
    indirectos.erase(id);  // nunca puede citarse a sí mismo como indirecto
    for (const auto& directo : directos) {
        indirectos.erase(directo); // eliminar citados directos
    }

    return indirectos.size();
}

