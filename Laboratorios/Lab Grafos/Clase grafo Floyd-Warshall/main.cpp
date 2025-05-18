#include <bits/stdc++.h>
using namespace std;

// Función que implementa el algoritmo de Floyd-Warshall
void floyds(vector<vector<int>> &b)
{
    int i, j, k;
    // Itera sobre todos los nodos intermedios
    for (k = 0; k < b.size(); k++)
    {
        // Itera sobre todos los pares de nodos (i, j)
        for (i = 0; i < b.size(); i++)
        {
            for (j = 0; j < b.size(); j++)
            {
                // Si existe un camino a través del nodo intermedio k
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    // Actualiza el costo si encuentra un camino más corto
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }

    // Imprime la matriz de costos mínimos
    for (i = 0; i < b.size(); i++)
    {
        cout << "Minimum Cost With Respect to Node:" << i << endl;
        for (j = 0; j < b.size(); j++)
        {
            cout << b[i][j] << "\t";
        }
    }
}

int main()
{
    int numeroVertices = 0;
    // Solicita al usuario el número de vértices
    cout << "Con cuantos vertices desea trabajar?" << endl;
    cin >> numeroVertices;

    // Inicializa la matriz de adyacencia con valores grandes (infinito)
    vector<vector<int>> b(numeroVertices, vector<int>(numeroVertices));
    for (int i = 0; i < numeroVertices; i++)
    {
        for (int j = 0; j < numeroVertices; j++)
        {
            b[i][j] = 1e9; // Representa infinito
        }
    }

    int opc = -1;
    // Ciclo para permitir al usuario agregar aristas
    while (opc != 0)
    {
        cout << "Si desea salir ingrese 0, si desea agregar una arista ingrese 1" << endl;
        cin >> opc;
        if (opc == 1)
        {
            int origen, destino, costo;
            // Solicita los datos de la arista
            cout << "Ingrese el nodo de origen" << endl;
            cin >> origen;
            cout << "Ingrese el nodo de destino" << endl;
            cin >> destino;
            cout << "Ingrese el costo de la arista" << endl;
            cin >> costo;
            b[origen][destino] = costo; // Actualiza la matriz con el costo de la arista
        }
    }

    // Llama a la función de Floyd-Warshall para calcular los caminos más cortos
    floyds(b);
    return 0;
}