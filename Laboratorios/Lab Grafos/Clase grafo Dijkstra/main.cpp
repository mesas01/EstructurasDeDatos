#include <bits/stdc++.h> // Incluye todas las bibliotecas estándar de C++
using namespace std;

// Función para encontrar el vértice con la distancia mínima que aún no está incluido en el conjunto de caminos más cortos
int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX; // Inicializa el valor mínimo como infinito
    int min_index;     // Índice del vértice con la distancia mínima

    // Recorre todos los vértices para encontrar el de menor distancia
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min) // Si el vértice no está en el conjunto y su distancia es menor
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index; // Devuelve el índice del vértice con la distancia mínima
}

// Función para imprimir la solución: las distancias desde el vértice fuente a todos los demás
void printSolucion(int dist[], int V)
{
    cout << "Vertice\t Distancia desde la Fuente" << endl;
    for (int i = 0; i < V; i++) // Recorre todos los vértices
    {
        cout << i << "\t\t\t" << dist[i] << endl; // Imprime el vértice y su distancia desde la fuente
    }
}

// Implementación del algoritmo de Dijkstra
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    int dist[V];    // Arreglo para almacenar las distancias mínimas desde la fuente
    bool sptSet[V]; // Arreglo para rastrear los vértices incluidos en el conjunto de caminos más cortos

    // Inicializa todas las distancias como infinito y el conjunto de caminos más cortos como falso
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0; // La distancia desde la fuente a sí misma es 0

    // Encuentra el camino más corto para todos los vértices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V); // Selecciona el vértice con la distancia mínima
        sptSet[u] = true;                    // Marca el vértice como procesado

        // Actualiza las distancias de los vértices adyacentes al vértice seleccionado
        for (int v = 0; v < V; v++)
        {
            // Actualiza dist[v] si no está en el conjunto, hay un borde desde u a v, y el nuevo camino es más corto
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
        printSolucion(dist, V); // Imprime las distancias actuales después de cada iteración
    }
}

int main()
{
    // Representación de un grafo como una matriz de adyacencia
    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                 {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                 {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                 {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    int V = 9; // Número de vértices en el grafo

    dijkstra(graph, 0, V); // Llama al algoritmo de Dijkstra con el vértice fuente 0
}