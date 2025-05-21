#include "cargar_archivo.h"
#include <fstream>
#include <sstream>
#include <iostream>

void cargarDesdeArchivo(MapaDeCitaciones& mapa, const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << ruta << std::endl;
        return;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        if (linea.empty() || linea[0] == '#') continue;

        if (linea.find("ARTICULO") == 0) {
            size_t pos = linea.find(' ');
            linea = linea.substr(pos + 1);

            std::stringstream ss(linea);
            std::string id, titulo, revista, volumen, añoStr, autoresStr;

            getline(ss, id, '|');
            getline(ss, titulo, '|');
            getline(ss, revista, '|');
            getline(ss, volumen, '|');
            getline(ss, añoStr, '|');
            getline(ss, autoresStr);

            auto trim = [](std::string& s) {
                s.erase(0, s.find_first_not_of(" \t"));
                s.erase(s.find_last_not_of(" \t") + 1);
            };

            trim(id); trim(titulo); trim(revista); trim(volumen); trim(añoStr); trim(autoresStr);

            std::vector<std::string> autores;
            std::stringstream sa(autoresStr);
            std::string autor;
            while (getline(sa, autor, ',')) {
                trim(autor);
                autores.push_back(autor);
            }

            int año = std::stoi(añoStr);
            Articulo art(id, titulo, autores, revista, volumen, año);
            mapa.agregarArticulo(art);
        }
        else if (linea.find("CITA") == 0) {
            size_t pos1 = linea.find(' ');
            size_t pos2 = linea.find("->");

            std::string origen = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string destino = linea.substr(pos2 + 2);

            auto trim = [](std::string& s) {
                s.erase(0, s.find_first_not_of(" \t"));
                s.erase(s.find_last_not_of(" \t") + 1);
            };

            trim(origen);
            trim(destino);

            mapa.agregarCita(origen, destino);
        }
    }

    archivo.close();
}
