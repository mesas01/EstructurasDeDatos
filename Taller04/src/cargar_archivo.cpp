#include "cargar_archivo.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Funcion para cargar datos desde un archivo al mapa de citaciones
void cargarDesdeArchivo(MapaDeCitaciones& mapa, const std::string& ruta) {
    std::ifstream archivo(ruta); // Abre el archivo en modo lectura
    if (!archivo.is_open()) {
        // Si no se puede abrir, muestra un mensaje de error
        std::cerr << "No se pudo abrir el archivo: " << ruta << std::endl;
        return;
    }

    std::string linea;
    // Lee el archivo línea por línea
    while (getline(archivo, linea)) {
        // Ignora líneas vacías o comentarios
        if (linea.empty() || linea[0] == '#') continue;

        // Si la línea describe un artículo
        if (linea.find("ARTICULO") == 0) {
            size_t pos = linea.find(' ');
            linea = linea.substr(pos + 1);

            std::stringstream ss(linea);
            std::string id, titulo, revista, volumen, añoStr, autoresStr;

            // Extrae los campos separados por '|'
            getline(ss, id, '|');
            getline(ss, titulo, '|');
            getline(ss, revista, '|');
            getline(ss, volumen, '|');
            getline(ss, añoStr, '|');
            getline(ss, autoresStr);

            // Función lambda para quitar espacios al inicio y final
            auto trim = [](std::string& s) {
                s.erase(0, s.find_first_not_of(" \t"));
                s.erase(s.find_last_not_of(" \t") + 1);
            };

            // Limpia los campos de espacios
            trim(id); trim(titulo); trim(revista); trim(volumen); trim(añoStr); trim(autoresStr);

            // Separa los autores por coma
            std::vector<std::string> autores;
            std::stringstream sa(autoresStr);
            std::string autor;
            while (getline(sa, autor, ',')) {
                trim(autor);
                autores.push_back(autor);
            }

            // Convierte el año a entero y crea el artículo
            int año = std::stoi(añoStr);
            Articulo art(id, titulo, autores, revista, volumen, año);
            mapa.agregarArticulo(art);
        }
        // Si la línea describe una cita
        else if (linea.find("CITA") == 0) {
            size_t pos1 = linea.find(' ');
            size_t pos2 = linea.find("->");

            // Extrae el origen y destino de la cita
            std::string origen = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string destino = linea.substr(pos2 + 2);

            // Limpia los campos de espacios
            auto trim = [](std::string& s) {
                s.erase(0, s.find_first_not_of(" \t"));
                s.erase(s.find_last_not_of(" \t") + 1);
            };

            trim(origen);
            trim(destino);

            // Agrega la cita al mapa
            mapa.agregarCita(origen, destino);
        }
    }

    archivo.close(); // Cierra el archivo al finalizar
}
