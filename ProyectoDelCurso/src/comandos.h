#ifndef COMANDOS_H
#define COMANDOS_H

#include <vector>
#include <string>

void cargarImagen(const std::vector<std::string>& argumentos);
void cargarVolumen(const std::vector<std::string>& argumentos);
void infoImagen();
void infoVolumen();
void proyeccion2D(const std::vector<std::string>& argumentos);
void codificarImagen(const std::vector<std::string>& argumentos);
void decodificarArchivo(const std::vector<std::string>& argumentos);
void segmentar(const std::vector<std::string>& argumentos);

#endif