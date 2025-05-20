#include "../MapaDeCitaciones.h"
#include <iostream>

void ejecutarAlgoritmo1(MapaDeCitaciones& mapa) {
    std::string resultado = mapa.articuloMasCitado();
    if (!resultado.empty()) {
        std::cout << "Artículo más citado: " << resultado << std::endl;
    } else {
        std::cout << "No hay artículos citados aún." << std::endl;
    }
}
