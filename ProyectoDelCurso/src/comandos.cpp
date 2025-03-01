/************************************************
 * PROYECTO 1
 * FECHA: 12-02-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: COMANDOS.CPP
 ***********************************************/
#include <iostream>
#include "comandos.h"
#include "clases.h"
#include <fstream>
/*Creamos una clase de tipo Imagen*/
Imagen imagen;
/*Funcion que veifica si el archivo existe*/
bool archivoExiste(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    return archivo.good();
}

/*Funcion para cargar una imagen*/
void cargarImagen(const std::vector<std::string>& argumentos) {
    if (!archivoExiste(argumentos[1])) {
        std::cout << "Error: El archivo no existe.\n";
        return;
    }
    std::string nombre = argumentos[1];   
    std::string codigo;
    int xTamano;
    int yTamano;
    int maxIntensidad;
    std::list<std::list<int>> lista;
    std::list<int> fila;
    std::ifstream archivo(nombre);
    std::string palabra;
    int num;
    
    archivo >> codigo;
    archivo >> xTamano;
    archivo >> yTamano;
    archivo >> maxIntensidad;
    while (archivo >> palabra) {
        for(int contador = 0; contador < xTamano; contador++, archivo >> palabra){
            num = std::stoi(palabra);
            fila.push_back(num);
        }
        lista.push_back(fila);
        fila.clear();
    }
    archivo.close();
    if(lista.size() > yTamano){ //CUANDO SE CARGA EL ARCHIVO img_02.pgm EL TAMAÑO DE LA LISTA ES 1- CON RESPECTO A LO QUE DICE AL TAMAÑO DE Y NO SE POR QUÉ
        std::cout << "Error: El archivo no tiene el tamano correcto de Columnas.\n";
        return;
    }
    imagen.setNombre(nombre);
    imagen.setCodigo(codigo);
    imagen.setXTamano(xTamano);
    imagen.setYTamano(yTamano);
    imagen.setMaxIntensidad(maxIntensidad);
    imagen.setLista(lista);
    std::cout << "La imagen " << argumentos[1] << " ha sido cargada.\n";
}
/*Funcion para cargar un volumen*/
void cargarVolumen(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 3) {
        std::cout << "Error: Uso correcto -> cargar_volumen <nombre_base> <n_im>\n";
        return;
    }

    std::string nombreBase = argumentos[1];
    int nImagenes = std::stoi(argumentos[2]);
    bool todasExisten = true;

    for (int i = 1; i <= nImagenes; ++i) {
        // Construye el nombre del archivo con dos dígitos (01, 02, ..., 10, etc.)
        std::string nombreArchivo = nombreBase + (i < 10 ? "0" : "") + std::to_string(i) + ".ppm";
        if (!archivoExiste(nombreArchivo)) {
            std::cout << "Error: El archivo " << nombreArchivo << " no existe.\n";
            todasExisten = false;
        }
    }

    if (todasExisten) {
        std::cout << "El volumen " << nombreBase << " ha sido cargado.\n";
    } else {
        std::cout << "Error: No se pudo cargar el volumen debido a archivos faltantes.\n";
    }
}

void infoImagen() {
    std::cout << "Información de la imagen cargada.\n";
}

void infoVolumen() {
    std::cout << "Información del volumen cargado.\n";
}
//funcion para la proyeccion 2D
void proyeccion2D(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 4) {
        std::cout << "Error: Uso correcto -> proyeccion2D <dirección> <criterio> <nombre_archivo.pgm>\n";
        return;
    }
    std::cout << "Proyección 2D generada y almacenada en " << argumentos[3] << ".\n";
}
//Funcion para codificar imagenes
void codificarImagen(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 2) {
        std::cout << "Error: Uso correcto -> codificar_imagen <nombre_archivo.pgm>\n";
        return;
    }
    std::cout << "La imagen ha sido codificada y almacenada en " << argumentos[1] << ".\n";
}
//Funcion para decodificar un archivo
void decodificarArchivo(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 3) {
        std::cout << "Error: Uso correcto -> decodificar_archivo <nombre_archivo.pgm> <nombre_imagen.pgm>\n";
        return;
    }
    std::cout << "El archivo " << argumentos[1] << " ha sido decodificado y almacenado en " << argumentos[2] << ".\n";
}
//Funcion para segmentar 
void segmentar(const std::vector<std::string>& argumentos) {
    if (argumentos.size() < 3) {
        std::cout << "Error: Uso correcto -> segmentar <salida_imagen.pgm> <semillas>\n";
        return;
    }
    std::cout << "La imagen ha sido segmentada y almacenada en " << argumentos[1] << ".\n";
}