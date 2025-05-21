#include "../MapaDeCitaciones.h"
#include <iostream>

void ejecutarAlgoritmo3(MapaDeCitaciones& mapa) {
    std::string id;
    std::cout << "\n\nID del articulo para indice de referenciacion: ";
    std::getline(std::cin, id);
    double indice = mapa.calcularIndiceReferenciacion(id);
    std::cout << "\nIndice de referenciacion: " << indice << std::endl;
}
