#include <iostream>
#include "interfaz.h"

void mostrarBienvenida() {
    std::cout << "=========================================\n";
    std::cout << "||                                     ||\n";
    std::cout << "||      BIENVENIDO AL SISTEMA DE       ||\n";
    std::cout << "||      PROCESAMIENTO DE IMÁGENES      ||\n";
    std::cout << "||                                     ||\n";
    std::cout << "||         Desarrollado por:           ||\n";
    std::cout << "||  Santiago Mesa & Jeronimo Chaparro  ||\n";
    std::cout << "||                                     ||\n";
    std::cout << "=========================================\n";
    std::cout << "||                                     ||\n";
    std::cout << "||   Usa el comando 'ayuda' para       ||\n";
    std::cout << "||   ver la lista de comandos.         ||\n";
    std::cout << "||                                     ||\n";
    std::cout << "=========================================\n\n";
}

void ayuda() {
    std::cout << "===================================================\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   MENÚ DE AYUDA                               ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "===================================================\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   Comandos disponibles:                       ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   1. ayuda                                    ||\n";
    std::cout << "||      - Muestra esta lista.                    ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   2. cargar_imagen <nombre_imagen.pgm>        ||\n";
    std::cout << "||      - Carga una imagen en memoria.           ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   3. cargar_volumen <nombre_base> <n_im>      ||\n";
    std::cout << "||      - Carga un volumen en memoria.           ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   4. info_imagen                              ||\n";
    std::cout << "||      - Muestra información de la imagen       ||\n";
    std::cout << "||        cargada.                               ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   5. info_volumen                             ||\n";
    std::cout << "||      - Muestra información del volumen        ||\n";
    std::cout << "||        cargado.                               ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   6. proyeccion2D <dirección> <criterio>      ||\n";
    std::cout << "||      <nombre_archivo.pgm>                     ||\n";
    std::cout << "||      - Genera una proyección 2D.              ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   7. codificar_imagen <nombre_archivo.pgm>    ||\n";
    std::cout << "||      - Codifica la imagen en memoria.         ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   8. decodificar_archivo <nombre_archivo.pgm> ||\n";
    std::cout << "||      <nombre_imagen.pgm>                      ||\n";
    std::cout << "||      - Decodifica un archivo.                 ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   9. segmentar <salida_imagen.pgm> <semillas> ||\n";
    std::cout << "||      - Segmenta una imagen.                   ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "||   10. salir                                   ||\n";
    std::cout << "||      - Sale del programa.                     ||\n";
    std::cout << "||                                               ||\n";
    std::cout << "===================================================\n\n";
}