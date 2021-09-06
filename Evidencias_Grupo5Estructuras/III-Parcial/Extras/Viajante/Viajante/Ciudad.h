#pragma once
#include <vector>
#include <iostream>
#include "Respuesta1.h"
using namespace std;

void insertarElemento(int graph[][V], int dim) {
    int i, j;
    cout << "Ingrese los datos:" << endl;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++) {
            cout << "[" << i + 1 << "]" << "[" << j + 1 << "] :";
            cin >> graph[i][j];
        }
}
    
void mostrarGrafo(int graph[][V], int dim){
    int i, j;
    printf("\n");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d", graph[i][j]);
            printf("%*s", j + 5, "");
        }
        printf("\n");
    }
}
vector<Respuesta> p(vector <Respuesta> &resp, int graph[][V]) {
    for (size_t i = 0; i < resp.size(); i++)
    {
        resp.at(i).insertar(1);
        resp.at(i).add(1);
        resp.at(i).add((resp.at(i).sum(graph)));
    }
    return resp;
}
    
void mostrarSolucion(vector <Respuesta> resp, int cost) {
    for (int i = 0; i < resp.size(); i++)
    {
        if (resp.at(i).get_res().back() == cost) {
            resp.at(i).mostrar();
            cout << endl;
        }
        
    }
}

