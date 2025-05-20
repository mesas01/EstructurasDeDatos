#include "../MapaDeCitaciones.h"
#include <iostream>

void ejecutarAlgoritmo4(MapaDeCitaciones& mapa) {
    std::string id;
    std::cout << "ID del artículo para citaciones indirectas: ";
    std::getline(std::cin, id);
    int cantidad = mapa.contarCitacionesIndirectas(id);
    std::cout << "Cantidad de citaciones indirectas: " << cantidad << std::endl;
}
