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


#include <iostream>
#include <string>
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
    Operation op;
    string row_1="-", row_2 = "-", column_1 = "-", column_2 = "-";/*
    while (!op.isNumber(row_1)) {
        cout << "ingrese el numero de filas de la primera matriz" << endl;
        cin >> row_1;
    }
    while (!op.isNumber(column_1)) {
        cout << "ingrese el numero de columnas de la primera matriz" << endl;
        cin >> column_1;
    }
    while (!op.isNumber(row_2)) {
        cout << "ingrese el numero de filas de la segunda matriz" << endl;
        cin >> row_2;
    }
    while (!op.isNumber(column_2)) {
        cout << "ingrese el numero de columnas de la segunda matriz" << endl;
        cin >> column_2;
    }
    
   

    
    op.read(m1,stoi(row_1), stoi(column_1));
    op.read(m2, stoi(row_2), stoi(column_2));
    op.multiply(m1, m2, mr);
    op.print(mr, stoi(row_1), stoi(column_2));*/
   
}
