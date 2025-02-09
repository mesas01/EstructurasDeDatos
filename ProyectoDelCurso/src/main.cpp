#include <iostream>
#include <string>
#include <vector>
#include "interfaz.h"
#include "comandos.h"
#include "utilidades.h"

int main() {
    std::string comando;
    std::vector<std::string> argumentos;

    mostrarBienvenida(); // Mostrar el menu de bienvenida

    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, comando);

        // Dividir el comando en partes (comando principal + argumentos)
        argumentos = dividirComando(comando);

        if (argumentos.empty()) {
            continue; // Si no se ingresó ningún comando, continuar
        }

        // Validar y ejecutar el comando
        if (argumentos[0] == "ayuda" || argumentos[0] == "AYUDA") {
            ayuda();
        } else if (argumentos[0] == "cargar_imagen") {
            cargarImagen(argumentos);
        } else if (argumentos[0] == "cargar_volumen") {
            cargarVolumen(argumentos);
        } else if (argumentos[0] == "info_imagen") {
            infoImagen();
        } else if (argumentos[0] == "info_volumen") {
            infoVolumen();
        } else if (argumentos[0] == "proyeccion2D") {
            proyeccion2D(argumentos);
        } else if (argumentos[0] == "codificar_imagen") {
            codificarImagen(argumentos);
        } else if (argumentos[0] == "decodificar_archivo") {
            decodificarArchivo(argumentos);
        } else if (argumentos[0] == "segmentar") {
            segmentar(argumentos);
        } else if (argumentos[0] == "salir") {
            break; // Salir del programa
        } else {
            std::cout << "Error: Comando no reconocido. Use 'ayuda' para ver la lista de comandos.\n";
        }
    }

    return 0;
}