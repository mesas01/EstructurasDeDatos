/************************************************
 * PROYECTO 1
 * FECHA: 01-03-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: CLASES.H
 ***********************************************/
#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <list>
class Imagen{
    private:
        std::string nombre;
        std::string codigo;
        int xTamano;
        int yTamano;
        int maxIntensidad;
        std::list<std::list<int>> lista;
    public:
        ~Imagen();
        void setNombre(std::string nombre);
        void setCodigo(std::string codigo);
        void setXTamano(int xTamano);
        void setYTamano(int yTamano);
        void setMaxIntensidad(int maxIntensidad);
        void setLista(std::list<std::list<int>> lista);
        std::string getNombre();
        std::string getCodigo();
        int getXTamano();
        int getYTamano();
        int getMaxIntensidad();
        std::list<std::list<int>> getLista();
};



#endif