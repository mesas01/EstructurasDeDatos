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
bool cargadaI = false;
Volumen volumen;
bool cargadaV = false;
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
    std::ifstream archivo(argumentos[1]);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return;
    }
    std::string codigo;
    int xTamano, yTamano, maxIntensidad;

    // Leer el encabezado
    archivo >> codigo >> xTamano >> yTamano >> maxIntensidad;

    // Configurar el objeto Imagen
    imagen.setNombre(argumentos[1]);
    imagen.setCodigo(codigo);
    imagen.setXTamano(xTamano);
    imagen.setYTamano(yTamano);
    imagen.setMaxIntensidad(maxIntensidad);

    // Leer los píxeles y almacenarlos en la lista de listas
    std::list<std::list<int>> listaPixeles;
    for (int y = 0; y < yTamano; ++y) {
        std::list<int> fila;
        for (int x = 0; x < xTamano; ++x) { // *3 porque cada píxel tiene R, G y B
            int valor;
            archivo >> valor;
            fila.push_back(valor);
        }
        listaPixeles.push_back(fila);
    }

    imagen.setLista(listaPixeles);
    cargadaI = true;
    archivo.close();
    //std::cout << "Tamano de la lista: " << imagen.getLista().size() << " yTamano: " << imagen.getYTamano() << std::endl;
    if(imagen.getLista().size() != imagen.getYTamano()){ //CUANDO SE CARGA EL ARCHIVO img_02.pgm EL TAMAÑO DE LA LISTA ES 1- CON RESPECTO A LO QUE DICE AL TAMAÑO DE Y NO SE POR QUÉ
        std::cout << "Error: El archivo no tiene el tamano correcto de Columnas.\n";
        return;
    }
    std::cout << "La imagen " << argumentos[1] << " ha sido cargada.\n";
}
/*Funcion para cargar un volumen*/
void cargarVolumen(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 3) {
        std::cout << "Error: Uso correcto -> cargar_volumen <nombre_base> <n_im>\n";
        return;
    }
    std::string nombre;
    std::vector<std::string> argumentosI;
    std::string nombreBase = argumentos[1];
    int nImagenes = std::stoi(argumentos[2]);
    bool todasExisten = true;

    std::string ultimos22 = nombreBase.substr(nombreBase.size() > 16 ? nombreBase.size() - 16 : 0);
    if (ultimos22.size() >= 3) {
        ultimos22.erase(ultimos22.size() - 3, 3); // Elimina los últimos 4 caracteres
    }
    for (int i = 1; i <= nImagenes; ++i) {
        // Construye el nombre del archivo con dos dígitos (01, 02, ..., 10, etc.)
        std::string nombreArchivo = nombreBase + ultimos22 + "0" + std::to_string(i) + ".ppm";
        if (!archivoExiste(nombreArchivo)) {
            std::cout << "Error: El archivo " << nombreArchivo << " no existe.\n";
            todasExisten = false;
        }

        argumentosI.push_back("vacio");
        argumentosI.push_back(nombreArchivo);
        cargarImagen(argumentosI);
        volumen.getLista().push_back(imagen);

    }
    cargadaV = true;
    cargadaI = false;
    if (todasExisten) {
        std::cout << "El volumen " << nombreBase << " ha sido cargado.\n";
    } else {
        std::cout << "Error: No se pudo cargar el volumen debido a archivos faltantes.\n";
        return;
    }
    volumen.setNombre(nombreBase);
    volumen.setNImagenes(nImagenes);
}

void infoImagen() {
    if(!cargadaI){
        std::cout << "Error: No hay ninguna imagen cargada en memoria.\n";
        return;
    }
    std::cout << "Imagen cargada en memoria: " << imagen.getNombre() << ", ancho: " << imagen.getXTamano() <<", alto: " << imagen.getYTamano() <<".\n";
}

void infoVolumen() {
    if(!cargadaV){
        std::cout << "Error: No hay ningun volumen cargad en memoria.\n";
        return;
    }
    std::cout << "Volumen cargado en memoria: " << volumen.getNombre() << ", Tamano: " << volumen.getNImagenes() << ".\n";
}
//funcion para la proyeccion 2D
void proyeccion2D(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 4) {
        std::cout << "Error: Uso correcto -> proyeccion2D <dirección> <criterio> <nombre_archivo.pgm>\n";
        return;
    }
    if (!cargadaV) {
        std::cout << "El volumen aún no ha sido cargado en memoria.\n";
        return;
    }

    std::string direccion = argumentos[1];
    std::string criterio = argumentos[2];
    std::string nombreArchivo = argumentos[3];

    int xTamano = volumen.getLista().front().getXTamano();
    int yTamano = volumen.getLista().front().getYTamano();
    int zTamano = volumen.getNImagenes();

    std::list<std::list<int>> proyeccion;

    if (direccion == "x") {
        generarProyeccion(proyeccion, xTamano, yTamano, criterio);
    } else if (direccion == "z") {
        generarProyeccion(proyeccion, zTamano, xTamano, criterio);
    } else if (direccion == "y") {
        generarProyeccion(proyeccion, yTamano, zTamano, criterio);
    } else {
        std::cout << "Error: Dirección no válida.\n";
        return;
    }

    guardarPGM(proyeccion, nombreArchivo, xTamano, yTamano);
    std::cout << "La proyección 2D del volumen en memoria ha sido generada y almacenada en el archivo " << nombreArchivo << ".\n";
}
//Funcion para generar la proyeccion
void generarProyeccion(std::list<std::list<int>>& proyeccion, int xTamano, int yTamano, const std::string& criterio) {
    for (int y = 0; y < yTamano; ++y) {
        std::list<int> fila;
        for (int x = 0; x < xTamano; ++x) {
            std::vector<int> profundidad;
            for (const auto& imagen : volumen.getLista()) {
                auto itFila = std::next(imagen.getLista().begin(), y);
                auto itValor = std::next(itFila->begin(), x);
                profundidad.push_back(*itValor);
            }
            fila.push_back(procesarCriterio(profundidad, criterio));
        }
        proyeccion.push_back(fila);
    }
}
//Funcion para procesar el criterio
int procesarCriterio(const std::vector<int>& valores, const std::string& criterio) {
    if (valores.empty()) return 0;
    if (criterio == "minimo") return *std::min_element(valores.begin(), valores.end());
    if (criterio == "maximo") return *std::max_element(valores.begin(), valores.end());
    if (criterio == "promedio") return std::accumulate(valores.begin(), valores.end(), 0) / valores.size();
    if (criterio == "mediana") {
        std::vector<int> copia = valores;
        std::sort(copia.begin(), copia.end());
        return copia[copia.size() / 2];
    }
    return 0;
}
//Funcion para guardar la proyeccion en un archivo
void guardarPGM(const std::list<std::list<int>>& proyeccion, const std::string& nombreArchivo, int xTamano, int yTamano) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "La proyección 2D del volumen en memoria no ha podido ser generada.\n";
        return;
    }
    archivo << "P2\n" << xTamano << " " << yTamano << "\n255\n";
    for (const auto& fila : proyeccion) {
        for (int valor : fila) {
            archivo << valor << " ";
        }
        archivo << "\n";
    }
    archivo.close();
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