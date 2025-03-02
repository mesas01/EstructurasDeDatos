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
    std::cout << "Se ha ingresado la imagen: " << argumentos[1] << ".\n";
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

    //std::cout << "Tamano de la lista en X: " << imagen.getLista().front().size() << std::endl;
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
    std::list<Imagen> lImagenes;

    std::string ultimos22 = nombreBase.erase(0, 15);
    if (ultimos22.size() > 15) {
        ultimos22.erase(ultimos22.size() - 4, 4); // Elimina los últimos 4 caracteres
    }else {
        ultimos22.erase(ultimos22.size() - 3, 3); // Elimina los últimos 4 caracteres
    }
    for (int i= 1; i <= nImagenes; i++) {
        std::cout << "Valor de i: " << i << std::endl;
        // Construye el nombre del archivo con dos dígitos (01, 02, ..., 10, etc.)
        std::string nombreArchivo = "imagenesPrueba/" + nombreBase + "/" + ultimos22 + "0" + std::to_string(i) + ".ppm";
        //std::string nombreArchivo = "imagenesPrueba/" + nombreBase + (i < 10 ? "0" : "") + std::to_string(i) + ".ppm";
        std::cout << "NOMBRE DEL ARCHIVO: " << nombreArchivo << std::endl;
        if (!archivoExiste(nombreArchivo)) {
            std::cout << "Error: El archivo " << nombreArchivo << " no existe.\n";
            todasExisten = false;
        }

        argumentosI.push_back("vacio");
        argumentosI.push_back(nombreArchivo);
        cargarImagen(argumentosI);
        lImagenes.push_back(imagen);
        argumentosI.clear();

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
    volumen.setLista(lImagenes);
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
        std::cout << "El volumen aun no ha sido cargado en memoria.\n";
        return;
    }
    if (volumen.getLista().empty()) {
        std::cerr << "Error: La lista de volumen está vacía.\n";
        return;
    }

    /*auto primeraImagen = volumen.getLista().front();
    auto primeraLista = primeraImagen.getLista().front();
    std::cout << "Tamano de la primera lista en X: " << primeraLista.size() << std::endl;*/

    std::string direccion = argumentos[1];
    std::string criterio = argumentos[2];
    std::string nombreArchivo = argumentos[3];

    if (criterio != "mediana" && criterio != "minimo" && criterio != "maximo" && criterio != "promedio"){
        std::cout << "El Criterio ingresado no es valido.\n";
        return;
    }
    std::list<std::list<int>> proyeccion;

    if (direccion == "x") {
        for (auto it = volumen.getLista().begin(); it != volumen.getLista().end(); ++it){ //Recorre la lista de imagenes que seria el eje z
            std::list<int> fila;
            //std::cout << "Recorriendo el eje Z...\n";
            for(auto it2 = it->getLista().begin(); it2 != it->getLista().end(); ++it2){ //Recorre la lista de listas de enteros, donde se guardan los pixeles en el eje y
                /*std::cout << "Recorriendo el eje Y...\n";
                std::cout << "Tamaño de la lista de enteros: " << it2->size() << "\n";*/
                int minimo = 255;
                int maximo = 0;
                int promedio = 0;
                if (criterio == "mediana"){
                    std::vector<int> copia (it2->begin(),it2->end()); //Copia la lista de enteros en un vector copia
                    sort(copia.begin(), copia.end());
                    fila.push_back(copia[copia.size()/2]);
                }else if (criterio == "minimo"){
                    for(auto it3 = it2->begin(); it3 != it2->end(); ++it3){
                        if(*it3 < minimo){ //Busca el minimo valor de la lista de enteros, que son los pixeles en x
                            minimo = *it3;
                        }
                    }
                    fila.push_back(minimo); //Proyecta el minimo valor de la lista de enteros, a lo que va a ser la primera fila de la proyeccion
                } else if (criterio == "maximo"){
                    for(auto it3 = it2->begin(); it3 != it2->end(); ++it3){
                        if(*it3 > maximo){ //Busca el maximo valor de la lista de enteros, que son los pixeles en x
                            maximo = *it3;
                        }
                    }
                    fila.push_back(maximo); //Proyecta el maximo valor de la lista de enteros, a lo que va a ser la primera fila de la proyeccion
                }else if (criterio == "promedio"){
                    for(auto it3 = it2->begin(); it3 != it2->end(); ++it3){
                        promedio += *it3; //Suma todos los valores de la lista de enteros, que son los pixeles en x
                    }
                    promedio = promedio / it2->size(); //Divide la suma de los valores de la lista de enteros, que son los pixeles en x, entre el tamaño de la lista
                    fila.push_back(promedio); //Proyecta el promedio de la lista de enteros, a lo que va a ser la primera fila de la proyeccion
                } else {
                    std::cout << "Error: Criterio no valido.\n";
                    return;
                }
            }
            proyeccion.push_back(fila); //Agrega la fila a la proyeccion  
            fila.clear();
        }
    } else if (direccion == "y") {
        
    } else if (direccion == "z") {
        int minimo = 255;
        std::list<int> fila;
        std::list<int> lpp;
        for (auto it = volumen.getLista().begin(); it != volumen.getLista().end(); ++it){ //Recorre la lista de imagenes que seria el eje z  
            
            
        }
        for(auto it = lpp.begin(); it != lpp.end(); ++it){
            if(*it < minimo){
                minimo = *it;
            }
        }

    } else {
        std::cout << "Error: Dirección no válida.\n";
        return;
    }

    guardarPGM(proyeccion, nombreArchivo);
    std::cout << "La proyección 2D del volumen en memoria ha sido generada y almacenada en el archivo " << nombreArchivo << ".\n";
}
//Funcion para guardar la proyeccion en un archivo
void guardarPGM(const std::list<std::list<int>>& proyeccion, const std::string& nombreArchivo) {
    std::cout << "Intentando guardar el archivo: " << nombreArchivo << "\n";
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "La proyección 2D del volumen en memoria no ha podido ser generada.\n";
        return;
    }
    
    archivo << "P2\n" << proyeccion.front().size() << " " << proyeccion.size() << "\n255\n"; //Se ingresa en el archivo el tamaño en e X y luego el tamoño en Y
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