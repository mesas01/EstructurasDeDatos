#include <iostream>             // Entrada y salida estándar
#include <string>               // Manejo de cadenas
#include <vector>               // Uso de vectores (listas dinámicas)
#include "Articulo.h"           // Definición de la clase Articulo
#include "MapaDeCitaciones.h"  // Definición del grafo de artículos y citaciones
#include "cargar_archivo.h"    // Función para cargar artículos desde archivo

// Declaración anticipada de las funciones correspondientes a cada algoritmo
void ejecutarAlgoritmo1(MapaDeCitaciones& mapa);  // Artículo más citado
void ejecutarAlgoritmo2(MapaDeCitaciones& mapa);  // Componentes conectados tras eliminar un artículo
void ejecutarAlgoritmo3(MapaDeCitaciones& mapa);  // Índice de referenciación
void ejecutarAlgoritmo4(MapaDeCitaciones& mapa);  // Citaciones indirectas

using namespace std;  // Para evitar usar std:: en cada línea

// Función que muestra el menú principal del sistema
void mostrarMenu() {
    cout << "\n====== MENU - Sistema de Citaciones ======" << endl;
    cout << "1. Agregar articulo" << endl;
    cout << "2. Agregar citacion (de un articulo a otro)" << endl;
    cout << "3. Mostrar articulo mas citado (Algoritmo 1)" << endl;
    cout << "4. Contar grupos tras eliminar articulo (Algoritmo 2)" << endl;
    cout << "5. Calcular indice de referenciacion (Algoritmo 3)" << endl;
    cout << "6. Contar citaciones indirectas (Algoritmo 4)" << endl;
    cout << "7. Cargar datos desde archivo (mapa_ejemplo.txt)" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Función principal del programa
int main() {
    MapaDeCitaciones mapa;  // Se crea el grafo de citaciones
    int opcion;              // Variable para controlar la opción seleccionada

    do {
        mostrarMenu();       // Se muestra el menú al usuario
        cin >> opcion;       // Se recibe la opción
        cin.ignore();        // Limpia el buffer del enter

        switch (opcion) {
            case 1: {
                // Agregar un nuevo artículo manualmente
                string id, titulo, revista, volumen;
                int año, numAutores;
                vector<string> autores;

                cout << "ID del articulo: ";
                getline(cin, id);
                cout << "Titulo: ";
                getline(cin, titulo);
                cout << "Revista: ";
                getline(cin, revista);
                cout << "Volumen: ";
                getline(cin, volumen);
                cout << "Año: ";
                cin >> año;
                cin.ignore();

                cout << "Numero de autores: ";
                cin >> numAutores;
                cin.ignore();

                // Se solicitan los nombres de los autores
                for (int i = 0; i < numAutores; ++i) {
                    string autor;
                    cout << "Autor " << i + 1 << ": ";
                    getline(cin, autor);
                    autores.push_back(autor);
                }

                // Se construye y agrega el artículo al mapa
                Articulo nuevo(id, titulo, autores, revista, volumen, año);
                mapa.agregarArticulo(nuevo);
                cout << "Articulo agregado con exito." << endl;
                break;
            }

            case 2: {
                // Agregar una citación entre dos artículos existentes
                string origen, destino;
                cout << "ID del articulo que cita (origen): ";
                getline(cin, origen);
                cout << "ID del articulo citado (destino): ";
                getline(cin, destino);
                mapa.agregarCita(origen, destino);
                cout << "Citacion agregada." << endl;
                break;
            }

            // Ejecuta el algoritmo 1: artículo más citado
            case 3:
                ejecutarAlgoritmo1(mapa);
                break;

            // Ejecuta el algoritmo 2: contar componentes tras eliminar artículo
            case 4:
                ejecutarAlgoritmo2(mapa);
                break;

            // Ejecuta el algoritmo 3: índice de referenciación
            case 5:
                ejecutarAlgoritmo3(mapa);
                break;

            // Ejecuta el algoritmo 4: citaciones indirectas
            case 6:
                ejecutarAlgoritmo4(mapa);
                break;

            // Cargar artículos y citaciones desde archivo
            case 7: {
                string ruta = "datos/mapa_ejemplo.txt";
                cargarDesdeArchivo(mapa, ruta);
                cout << "\n\nArchivo cargado exitosamente desde '" << ruta << "'." << endl;
                break;
            }

            // Salir del sistema
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            // Validación de opción incorrecta
            default:
                cout << "Opción invalida. Intente nuevamente." << endl;
        }

    } while (opcion != 0);  // Se repite mientras no se seleccione salir

    return 0;  // Fin del programa
}
