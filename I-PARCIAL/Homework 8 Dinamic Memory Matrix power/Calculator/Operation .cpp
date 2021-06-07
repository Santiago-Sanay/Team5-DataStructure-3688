/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Potencia de matriz dinamica
*FECHA DE CREACION : 2 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 4 DE JUNIO 2021
*/


#include "Operation.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include <iostream>
using namespace std;

int** Operation::segmentar(int dim) {
    Matrix matrix;
    int j;
    matrix.set_matrix((int**)malloc(dim * sizeof(int*)));    
    for (j = 0; j < dim; j++) {
        *(matrix.get_matrix() + j) = (int*)malloc(dim * sizeof(int));
    }
    return matrix.get_matrix();
}
void Operation::encerar(Matrix matrix, int dim) {
    int i, j;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            *(*(matrix.get_matrix() + i) + j) = 0;
}
void Operation::ingresar(Matrix matrix, int dim) {
    int i, j;
    cout << "Ingrese los datos:" << endl;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++) {
            cout << "[" << i + 1 << "]" << "[" << j + 1 << "] :";
            cin>>(*(*(matrix.get_matrix() + i) + j));
        }
}
void Operation::calcular(Matrix matrix_1, Matrix matrix_2, Matrix matrix_r, int dim) {
    int i, j, k;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            for (k = 0; k < dim; k++) {
                *(*(matrix_r.get_matrix() + i) + j) = *(*(matrix_r.get_matrix() + i) + j) + *(*(matrix_1.get_matrix() + i) + k) * *(*(matrix_2.get_matrix() + k) + j);
            }
        }
    }
}
void Operation::imprimir(Matrix matrix, int dim) {
    int i, j;
    printf("\n");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d", *(*(matrix.get_matrix() + i) + j));
            printf("%*s", j + 5, "");
        }
        printf("\n");
    }
}

void Operation::copiar_matriz(Matrix m1, Matrix m2, int dim) {
    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            *(*(m1.get_matrix() + i) + j) = *(*(m2.get_matrix() + i) + j);
        }
    }
}

void Operation::calcular_potencia(Matrix m1, Matrix mr, int dim, int potencia) {
    int i=0,j=0;
    Matrix m2;
    m2.set_matrix(segmentar(dim));
    encerar(m2, dim);
    copiar_matriz(m2, m1, dim);
    copiar_matriz(mr, m1, dim);
    if (potencia==0) {
        encerar(mr, dim);
        for (j = 0; j < dim; j++)
            *(*(mr.get_matrix() + j) + j) = 1;
    }
    for (i = 0; i < potencia-1; i++) {
        encerar(mr, dim);
        calcular(m2, m1, mr, dim);
        copiar_matriz(m2, mr, dim);

    }



}


