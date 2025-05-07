#include <iostream>
#include <list>
#include <algorithm> // para usar find
#include <cstring>   // para memset

using namespace std;

// Clase que representa un grafo no dirigido
class Grafo {
    int V;              // Número de vértices
    list<int>* adj;     // Lista de adyacencia para representar el grafo

public:
    Grafo(int V) {
        this->V = V;
        adj = new list<int>[V]; // Crear arreglo de listas
    }

    ~Grafo() {
        delete[] adj; // Liberar memoria
    }

    void agregarEdge(int u, int v);      // Agrega una arista entre u y v
    void borrarEdge(int u, int v);       // "Elimina" una arista marcándola como -1
    void EulerGrafo();                   // Función principal para imprimir el camino Euleriano
    void impEulerGrafo(int u);           // Función recursiva para construir el camino
    bool isValidNextEdge(int u, int v);  // Verifica si la arista u-v es válida para recorrer
    int DFSCount(int v, bool visited[]); // Cuenta los vértices alcanzables desde v usando DFS
};

// Función para agregar una arista en ambas direcciones (grafo no dirigido)
void Grafo::agregarEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Función principal que inicia el recorrido del camino Euleriano
void Grafo::EulerGrafo() {
    int u = 0;

    // Buscar un vértice con grado impar (si existe), para comenzar desde ahí
    for (int i = 0; i < V; i++) {
        if (adj[i].size() & 1) { // si el número de aristas es impar
            u = i;
            break;
        }
    }

    // Inicia el recorrido desde el vértice encontrado
    impEulerGrafo(u);
    cout << endl;
}

// Función recursiva que imprime el recorrido del camino Euleriano
void Grafo::impEulerGrafo(int u) {
    list<int>::iterator i;

    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;
        // Si la arista aún existe y es válida, se recorre
        if (v != -1 && isValidNextEdge(u, v)) {
            cout << u << " - " << v << "  ";
            borrarEdge(u, v);       // Marcar la arista como eliminada
            impEulerGrafo(v);       // Llamada recursiva desde el nuevo vértice
            break; // salir porque la lista se modificó
        }
    }
}

// Verifica si se puede tomar la arista u-v como parte del camino
bool Grafo::isValidNextEdge(int u, int v) {
    int count = 0;
    list<int>::iterator i;

    // Contar cuántas aristas quedan sin eliminar desde u
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
        if (*i != -1)
            count++;

    // Si solo queda una arista, no hay otra opción, se debe tomar
    if (count == 1)
        return true;

    // Si hay más de una opción, hacemos una verificación extra
    bool visited[V];
    memset(visited, false, V);
    int count1 = DFSCount(u, visited); // Conteo antes de eliminar la arista

    borrarEdge(u, v); // Eliminar temporalmente la arista

    memset(visited, false, V);
    int count2 = DFSCount(u, visited); // Conteo después de eliminar la arista

    agregarEdge(u, v); // Restaurar la arista

    // Si el grafo se vuelve menos conectado, no es una arista válida
    return count1 <= count2;
}

// Marca la arista u-v como eliminada cambiando su valor a -1
void Grafo::borrarEdge(int u, int v) {
    list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
    if (iv != adj[u].end()) *iv = -1;

    list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
    if (iu != adj[v].end()) *iu = -1;
}

// Algoritmo DFS (búsqueda en profundidad) para contar los nodos alcanzables
int Grafo::DFSCount(int v, bool visited[]) {
    visited[v] = true;
    int count = 1;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (*i != -1 && !visited[*i])
            count += DFSCount(*i, visited); // Visitar recursivamente los vecinos

    return count;
}

// Función principal para probar el grafo
int main() {
    Grafo g(5);

    // Agregamos algunas aristas al grafo
    g.agregarEdge(0, 1);
    g.agregarEdge(0, 2);
    g.agregarEdge(1, 2);
    g.agregarEdge(2, 3);
    g.agregarEdge(3, 4);
    g.agregarEdge(4, 2);

    // Mostrar el camino Euleriano
    cout << "Camino Euleriano:\n";
    g.EulerGrafo();

    return 0;
}
