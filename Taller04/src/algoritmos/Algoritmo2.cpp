#include "../MapaDeCitaciones.h"
#include <iostream>

void ejecutarAlgoritmo2(MapaDeCitaciones& mapa) {
    std::string id;
    std::cout << "\n\nID del articulo a eliminar: ";
    std::getline(std::cin, id);
    int grupos = mapa.contarGruposTrasEliminar(id);
    std::cout << "Grupos resultantes tras eliminar: " << grupos << std::endl;
}
