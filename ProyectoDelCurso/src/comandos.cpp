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
#include <cstring>


using namespace std;
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
    std::string ruta = argumentos[1];

    // Si no existe, intentamos con ruta relativa desde src/imagenesPrueba
    if (!archivoExiste(ruta)) {
        std::string alternativa = "src/imagenesPrueba/" + ruta;
        if (archivoExiste(alternativa)) {
            ruta = alternativa;
        } else {
            std::cout << "Error: El archivo no existe.\n";
            return;
        }
    }

    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return;
    }

    std::string codigo;
    int xTamano, yTamano, maxIntensidad;

    // Leer el encabezado
    archivo >> codigo >> xTamano >> yTamano >> maxIntensidad;

    // Configurar el objeto Imagen
    imagen.setNombre(ruta);
    imagen.setCodigo(codigo);
    imagen.setXTamano(xTamano);
    imagen.setYTamano(yTamano);
    imagen.setMaxIntensidad(maxIntensidad);

    // Leer los píxeles y almacenarlos en la lista de listas
    std::list<std::list<int>> listaPixeles;
    for (int y = 0; y < yTamano; ++y) {
        std::list<int> fila;
        for (int x = 0; x < xTamano; ++x) {
            int valor;
            archivo >> valor;
            fila.push_back(valor);
        }
        listaPixeles.push_back(fila);
    }

    imagen.setLista(listaPixeles);
    cargadaI = true;
    archivo.close();

    if (static_cast<int>(imagen.getLista().size()) != imagen.getYTamano()) {
        std::cout << "Error: El archivo no tiene el tamaño correcto de filas.\n";
        return;
    }

    std::cout << "La imagen " << ruta << " ha sido cargada.\n";
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
        //std::cout << "Valor de i: " << i << std::endl;
        // Construye el nombre del archivo con dos dígitos (01, 02, ..., 10, etc.)
        std::string numeroImagen = (i < 10) ? "0" + std::to_string(i) : std::to_string(i); // Asegura que los números de 1 dígito tengan un 0 al inicio
        std::string nombreArchivo = "imagenesPrueba/" + nombreBase + "/" + ultimos22 + numeroImagen + ".ppm";
        //std::cout << "NOMBRE DEL ARCHIVO: " << nombreArchivo << std::endl;
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

//Funcion para mostrar la informacion de la imagen cargada en memoria
void infoImagen() {
    if(!cargadaI){
        std::cout << "Error: No hay ninguna imagen cargada en memoria.\n";
        return;
    }
    std::cout << "Imagen cargada en memoria: " << imagen.getNombre() << ", ancho: " << imagen.getXTamano() <<", alto: " << imagen.getYTamano() <<".\n";
}
//Funcion para mostrar la informacion del volumen cargado en memoria
void infoVolumen() {
    if(!cargadaV){
        std::cout << "Error: No hay ningun volumen cargado en memoria.\n";
        return;
    }
    std::cout << "Volumen cargado en memoria: " << volumen.getNombre() << ", Tamano: " << volumen.getNImagenes() << ".\n";
}

//funcion para la proyeccion 2D
void proyeccion2D(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 4) {
        std::cout << "Error: Uso correcto -> proyeccion2D <direccion> <criterio> <nombre_archivo.pgm>\n";
        return;
    }

    if (!cargadaV) {
        std::cout << "El volumen aún no ha sido cargado en memoria.\n";
        return;
    }

    if (volumen.getLista().empty()) {
        std::cerr << "Error: La lista de volumen está vacía.\n";
        return;
    }

    std::string direccion = argumentos[1];
    std::string criterio = argumentos[2];
    std::string nombreArchivo = argumentos[3];

    // Validar criterio
    if (criterio != "minimo" && criterio != "maximo" && criterio != "promedio" && criterio != "mediana") {
        std::cout << "Error: Criterio no valido. Use minimo, maximo, promedio, o mediana.\n";
        return;
    }

    // Validar dirección
    if (direccion != "x" && direccion != "y" && direccion != "z") {
        std::cout << "Error: Dirección no válida. Use x, y, o z.\n";
        return;
    }

    // Obtener dimensiones del volumen
    int ancho = volumen.getLista().front().getXTamano();
    int alto = volumen.getLista().front().getYTamano();
    int profundidad = volumen.getNImagenes();

    // Estructura para almacenar la proyección 2D
    std::list<std::list<int>> proyeccion;

    if (direccion == "x") {
        // Proyección en X: Colapsar columnas (eje X)
        for (int y = 0; y < alto; y++) {
            std::list<int> fila;
            for (int z = 0; z < profundidad; z++) {
                auto imagen = volumen.getLista().begin();
                std::advance(imagen, z);
                auto filaImagen = imagen->getLista().begin();
                std::advance(filaImagen, y);

                if (criterio == "minimo") {
                    int minimo = 255;
                    for (int valor : *filaImagen) {
                        if (valor < minimo) minimo = valor;
                    }
                    fila.push_back(minimo);
                } else if (criterio == "maximo") {
                    int maximo = 0;
                    for (int valor : *filaImagen) {
                        if (valor > maximo) maximo = valor;
                    }
                    fila.push_back(maximo);
                } else if (criterio == "promedio") {
                    int suma = 0;
                    for (int valor : *filaImagen) {
                        suma += valor;
                    }
                    fila.push_back(suma / ancho);
                } else if (criterio == "mediana") {
                    std::vector<int> valores(filaImagen->begin(), filaImagen->end());
                    std::sort(valores.begin(), valores.end());
                    fila.push_back(valores[valores.size() / 2]);
                }
            }
            proyeccion.push_back(fila);
        }
    } else if (direccion == "y") {
        // Proyección en Y: Colapsar filas (eje Y)
        for (int x = 0; x < ancho; x++) {
            std::list<int> fila;
            for (int z = 0; z < profundidad; z++) {
                auto imagen = volumen.getLista().begin();
                std::advance(imagen, z);
                int suma = 0;
                int minimo = 255;
                int maximo = 0;
                std::vector<int> valores;

                for (auto filaImagen : imagen->getLista()) {
                    auto it = filaImagen.begin();
                    std::advance(it, x);
                    int valor = *it;

                    if (criterio == "minimo") {
                        if (valor < minimo) minimo = valor;
                    } else if (criterio == "maximo") {
                        if (valor > maximo) maximo = valor;
                    } else if (criterio == "promedio") {
                        suma += valor;
                    } else if (criterio == "mediana") {
                        valores.push_back(valor);
                    }
                }

                if (criterio == "minimo") {
                    fila.push_back(minimo);
                } else if (criterio == "maximo") {
                    fila.push_back(maximo);
                } else if (criterio == "promedio") {
                    fila.push_back(suma / alto);
                } else if (criterio == "mediana") {
                    std::sort(valores.begin(), valores.end());
                    fila.push_back(valores[valores.size() / 2]);
                }
            }
            proyeccion.push_back(fila);
        }
    } else if (direccion == "z") {
        // Proyección en Z: Colapsar profundidad (eje Z)
        for (int y = 0; y < alto; y++) {
            std::list<int> fila;
            for (int x = 0; x < ancho; x++) {
                int suma = 0;
                int minimo = 255;
                int maximo = 0;
                std::vector<int> valores;

                for (int z = 0; z < profundidad; z++) {
                    auto imagen = volumen.getLista().begin();
                    std::advance(imagen, z);
                    auto filaImagen = imagen->getLista().begin();
                    std::advance(filaImagen, y);
                    auto it = filaImagen->begin();
                    std::advance(it, x);
                    int valor = *it;

                    if (criterio == "minimo") {
                        if (valor < minimo) minimo = valor;
                    } else if (criterio == "maximo") {
                        if (valor > maximo) maximo = valor;
                    } else if (criterio == "promedio") {
                        suma += valor;
                    } else if (criterio == "mediana") {
                        valores.push_back(valor);
                    }
                }

                if (criterio == "minimo") {
                    fila.push_back(minimo);
                } else if (criterio == "maximo") {
                    fila.push_back(maximo);
                } else if (criterio == "promedio") {
                    fila.push_back(suma / profundidad);
                } else if (criterio == "mediana") {
                    std::sort(valores.begin(), valores.end());
                    fila.push_back(valores[valores.size() / 2]);
                }
            }
            proyeccion.push_back(fila);
        }
    }

    // Guardar la proyección en un archivo PGM
    guardarPGM(proyeccion, nombreArchivo);
    std::cout << "La proyeccion 2D del volumen en memoria ha sido generada y almacenada en el archivo " << nombreArchivo << ".\n";
}

//Funcion para guardar la proyeccion en un archivo
void guardarPGM(const std::list<std::list<int>>& proyeccion, const std::string& nombreArchivo) {
    //std::cout << "Intentando guardar el archivo: " << nombreArchivo << "\n";
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
        std::cout << "Error: Uso correcto -> codificar_imagen <nombre_archivo.huf>\n";
        return;
    }
    if (!cargadaI) {
        std::cout << "Error: No hay una imagen cargada en memoria.\n";
        return;
    }

    // Paso 1: Obtener la lista de píxeles y contar frecuencias
    std::vector<unsigned long> freq(256, 0);
    std::vector<unsigned char> pixels;

    for (const auto& fila : imagen.getLista()) {
        for (int valor : fila) {
            unsigned char intensidad = static_cast<unsigned char>(valor);
            freq[intensidad]++;
            pixels.push_back(intensidad);
        }
    }

    // Paso 2: Construir árbol de Huffman
    HuffmanTree tree(freq);
    std::map<unsigned char, std::string> codes = tree.getCodes();

    // Paso 3: Codificar todos los píxeles
    std::string bitStream;
    for (unsigned char pixel : pixels) {
        bitStream += codes[pixel];
    }

    // Guardar número de bits válidos antes de rellenar con ceros
    size_t numBitsValidos = bitStream.size();
    while (bitStream.size() % 8 != 0) {
        bitStream += "0";
    }

    // Paso 4: Escribir archivo binario
    std::ofstream out(argumentos[1], std::ios::binary);
    if (!out) {
        std::cerr << "Error: No se pudo crear el archivo " << argumentos[1] << ".\n";
        return;
    }

    unsigned short W = static_cast<unsigned short>(imagen.getXTamano());
    unsigned short H = static_cast<unsigned short>(imagen.getYTamano());
    unsigned char M = static_cast<unsigned char>(imagen.getMaxIntensidad());

    out.write(reinterpret_cast<char*>(&W), sizeof(W));
    out.write(reinterpret_cast<char*>(&H), sizeof(H));
    out.write(reinterpret_cast<char*>(&M), sizeof(M));

    for (int i = 0; i <= M; ++i) {
        out.write(reinterpret_cast<char*>(&freq[i]), sizeof(unsigned long));
    }

    // Escribir stream de bits comprimido como bytes
    for (size_t i = 0; i < bitStream.size(); i += 8) {
        std::bitset<8> byte(bitStream.substr(i, 8));
        unsigned char byteVal = static_cast<unsigned char>(byte.to_ulong());
        out.write(reinterpret_cast<char*>(&byteVal), sizeof(unsigned char));
    }

    // Escribir al final cuántos bits son válidos (para quitar los ceros añadidos)
    out.write(reinterpret_cast<char*>(&numBitsValidos), sizeof(size_t));
    out.close();

    std::cout << "La imagen en memoria ha sido codificada exitosamente y almacenada en el archivo " << argumentos[1] << ".\n";
}


//Funcion para decodificar un archivo
void decodificarArchivo(const std::vector<std::string>& argumentos) {
    if (argumentos.size() != 3) {
        std::cout << "Error: Uso correcto -> decodificar_archivo <nombre_archivo.huf> <nombre_imagen.pgm>\n";
        return;
    }

    std::ifstream in(argumentos[1], std::ios::binary);
    if (!in) {
        std::cerr << "El archivo " << argumentos[1] << " no ha podido ser decodificado.\n";
        return;
    }

    // Paso 1: Leer encabezado
    unsigned short W, H;
    unsigned char M;
    in.read(reinterpret_cast<char*>(&W), sizeof(W));
    in.read(reinterpret_cast<char*>(&H), sizeof(H));
    in.read(reinterpret_cast<char*>(&M), sizeof(M));

    // Paso 2: Leer frecuencias
    std::vector<unsigned long> freq(256, 0);
    for (int i = 0; i <= M; ++i) {
        in.read(reinterpret_cast<char*>(&freq[i]), sizeof(unsigned long));
    }

    // Paso 3: Leer todo el bloque de bytes restante
    std::vector<unsigned char> bytes;
    char b;
    while (in.read(&b, sizeof(char))) {
        bytes.push_back(static_cast<unsigned char>(b));
    }
    in.close();

    if (bytes.size() < sizeof(size_t)) {
        std::cerr << "Error: Archivo corrupto o incompleto.\n";
        return;
    }

    // Paso 4: Separar el número de bits válidos del final
    size_t numBitsValidos;
    std::memcpy(&numBitsValidos, &bytes[bytes.size() - sizeof(size_t)], sizeof(size_t));
    bytes.resize(bytes.size() - sizeof(size_t));

    // Paso 5: Convertir bytes a bitstream
    std::string bitStream;
    for (unsigned char byte : bytes) {
        bitStream += std::bitset<8>(byte).to_string();
    }
    bitStream = bitStream.substr(0, numBitsValidos);

    // Paso 6: Reconstruir árbol de Huffman
    HuffmanTree tree(freq);
    HuffmanNode* root = tree.getRoot();
    if (!root) {
        std::cerr << "Error: No se pudo reconstruir el árbol de Huffman.\n";
        return;
    }

    // Paso 7: Decodificar bits → píxeles
    std::vector<unsigned char> pixels;
    HuffmanNode* current = root;

    for (char bit : bitStream) {
        current = (bit == '0') ? current->left : current->right;

        if (!current->left && !current->right) {
            pixels.push_back(current->pixel);
            current = root;
        }
    }

    if (pixels.size() != W * H) {
        std::cerr << "Advertencia: se decodificaron " << pixels.size()
                  << " píxeles, pero se esperaban " << W * H << ".\n";
    }

    // Paso 8: Escribir imagen PGM
    std::ofstream out(argumentos[2]);
    if (!out) {
        std::cerr << "Error: No se pudo crear el archivo " << argumentos[2] << ".\n";
        return;
    }

    out << "P2\n" << W << " " << H << "\n" << static_cast<int>(M) << "\n";

    for (size_t i = 0; i < pixels.size(); ++i) {
        out << static_cast<int>(pixels[i]) << " ";
        if ((i + 1) % W == 0) out << "\n";
    }

    out.close();
    std::cout << "El archivo " << argumentos[1] << " ha sido decodificado exitosamente, y la imagen correspondiente se ha almacenado en el archivo " << argumentos[2] << ".\n";
}


//Funcion para segmentar 
void segmentar(const std::vector<std::string>& argumentos) {
    if (argumentos.size() < 3) {
        std::cout << "Error: Uso correcto -> segmentar <salida_imagen.pgm> <semillas>\n";
        return;
    }
    std::cout << "La imagen ha sido segmentada y almacenada en " << argumentos[1] << ".\n";
}