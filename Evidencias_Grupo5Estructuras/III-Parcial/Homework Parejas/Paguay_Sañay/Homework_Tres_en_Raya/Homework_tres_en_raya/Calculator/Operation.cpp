/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*

*@author ALEX PAGUAY
*@author SANTIAGO SA�AY

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



bool Operation::verificar_matrix_suma15(Matrix matrix)
{
   
    int sum = 0;
    if (*(*(matrix.get_matrix())) + *(*(matrix.get_matrix() + 1) + 1) + *(*(matrix.get_matrix() + 2) + 2) == 15) {
        sum++;
    }
    if (*(*(matrix.get_matrix())) + *(*(matrix.get_matrix() + 0) + 1) + *(*(matrix.get_matrix() + 0) + 2) == 15) {
        sum++;
    }
    if (*(*(matrix.get_matrix()+1)) + *(*(matrix.get_matrix() + 1) + 1) + *(*(matrix.get_matrix() + 1) + 2) == 15) {
        sum++;
    }
    if (*(*(matrix.get_matrix()+2)) + *(*(matrix.get_matrix() + 2) + 1) + *(*(matrix.get_matrix() + 2) + 2) == 15) {
        sum++;
    }
    if (*(*(matrix.get_matrix()+2)+0) + *(*(matrix.get_matrix() + 1) + 1) + *(*(matrix.get_matrix() + 0) + 2) == 15) {
        sum++;
    }
    if (*(*(matrix.get_matrix() + 0) + 0) + *(*(matrix.get_matrix() + 1) + 0) + *(*(matrix.get_matrix() + 2) + 0) == 15) {
        sum++;
    }
    if (*(*(matrix.get_matrix() + 0) + 1) + *(*(matrix.get_matrix() + 1) + 1) + *(*(matrix.get_matrix() + 2) + 1) == 15) {
        sum++;
    }
    if (*(*(matrix.get_matrix() + 0) + 2) + *(*(matrix.get_matrix() + 1) + 2) + *(*(matrix.get_matrix() + 2) + 2) == 15) {
        sum++;
    }
    if (sum == 8) {
        
        return true;
    }
    return false;
}

void Operation::vec_to_matrix(int* vec,Matrix matrix)
{
   
    int cont = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(matrix.get_matrix() + i) + j) = *(vec + cont);
            cont++;
        }
    }
    
}



void Operation::swap(int* v, int i, int j)
{
    int	t;

    t = *(v+i);
    *(v + i) = *(v + j);
    *(v + j) = t;
}

void Operation::perm(int *v, int n, int i,Matrix matrix, int &sol)
{
    /* this function generates the permutations of the array
     * from element i to element n-1
     
     */
    vec_to_matrix(v, matrix);
    bool band = false;
    if (verificar_matrix_suma15(matrix)) {
        
        band = true;
       
    }
    else {
        //cout << "no es solucion" << endl;
    }
    int	j;

    /* if we are at the end of the array, we have one permutation
     * we can use (here we print it; you could as easily hand the
     * array off to some other function that uses it for something
     */
    if (i == n) {
        if (band) {
            for (j = 0; j < n; j++) printf("%d ", *(v + j));
            printf("\n");
            cout << "si es solucion" << endl;
            imprimir(matrix, 3);
            sol = sol + 1;
        }
        /*for (j = 0; j < n; j++) printf("%d ", *(v+j));
        printf("\n");*/
    }
    else
        /* recursively explore the permutations starting
         * at index i going through index n-1
         */
        for (j = i; j < n; j++) {

            /* try the array with i and j switched */

            swap(v, i, j);
            perm(v, n, i + 1,matrix,sol);

            /* swap them back the way they were */

            swap(v, i, j);
        }
}






