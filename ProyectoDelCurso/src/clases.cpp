/************************************************
 * PROYECTO 1
 * FECHA: 01-03-2025
 * MATERIA: ESTRUCTURAS DE DATOS
 * AUTORES: SANTIAGO MESA Y JERONIMO CHAPARRO
 * ARCHIVO: CLASES.CPP
 * 
 * Descripción: Implementación de las clases Imagen y Volumen,
 * que representan imágenes individuales y volúmenes 3D respectivamente.
 ***********************************************/

#include "clases.h"

// Destructor de la clase Imagen
// Libera la memoria utilizada por la lista de píxeles.
Imagen::~Imagen() {
    lista.clear();
}

// Métodos setters para la clase Imagen
// Asigna el nombre de la imagen
void Imagen::setNombre(std::string nombre) {
    this->nombre = nombre;
}

// Asigna el código de la imagen (e.g., "P2" para PGM)
void Imagen::setCodigo(std::string codigo) {
    this->codigo = codigo;
}

// Asigna el tamaño en el eje X (ancho de la imagen)
void Imagen::setXTamano(int xTamano) {
    this->xTamano = xTamano;
}

// Asigna el tamaño en el eje Y (alto de la imagen)
void Imagen::setYTamano(int yTamano) {
    this->yTamano = yTamano;
}

// Asigna la intensidad máxima de los píxeles
void Imagen::setMaxIntensidad(int maxIntensidad) {
    this->maxIntensidad = maxIntensidad;
}

// Asigna la lista de píxeles de la imagen
void Imagen::setLista(std::list<std::list<int>> lista) {
    this->lista = lista;
}

// Métodos getters para la clase Imagen
// Obtiene el nombre de la imagen
std::string Imagen::getNombre() const {
    return nombre;
}

// Obtiene el código de la imagen
std::string Imagen::getCodigo() const {
    return codigo;
}

// Obtiene el tamaño en el eje X (ancho)
int Imagen::getXTamano() const {
    return xTamano;
}

// Obtiene el tamaño en el eje Y (alto)
int Imagen::getYTamano() const {
    return yTamano;
}

// Obtiene la intensidad máxima de los píxeles
int Imagen::getMaxIntensidad() const {
    return maxIntensidad;
}

// Obtiene la lista de píxeles de la imagen
const std::list<std::list<int>>& Imagen::getLista() const {
    return lista;
}

// Destructor de la clase Volumen
// Libera la memoria utilizada por la lista de imágenes.
Volumen::~Volumen() {
    lista.clear();
}

// Métodos setters para la clase Volumen
// Asigna el nombre del volumen
void Volumen::setNombre(std::string nombre) {
    this->nombre = nombre;
}

// Asigna el número de imágenes en el volumen
void Volumen::setNImagenes(int nImagenes) {
    this->nImagenes = nImagenes;
}

// Asigna la lista de imágenes que componen el volumen
void Volumen::setLista(std::list<Imagen> lista) {
    this->lista = lista;
}

// Métodos getters para la clase Volumen
// Obtiene el nombre del volumen
std::string Volumen::getNombre() {
    return nombre;
}

// Obtiene el número de imágenes en el volumen
int Volumen::getNImagenes() {
    return nImagenes;
}

// Obtiene la lista de imágenes que componen el volumen
const std::list<Imagen>& Volumen::getLista() const {
    return lista;
}

// Constructor de la clase HuffmanNode
// Inicializa un nodo del árbol de Huffman con un píxel y su frecuencia
HuffmanNode::HuffmanNode(unsigned char p, unsigned long f) : pixel(p), freq(f), left(nullptr), right(nullptr) {}

// Comparador para la cola de prioridad utilizada en el árbol de Huffman
bool Compare::operator()(HuffmanNode* a, HuffmanNode* b) {
    return a->freq > b->freq; // Ordena por frecuencia ascendente
}

// Constructor de la clase HuffmanTree
// Construye el árbol de Huffman a partir de un vector de frecuencias
HuffmanTree::HuffmanTree(const vector<unsigned long>& freq) {
    // Cola de prioridad para construir el árbol
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Crear un nodo para cada píxel con frecuencia mayor a 0
    for (size_t i = 0; i < freq.size(); i++) {
        if (freq[i] > 0)
            pq.push(new HuffmanNode(i, freq[i]));
    }

    // Construir el árbol combinando los nodos con menor frecuencia
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* newNode = new HuffmanNode(0, left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    root = pq.top(); // El último nodo en la cola es la raíz del árbol
    buildCodes(root, ""); // Generar los códigos de Huffman
}

// Método para construir los códigos de Huffman recursivamente
void HuffmanTree::buildCodes(HuffmanNode* node, string code) {
    if (!node) return; // Caso base: nodo nulo
    if (!node->left && !node->right) { // Nodo hoja
        huffmanCodes[node->pixel] = code; // Asignar código al píxel
    }
    buildCodes(node->left, code + "0"); // Recorrer subárbol izquierdo
    buildCodes(node->right, code + "1"); // Recorrer subárbol derecho
}

// Obtiene los códigos de Huffman generados
map<unsigned char, string> HuffmanTree::getCodes() {
    return huffmanCodes;
}

// Obtiene la raíz del árbol de Huffman
HuffmanNode* HuffmanTree::getRoot() {
    return root;
}
