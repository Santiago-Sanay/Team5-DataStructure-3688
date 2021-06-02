

#include <iostream>
#include "Matriz.h"
#include "Operation.h"
using namespace std;
int main()
{
    //int matriz[10][10] = { {1,3} ,{6,1} };
    //Matriz m1(matriz,2,2);
    //m1.print_matriz(2,2);
    int colum,row;
    int matrixP[10][10];
    int matrixQ[10][10];
    int fila;
    cout << "\tMATRIZ 1"<<endl;
    cout << "Ingrese filas" << endl;
    cin >> row;
    cout << "Ingrese columnas" << endl;
    cin >> colum;
    
    cout << "Matriz 1: " << row << "x" << colum << endl;

    for(int i=0; i< row; i++){
        for(int j=0;j< colum;j++){
            cout << "\nColumna " << i+1 << " Fila " << j+1 << endl;
            cin >> fila;
            matrixP[i][j] = fila;
        }
    }
    Matriz matrizA(matrixP, row, colum);
    matrizA.print_matriz();
    //Matriz matrizA(matrixP,colum,row);

    //cout << "Matriz 2: " << sizeM << "x" << sizeM << endl;
    //for (int i = 0; i < sizeM; i++) {
    //    for (int j = 0; j < sizeM; j++) {
    //        cout << "Columna " << i << "Fila " << j << endl;
    //        cin >> fila;
    //        matrixQ[i][j] = fila;
    //    }
    //}
}


