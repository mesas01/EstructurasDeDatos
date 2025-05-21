#include "../MapaDeCitaciones.h"
#include <iostream>

// Funcion que ejecuta el algoritmo para contar citaciones indirectas de un articulo
void ejecutarAlgoritmo4(MapaDeCitaciones& mapa) {
    std::string id;
    // Solicita al usuario el ID del articulo
    std::cout << "\n\nID del articulo para citaciones indirectas: ";
    std::getline(std::cin, id);
    // Llama al metodo para contar las citaciones indirectas
    int cantidad = mapa.contarCitacionesIndirectas(id);
    // Muestra el resultado en pantalla
    std::cout << "\nCantidad de citaciones indirectas: " << cantidad << std::endl;
}
