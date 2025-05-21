#include "../MapaDeCitaciones.h"
#include <iostream>

// Funcion que ejecuta el algoritmo para mostrar el articulo mas citado
void ejecutarAlgoritmo1(MapaDeCitaciones& mapa) {
    // Obtiene el ID o nombre del articulo mas citado
    std::string resultado = mapa.articuloMasCitado();
    if (!resultado.empty()) {
        // Si hay resultado, lo muestra en pantalla
        std::cout << "\n\nArticulo mas citado: " << resultado << "\n"<<std::endl;
    } else {
        // Si no hay articulos citados, muestra mensaje
        std::cout << "No hay articulos citados aun." << std::endl;
    }
}
