#include <iostream>
#include <string>
#include <vector>
#include "Articulo.h"
#include "MapaDeCitaciones.h"
#include "cargar_archivo.h"  


void ejecutarAlgoritmo1(MapaDeCitaciones& mapa);
void ejecutarAlgoritmo2(MapaDeCitaciones& mapa);
void ejecutarAlgoritmo3(MapaDeCitaciones& mapa);
void ejecutarAlgoritmo4(MapaDeCitaciones& mapa);

using namespace std;

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

int main() {
    MapaDeCitaciones mapa;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
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

                for (int i = 0; i < numAutores; ++i) {
                    string autor;
                    cout << "Autor " << i + 1 << ": ";
                    getline(cin, autor);
                    autores.push_back(autor);
                }

                Articulo nuevo(id, titulo, autores, revista, volumen, año);
                mapa.agregarArticulo(nuevo);
                cout << "Articulo agregado con exito." << endl;
                break;
            }

            case 2: {
                string origen, destino;
                cout << "ID del articulo que cita (origen): ";
                getline(cin, origen);
                cout << "ID del articulo citado (destino): ";
                getline(cin, destino);
                mapa.agregarCita(origen, destino);
                cout << "Citacion agregada." << endl;
                break;
            }

            case 3:
                ejecutarAlgoritmo1(mapa);
                break;
            case 4:
                ejecutarAlgoritmo2(mapa);
                break;
            case 5:
                ejecutarAlgoritmo3(mapa);
                break;
            case 6:
                ejecutarAlgoritmo4(mapa);
                break;

            case 7: {
                string ruta = "datos/mapa_ejemplo.txt";
                cargarDesdeArchivo(mapa, ruta);
                cout << "\n\nArchivo cargado exitosamente desde '" << ruta << "'." << endl;
                break;
            }

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción invalida. Intente nuevamente." << endl;
        }

    } while (opcion != 0);

    return 0;
}
