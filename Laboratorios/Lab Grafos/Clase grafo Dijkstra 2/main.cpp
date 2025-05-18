#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
#include <list>
using namespace std;

// iPair ==> Par de enteros
#define iPair pair<int, int>

// Clase para representar un grafo dirigido con lista de adyacencia
class Graph
{
    int V; // Número de vértices
    vector<pair<int, int>> adj; // Lista de adyacencia (vértice, peso)

public:
    Graph(int V); // Constructor
    void addEdge(int u, int v, int w); // Agrega una arista al grafo
    void shortestPath(int s); // Encuentra el camino más corto desde un vértice
};

void Graph::shortestPath(int src)
{
    // Cola de prioridad para procesar vértices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector para almacenar distancias, inicializado con infinito
    vector<int> dist(V, INF);

    // Agrega el vértice fuente a la cola con distancia 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        // Obtiene el vértice con la menor distancia y lo elimina de la cola
        int u = pq.top().second;
        pq.pop();

        // Recorre los vértices adyacentes de u
        for (vector<pair<int, int>>::iterator i = adj.begin(); i != adj.end(); ++i)
        {
            int v = (*i).first;   // Vértice adyacente
            int weight = (*i).second; // Peso de la arista

            // Si se encuentra un camino más corto hacia v
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight; // Actualiza la distancia
                pq.push(make_pair(dist[v], v)); // Agrega v a la cola
            }
        }
    }
}