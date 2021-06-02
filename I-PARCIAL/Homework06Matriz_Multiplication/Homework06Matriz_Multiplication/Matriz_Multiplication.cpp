/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
// Homework06Matriz_Multiplication.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Operation.h"
using namespace std;

int main()
{
    int m1[10][10];
    int m2[10][10];
    int mr[10][10];
    int row1 = 0;
    int column1=0;
    int row2 = 0;
    int column2 = 0;
    cout << "ingrese el numero de filas de la primera matriz" << endl;
    cin >> row1;
    cout << "ingrese el numero de columnas de la primera matriz" << endl;
    cin >> column1;
    cout << "ingrese el numero de filas de la segunda matriz" << endl;
    cin >> row2;
    cout << "ingrese el numero de columnas de la segunda matriz" << endl;
    cin >> column2;

    Operation op;
    op.leer(m1,row1,column1);
    op.leer(m2, row2, column2);
    op.multiply(m1, m2, mr);
    op.imprimir(mr, row1, column2);
   
}
