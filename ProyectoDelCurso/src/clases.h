/************************************************
 * PROYECTO 1
 * FECHA: 01-03-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: CLASES.H
 * 
 * Descripción: Definición de las clases Imagen y Volumen, 
 * utilizadas para representar imágenes individuales y 
 * conjuntos de imágenes organizadas en volúmenes 3D.
 ***********************************************/

 #ifndef CLASES_H
 #define CLASES_H
 
 #include <iostream>
 #include <list>
 #include <vector>
 #include <queue>
 #include <map>
 #include <bitset>

 
 using namespace std;
 
 /**
  * Clase Imagen
  * Representa una imagen en escala de grises almacenada en una estructura de listas anidadas.
  */
 class Imagen {
     private:
         std::string nombre;  // Nombre del archivo de la imagen
         std::string codigo;  // Código del formato de la imagen (ej. "P2" para PGM)
         int xTamano;         // Ancho de la imagen en píxeles
         int yTamano;         // Alto de la imagen en píxeles
         int maxIntensidad;   // Valor máximo de intensidad de los píxeles (0-255)
         std::list<std::list<int>> lista; // Matriz de píxeles almacenada como listas de listas
     
     public:
         ~Imagen();  // Destructor para limpiar memoria
         
         // Métodos setters
         void setNombre(std::string nombre);
         void setCodigo(std::string codigo);
         void setXTamano(int xTamano);
         void setYTamano(int yTamano);
         void setMaxIntensidad(int maxIntensidad);
         void setLista(std::list<std::list<int>> lista);
         
         // Métodos getters
         std::string getNombre() const;  // Devuelve el nombre del archivo
         std::string getCodigo() const;  // Devuelve el código del formato de la imagen
         int getXTamano() const;         // Devuelve el ancho de la imagen en píxeles
         int getYTamano() const;         // Devuelve el alto de la imagen en píxeles
         int getMaxIntensidad() const;   // Devuelve el valor máximo de intensidad de los píxeles
         const std::list<std::list<int>>& getLista() const;  // Devuelve la matriz de píxeles
 };
 
 /**
  * Clase Volumen
  * Representa un conjunto ordenado de imágenes que conforman un volumen 3D.
  */
 class Volumen{
     private:
         std::string nombre;  // Nombre base del volumen (sin extensión)
         int nImagenes;       // Número de imágenes en el volumen
         std::list<Imagen> lista; // Lista de imágenes que componen el volumen
     
     public:
         ~Volumen();  // Destructor para limpiar memoria
         
         // Métodos setters
         void setNombre(std::string nombre);
         void setNImagenes(int nImagenes);
         void setLista(std::list<Imagen> lista);
         
         // Métodos getters
         std::string getNombre();  // Devuelve el nombre base del volumen
         int getNImagenes();       // Devuelve la cantidad de imágenes en el volumen
         const std::list<Imagen>& getLista() const;  // Devuelve la lista de imágenes
 };

 //Estructura nodo de Huffman
 struct HuffmanNode {
    unsigned char pixel;
    unsigned long freq;
    HuffmanNode *left, *right;
    HuffmanNode(unsigned char p, unsigned long f);
};

//Estructura para comparar nodos de Huffman
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b);
};

//Clase árbol de Huffman
class HuffmanTree {
private:
    //Raiz
    HuffmanNode* root;
    //Mapa para almacenar los códigos de Huffman
    map<unsigned char, string> huffmanCodes;
    //Función para la construcción de los códigos de cada pixel
    void buildCodes(HuffmanNode* node, string code);

public:
    //Constructor
    HuffmanTree(const vector<unsigned long>& freq);
    //Getters
    map<unsigned char, string> getCodes();
    HuffmanNode* getRoot();
};
 
 #endif
 