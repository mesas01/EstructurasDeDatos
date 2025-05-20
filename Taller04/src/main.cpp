#include <iostream>
#include <string>
#include <vector>
#include "Articulo.h"
#include "MapaDeCitaciones.h"

using namespace std;

void mostrarMenu() {
    cout << "\n====== MENU - Sistema de Citaciones ======" << endl;
    cout << "1. Agregar articulo" << endl;
    cout << "2. Agregar citacion (de un articulo a otro)" << endl;
    cout << "3. Mostrar articulo más citado (Algoritmo 1)" << endl;
    cout << "4. Contar grupos tras eliminar artículo (Algoritmo 2)" << endl;
    cout << "5. Calcular indice de referenciacion (Algoritmo 3)" << endl;
    cout << "6. Contar citaciones indirectas (Algoritmo 4)" << endl;
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

                cout << "ID del artículo: ";
                getline(cin, id);
                cout << "Título: ";
                getline(cin, titulo);
                cout << "Revista: ";
                getline(cin, revista);
                cout << "Volumen: ";
                getline(cin, volumen);
                cout << "Año: ";
                cin >> año;
                cin.ignore();

                cout << "Número de autores: ";
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
                cout << "Artículo agregado con éxito." << endl;
                break;
            }

            case 2: {
                string origen, destino;
                cout << "ID del artículo que cita (origen): ";
                getline(cin, origen);
                cout << "ID del artículo citado (destino): ";
                getline(cin, destino);
                mapa.agregarCita(origen, destino);
                cout << "Citación agregada." << endl;
                break;
            }

            case 3: {
                string id = mapa.articuloMasCitado();
                if (!id.empty()) {
                    cout << "El artículo más citado es: " << id << endl;
                } else {
                    cout << "No hay artículos citados aún." << endl;
                }
                break;
            }

            case 4: {
                string id;
                cout << "ID del artículo a eliminar: ";
                getline(cin, id);
                int grupos = mapa.contarGruposTrasEliminar(id);
                cout << "Grupos resultantes tras eliminar: " << grupos << endl;
                break;
            }

            case 5: {
                string id;
                cout << "ID del artículo para índice de referenciación: ";
                getline(cin, id);
                double indice = mapa.calcularIndiceReferenciacion(id);
                cout << "Índice de referenciación: " << indice << endl;
                break;
            }

            case 6: {
                string id;
                cout << "ID del artículo para citaciones indirectas: ";
                getline(cin, id);
                int cantidad = mapa.contarCitacionesIndirectas(id);
                cout << "Cantidad de citaciones indirectas: " << cantidad << endl;
                break;
            }

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }

    } while (opcion != 0);

    return 0;
}
