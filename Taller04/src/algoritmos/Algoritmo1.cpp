#include "../MapaDeCitaciones.h"
#include <iostream>

void ejecutarAlgoritmo1(MapaDeCitaciones& mapa) {
    std::string resultado = mapa.articuloMasCitado();
    if (!resultado.empty()) {
        std::cout << "\n\nArticulo mas citado: " << resultado << "\n"<<std::endl;
    } else {
        std::cout << "No hay articulos citados aun." << std::endl;
    }
}
