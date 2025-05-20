#include "../MapaDeCitaciones.h"
#include <iostream>

void ejecutarAlgoritmo3(MapaDeCitaciones& mapa) {
    std::string id;
    std::cout << "ID del artículo para índice de referenciación: ";
    std::getline(std::cin, id);
    double indice = mapa.calcularIndiceReferenciacion(id);
    std::cout << "Índice de referenciación: " << indice << std::endl;
}
