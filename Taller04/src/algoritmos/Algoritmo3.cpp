#include "../MapaDeCitaciones.h"
#include <iostream>

// Funcion que ejecuta el algoritmo para calcular el indice de referenciacion de un articulo
void ejecutarAlgoritmo3(MapaDeCitaciones& mapa) {
    std::string id;
    // Solicita al usuario el ID del articulo
    std::cout << "\n\nID del articulo para indice de referenciacion: ";
    std::getline(std::cin, id);
    // Calcula el indice de referenciacion usando el metodo del mapa
    double indice = mapa.calcularIndiceReferenciacion(id);
    // Muestra el resultado en pantalla
    std::cout << "\nIndice de referenciacion: " << indice << std::endl;
}
