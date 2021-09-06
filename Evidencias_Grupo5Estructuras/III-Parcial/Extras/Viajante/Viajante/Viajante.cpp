// Viajante.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
//
#include <iostream>
#include<vector>
#include "Respuesta1.h"
#include "Ciudad.h"
using namespace std;
#define V 20
vector<int> sol;

void tsp(int graph[][V], vector<bool>& v, vector<Respuesta>& resp, int currPos, int n, int count, int cost, int& ans)
{
    Respuesta res;
    res.set_res(sol);
     /*If last node is reached and it has a link
     to the starting node i.e the source then
     keep the minimum value out of the total cost
     of traversal and "ans"
     Finally return to check for more possible values*/
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        resp.push_back(res);
        return;
    }

     /*BACKTRACKING STEP
     Loop to traverse the adjacency lis
     of currPos node and increasing the count
     by 1 and cost by graph[currPos][i] value*/
    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[currPos][i]){

            //Mark as visited
            v[i] = true;
            sol.push_back(i + 1);
            tsp(graph, v, resp, i, n, count + 1, cost + graph[currPos][i], ans);
            //Mark ith node as unvisited
            v[i] = false;
            sol.pop_back();
        }
    }

};

int main()
{

    int n;
    int ans = INT_MAX;
    vector<Respuesta> b;
    cout << "Ingrese el numero de cuidades:";
    cin >> n;
    int graph[V][V];
    insertarElemento(graph, n);
    mostrarGrafo(graph, n);    
    vector<bool> v(n);    
    for (int i = 0; i < n; i++)
        v[i] = false;
    v[0] = true;
    tsp(graph,v, b, 0, n, 1, 0, ans);
    b = p(b, graph);
    cout << "Solucion:" << endl;
    mostrarSolucion(b, ans);
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
