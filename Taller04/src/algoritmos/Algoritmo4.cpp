#include "../MapaDeCitaciones.h"
#include <iostream>

void ejecutarAlgoritmo4(MapaDeCitaciones& mapa) {
    std::string id;
    std::cout << "\n\nID del articulo para citaciones indirectas: ";
    std::getline(std::cin, id);
    int cantidad = mapa.contarCitacionesIndirectas(id);
    std::cout << "\nCantidad de citaciones indirectas: " << cantidad << std::endl;
}
