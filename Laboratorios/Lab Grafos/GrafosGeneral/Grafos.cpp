/**************************************************************
 * Universidad: Pontificia Universidad Javeriana
 * Estudiante: Santiago Mesa y Santiago Camargo
 * Docente: John Corredor
 * Curso: Estructuras de Datos
 * Archivo: Grafos.cpp
 * Fecha: 30/04/2025
 * 
 * Descripción:
 * Este programa permite determinar la existencia de un ciclo o
 * camino de Euler y un ciclo o camino Hamiltoniano en un grafo
 * no dirigido. Se usan dos clases: `Euler` y `Hamiltonian` que 
 * aplican algoritmos DFS para verificar dichas propiedades.
 **************************************************************

Ejemplo de entrada para probar el programa:

Número de vértices: 4
Número de aristas: 5
Aristas:
0 1
0 2
1 2
2 3
3 0

Este grafo tiene un ciclo de Euler y un ciclo Hamiltoniano.

Ejemplo de entrada para probar el programa:

Número de vértices: 4
Número de aristas: 5
Aristas:
0 0
0 0
0 0
0 0
0 0

Este grafo no tiene un ciclo de Euler ni un ciclo Hamiltoniano.
*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include <stdio.h>
 
using namespace std;
 
int n; // Número de vértices (variable global)
 
// Clase para manejar grafos y detectar circuitos/caminos de Euler
class Euler {
    int V;                // Número de vértices
    list<int> *adj;       // Lista de adyacencia para representar el grafo
    
    public:
    Euler(int V)  { 
        this->V = V;  
        adj = new list<int>[V];  // Inicializa la lista de adyacencia
    }
    ~Euler() { 
        delete[] adj; // Libera memoria al destruir el objeto
    }
    
    void addEdge(int u, int v);    // Agrega una arista bidireccional entre u y v
    void rmvEdge(int u, int v);    // Elimina una arista marcándola como -1
    void printEulerTour();         // Imprime el recorrido de Euler
    void printEulerUtil(int s);    // DFS para imprimir el recorrido de Euler
    int DFSCount(int v, bool visited[]); // Cuenta los nodos alcanzables desde v
    bool isValidNextEdge(int u, int v);  // Verifica si la arista u-v es válida
    int iseuler(int[]);            // Determina si hay circuito/camino/no Euler
};
 
// Agrega una arista bidireccional entre los vértices u y v
void Euler::addEdge(int u, int v) {
   adj[u].push_back(v);
   adj[v].push_back(u);
}

// Imprime el recorrido de Euler
void Euler::printEulerTour() {
    int u = 0;
    // Encuentra un vértice con grado impar para iniciar el recorrido
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1) { 
            u = i; 
            break; 
        }
    printEulerUtil(u); // Llama al recorrido DFS
    cout << endl;
}

// DFS para imprimir el recorrido de Euler
void Euler::printEulerUtil(int u) {
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;
        // Si la arista es válida, la recorre
        if (v != -1 && isValidNextEdge(u, v)) {
            cout << u << "-" << v << " ";
            rmvEdge(u, v); // Marca la arista como eliminada
            printEulerUtil(v); // Llama recursivamente al siguiente vértice
        }
    }
}

// Verifica si la arista u-v es válida para el recorrido de Euler
bool Euler::isValidNextEdge(int u, int v) {
    int count = 0;
    // Cuenta las aristas disponibles desde u
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        if (*i != -1) count++;
    
    // Si solo hay una arista, es válida
    if (count == 1) return true;
 
    // Realiza un conteo DFS antes y después de eliminar la arista
    bool visited[V];
    memset(visited, false, V);
    int count1 = DFSCount(u, visited);
 
    rmvEdge(u, v); // Elimina temporalmente la arista
    memset(visited, false, V);
    int count2 = DFSCount(u, visited);
    addEdge(u, v); // Restaura la arista
 
    // La arista es válida si no desconecta el grafo
    return (count1 <= count2);
}

// Elimina una arista marcándola como -1
void Euler::rmvEdge(int u, int v) {
    *find(adj[u].begin(), adj[u].end(), v) = -1;
    *find(adj[v].begin(), adj[v].end(), u) = -1;
}

// Realiza un conteo DFS para contar los nodos alcanzables desde v
int Euler::DFSCount(int v, bool visited[]) {
    visited[v] = true;
    int count = 1;
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (*i != -1 && !visited[*i])
            count += DFSCount(*i, visited);
    return count;
}

// Determina si el grafo tiene un circuito o camino de Euler
int Euler::iseuler(int a[]) {
   int count = 0;
   // Cuenta los vértices con grado impar
   for (int i = 0; i < n; i++)
    if (a[i] % 2 != 0) count++;
 
    if (count == 0) {
       cout << "Euler's circuit exists:\n";
       return 1; // Existe un circuito de Euler
    }else if (count == 2) {
        cout << "Euler's path exists:\n";
        return 1; // Existe un camino de Euler
    } else{
            cout << "No Euler's path or circuit exists:\n\n";
            return -1; // No existe ni camino ni circuito de Euler
    }
}

// Clase para detectar caminos/ciclos hamiltonianos
class Hamiltonian {
   int *path, v, x; // `path` almacena el ciclo/camino, `x` indica si es ciclo
public:
   Hamiltonian(int n) { 
       v = 0; 
       x = 0; 
       path = new int[n]; 
   }
   bool isSafe(bool graph[][10], int pos); // Verifica si es seguro agregar un vértice
   bool hamCycleUtil(bool graph[][10], int pos, int i); // Utilidad recursiva para DFS
   bool hamCycle(bool graph[][10]); // Determina si existe un ciclo/camino hamiltoniano
   void printSolution(); // Imprime la solución encontrada
};

// Verifica si es seguro agregar un vértice al camino
bool Hamiltonian::isSafe(bool graph[][10], int pos) {
   if (!graph[path[pos-1]][v]) return false; // Verifica si hay arista
   for (int i = 0; i < pos; i++)
       if (path[i] == v) return false; // Verifica si ya fue visitado
   return true;
}

// DFS para encontrar un ciclo/camino hamiltoniano
bool Hamiltonian::hamCycleUtil(bool graph[][10], int pos, int i) {
   if (pos == n) {
       // Si se visitaron todos los vértices, verifica si es ciclo
       if (graph[path[pos-1]][path[0]]) {
           cout << "Hamiltonian cycle exists\n"; 
           x = 1; // Es un ciclo
       } else {
           cout << "Hamiltonian path exists\n"; // Es un camino
       }
       return true;
   }
 
   for (v = 0; v < n; v++) {
       if (v == i) continue; // Evita el vértice inicial
       if (isSafe(graph, pos)) {
           path[pos] = v; // Agrega el vértice al camino
           if (hamCycleUtil(graph, pos + 1, i))
               return true;
           path[pos] = -1; // Retrocede si no es solución
       }
   }
   return false;
}

// Determina si existe un ciclo/camino hamiltoniano
bool Hamiltonian::hamCycle(bool graph[][10]) {
   for (int i = 0; i < n; i++) path[i] = -1; // Inicializa el camino
 
   for (int i = 0; i < n; i++) {
       path[0] = i; // Comienza desde cada vértice
       if (hamCycleUtil(graph, 1, i)) {
           printSolution(); // Imprime la solución si existe
           return true;
       }
   }
   cout << "\nNo Hamiltonian path or cycle exists";
   return false;
}

// Imprime el ciclo/camino hamiltoniano encontrado
void Hamiltonian::printSolution() {
   for (int i = 0; i < n - 1; i++)
       cout << path[i] << "-" << path[i + 1] << " ";
   if (x == 1)
       cout << path[n - 1] << "-" << path[0]; // Si es ciclo, conecta el último con el primero
   cout << "\n";
}

// Función principal: entrada de datos y ejecución de ejemplo
int main() {
   int i, j, v1, v2, Edges;
   cout << "\nEnter the number of vertices of graph: ";
   cin >> n; // Número de vértices
   Euler g1(n); // Objeto para manejar Euler
   Hamiltonian g2(n); // Objeto para manejar Hamiltoniano
   int a[n] = {0}; // Arreglo para almacenar grados de los vértices
   bool graph1[10][10] = {false}; // Matriz de adyacencia para Hamiltoniano
 
   cout << "\nEnter the total number of edges: ";
   cin >> Edges; // Número de aristas
   for (i = 1; i <= Edges; i++) {
       cout << "\nEnter the edge (u v): ";
       cin >> v1 >> v2; // Lee los extremos de la arista
       graph1[v1][v2] = 1; // Actualiza la matriz de adyacencia
       graph1[v2][v1] = 1;
       g1.addEdge(v1, v2); // Agrega la arista al grafo de Euler
       a[v1]++; // Incrementa el grado de los vértices
       a[v2]++;
   }
 
   cout << "\n";
   g2.hamCycle(graph1); // Verifica ciclo/camino hamiltoniano
   cout << "\n";
   if (g1.iseuler(a) == 1) // Verifica ciclo/camino de Euler
       g1.printEulerTour(); // Imprime el recorrido de Euler
 
   return 0;
}
