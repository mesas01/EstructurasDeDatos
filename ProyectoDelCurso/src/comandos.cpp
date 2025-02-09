#include <iostream>
#include "comandos.h"

void cargarImagen(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 2) {
        std::cout << "Error: Uso correcto -> cargar_imagen <nombre_imagen.pgm>\n";
        return;
    }
    std::cout << "La imagen " << argumentos[1] << " ha sido cargada.\n";
}

void cargarVolumen(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 3) {
        std::cout << "Error: Uso correcto -> cargar_volumen <nombre_base> <n_im>\n";
        return;
    }
    std::cout << "El volumen " << argumentos[1] << " ha sido cargado.\n";
}

void infoImagen() {
    std::cout << "Información de la imagen cargada.\n";
}

void infoVolumen() {
    std::cout << "Información del volumen cargado.\n";
}

void proyeccion2D(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 4) {
        std::cout << "Error: Uso correcto -> proyeccion2D <dirección> <criterio> <nombre_archivo.pgm>\n";
        return;
    }
    std::cout << "Proyección 2D generada y almacenada en " << argumentos[3] << ".\n";
}

void codificarImagen(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 2) {
        std::cout << "Error: Uso correcto -> codificar_imagen <nombre_archivo.huf>\n";
        return;
    }
    std::cout << "La imagen ha sido codificada y almacenada en " << argumentos[1] << ".\n";
}

void decodificarArchivo(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 3) {
        std::cout << "Error: Uso correcto -> decodificar_archivo <nombre_archivo.huf> <nombre_imagen.pgm>\n";
        return;
    }
    std::cout << "El archivo " << argumentos[1] << " ha sido decodificado y almacenado en " << argumentos[2] << ".\n";
}

void segmentar(const std::vector<std::string>& argumentos) {
    if (argumentos.size() < 3) {
        std::cout << "Error: Uso correcto -> segmentar <salida_imagen.pgm> <semillas>\n";
        return;
    }
    std::cout << "La imagen ha sido segmentada y almacenada en " << argumentos[1] << ".\n";
}