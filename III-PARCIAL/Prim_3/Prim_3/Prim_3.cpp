// Prim_3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Operation.h"
#include "Matrix.h"
#include "Operation_Prim.h"
int main()
{
    Operation_Prim op_prim;
    Operation op;
    srand(time(NULL));
    int size = 5;
    Matrix matrix1;
    matrix1.set_matrix(op.segmentar(5));
    op.encerar(matrix1, 5);
    op.generar_tabla_aleatoria(matrix1, 5,7);
    cout << "TABLA DE ADYACENCIA PONDERADA" << endl;
    op.imprimir(matrix1, 5);
    cout <<endl<< "ARBOL DE EXPANSION MINIMA" << endl;
    op_prim.primMST(matrix1.get_matrix(),5);

    return 0;
}

