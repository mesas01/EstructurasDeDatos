#include "../MapaDeCitaciones.h"
#include <iostream>

// Funcion que ejecuta el algoritmo para contar grupos tras eliminar un articulo
void ejecutarAlgoritmo2(MapaDeCitaciones& mapa) {
    std::string id;
    // Solicita al usuario el ID del articulo a eliminar
    std::cout << "\n\nID del articulo a eliminar: ";
    std::getline(std::cin, id);
    // Llama al metodo para contar los grupos resultantes tras eliminar el articulo
    int grupos = mapa.contarGruposTrasEliminar(id);
    // Muestra el resultado en pantalla
    std::cout << "Grupos resultantes tras eliminar: " << grupos << std::endl;
}
