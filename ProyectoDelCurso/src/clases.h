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

//Clase Imagen
class Imagen {
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
        std::string getNombre() const;  // Método constante
        std::string getCodigo() const;  // Método constante
        int getXTamano() const;         // Método constante
        int getYTamano() const;         // Método constante
        int getMaxIntensidad() const;   // Método constante
        const std::list<std::list<int>>& getLista() const;  // Método constante
    };

//Clase Volumen
class Volumen{
    private:
        std::string nombre;
        int nImagenes;
        std::list<Imagen> lista;
    public:
        ~Volumen();
        void setNombre(std::string nombre);
        void setNImagenes(int nImagenes);
        void setLista(std::list<Imagen> lista);
        std::string getNombre();
        int getNImagenes();
        const std::list<Imagen>& getLista() const;
};



#endif