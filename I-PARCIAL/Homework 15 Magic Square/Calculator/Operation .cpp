/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: MAGIC SQUARE
*FECHA DE CREACION : 6 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 8 DE JUNIO 2021
*/

#include "Operation.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include <iostream>
using namespace std;

void Operation::magic_square(Matrix matrix, int _long)
{
    int limit = _long *_long;
    int column = _long / 2;
    int row = 0;

    for (int i = 1; i <= limit; i++) {
        if (*(*(matrix.get_matrix() + row) + column) != 0) {
            row = row + 2;
            if (row >=_long) {
                row = row - _long;
            }
            column = column - 1;
            if (column == -1) {
                column = _long - 1;
            }
        }
        *(*(matrix.get_matrix() + row) + column) = i;
        row = row - 1;
        if (row == -1) {
            row = _long - 1;
        }
        column = column + 1;
        if (column == _long) {
            column = 0;
        }
    }
}
int** Operation::segment(int dim) {
    Matrix matrix;
    int j;
    matrix.set_matrix((int**)malloc(dim * sizeof(int*)));    
    for (j = 0; j < dim; j++) {
        *(matrix.get_matrix() + j) = (int*)malloc(dim * sizeof(int));
    }
    return matrix.get_matrix();
}
void Operation::wax(Matrix matrix, int dim) {
    int i, j;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            *(*(matrix.get_matrix() + i) + j) = 0;
}
void Operation::get_into(Matrix matrix, int dim) {
    int i, j;
    cout << "Ingrese los datos:" << endl;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++) {
            cout << "[" << i + 1 << "]" << "[" << j + 1 << "] :";
            cin>>(*(*(matrix.get_matrix() + i) + j));
        }
}

void Operation::print(Matrix matrix, int dim) {
    int i, j;
    printf("\n");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d", *(*(matrix.get_matrix() + i) + j));
            cout << "\t";
        }
        printf("\n");
    }
}



