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
        //if (band) {
            for (j = 0; j < n; j++) printf("%d ", *(v + j));
            printf("\n");
            /*cout << "si es solucion" << endl;
            imprimir(matrix, 3);
            sol = sol + 1;
        //}
        /*for (j = 0; j < n; j++) printf("%d ", *(v+j));
        printf("\n");*/
    }
    else
        /* recursively explore the permutations starting
         * at index i going through index n-1
         */
        for (j = i; j < n; j++) {

            /* try the array with i and j switched */

            swap(v, j, i);
            perm(v, n, i + 1,matrix,sol);

            /* swap them back the way they were */

            swap(v, j, i);
        }
}

void Operation::generar_tabla_aleatoria(Matrix matrix, int dim)
{
    int u;
   
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            u = 1 + (rand() % 2) - 1;
            if (i != j) {
                *(*(matrix.get_matrix() + i) + j) = u;
                *(*(matrix.get_matrix() + j) + i) = u;
            }
            else {
                *(*(matrix.get_matrix() + j) + i) = 0;
            }
        }
    }
}

void Operation::permutacion(string aux, int* items, int n, int r)
{
    string resp = aux;
    if (r > 0) {
        for (int x = 0; x < n; x++) {
            //cout <<" -"<< aux << endl;
            permutacion(aux + to_string(*(items + x)), items, n, r - 1);
        }
    }
    else {
        cout << endl << resp;
    }
}

int Operation::contar_colores(int n,int *vec1, int** matrix)
{
    int colors = 1;
    bool band = true, band2;
    int* vec = new int[n];
    for (int i = 0; i < n; i++) {
        *(vec + i) = 1;
    }
    int cont = 0;
    
    while (colors < n && band) {
        band2 = true;
       
        for (int i = 0; i < n; i++) {
            *(vec + i) = 1;
        }
        
        while (!complete_per(vec, n, colors)) {
           
            
            next_vec_per(vec, n, colors, n-1);
            if (process(vec, n, matrix)) {
                cont++;
                if (cont == 1) {
                    cout << "la forma de pintar es:";
                    imprimir_vec(vec, n);
                    cout << endl << "la cantidad de colores necesarios es:";
                    exit;
                }
                
                
                band = false;
            }
            
        }
        colors++;
        
    }
    if (colors > 1) {
        colors--;
    }
    return colors;
}

bool Operation::process(int* vec,int n, int** matrix)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (*(vec + i) == *(vec + j) && adyacent(i, j, matrix)) {
              
                return false;
            }
                
        }
    }
    return true;
}

bool Operation::adyacent(int i, int j, int** matrix)
{
    if (*(*(matrix + i) + j) == 1) {
        return true;
    }
    return false;
}

bool Operation::nextPermutation(int* vec, int color,int n)
{
    if (color == n) {
        return false;
    }
    else {
        for (int i = 0; i < n; i++) {
            return nextPermutation(vec, color + 1, n);
        }
    }
    return false;
}

void Operation::imprimir_vec(int* vec, int n)
{
    for (int i = 0; i < n; i++) {
        cout << *(vec + i) << " ";
    }
    cout << endl;
}

void Operation::next_vec_per(int* &vec, int num_casillas, int range, int position)
{
    
    if (range > 0 && position>=0) {
        *(vec + position)= *(vec + position)+1;
        if (*(vec + position) > range) {
            *(vec + position) = 1;
            next_vec_per(vec, num_casillas, range, position - 1);
        }
        
    }
    else {
        return;
    }
}

bool Operation::complete_per(int* vec, int num_casillas, int range)
{
    int cont = 0;
    for (int i = 0; i < num_casillas; i++) {
        
        if (*(vec + i) == range) {
            cont++;
        }
    }
   
    if (cont == num_casillas) {
        return true;
    }
    return false;
}

bool Operation::suma_billete(int* vec, int valor)
{
    int val1 = (*(vec));
    int val2 = 5*(*(vec+1));
    int val3 = 10*(*(vec + 2));
    int val4 = 25*(*(vec + 3));
    int val5 = 50*(*(vec+4));
    int val6 = 100 * (*(vec + 5));
    int val7 = 500 * (*(vec + 6));
    int val8 = 1000 * (*(vec + 7));
    //int val9 = 20 * (*(vec + 8));
    int suma = val1 + val2 + val3+val4+ val5 + val6 + val7 + val8;
    if (suma == valor*100) {
        return true;
    }
    return false;
}

void Operation::next_vec_per1(int*& vec, int num_casillas, int range, int position)
{
    if (range > 0 && position >= 0) {
        *(vec + position) = *(vec + position) + 1;
        if (*(vec + position) > range) {
            *(vec + position) = 0;
            next_vec_per1(vec, num_casillas, range, position - 1);
        }

    }
    else {
        return;
    }
}

void Operation::imprimir_vec2(int* vec, int n)
{
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout <<"Monedas de 1ctvo: "<< *(vec + i) << ", ";
        }
        if (i == 1) {
            cout << "Monedas de 5ctvos: " << *(vec + i) << ", ";
        }
        if (i == 2) {
            cout << "Monedas de 10ctvos: " << *(vec + i) << ", ";
        }
        if (i == 3) {
            cout << "Monedas de 25ctvos: " << *(vec + i) << ", ";
        }
        if (i == 4) {
            cout << "Monedas de 50ctvos: " << *(vec + i) << ", ";
        }
        if (i == 5) {
            cout << "Monedas de 1 dolar: " << *(vec + i) << ", ";
        }
        if (i == 6) {
            cout << "billetes de 5 dolares: " << *(vec + i) << ", ";
        }
        if (i == 7) {
            cout << "billetes de 10 dolares : " << *(vec + i) << ", ";
        }
       /* if (i == 8) {
            cout << "billetes de 20 dolares: " << *(vec + i) << ", ";
        }*/
        
    }
    cout << endl;
}

void Operation::next_vec_per2(int*& vec, int num_casillas, int range, int position)
{
    if (range > 0 && position >= 0) {
        *(vec + position) = *(vec + position) + 1;
       
        if (position == 7) {
            if (*(vec + position) > range/10) {
                *(vec + position) = 0;
                next_vec_per2(vec, num_casillas, range, position - 1);
            }
        }
        if (position == 6) {
            if (*(vec + position) > range / 5) {
                *(vec + position) = 0;
                next_vec_per2(vec, num_casillas, range, position - 1);
            }
        }
        if (position == 5) {
            if (*(vec + position) > range / 1) {
                *(vec + position) = 0;
                next_vec_per2(vec, num_casillas, range, position - 1);
            }
        }
        if (position == 4) {
            if (*(vec + position) > range ) {
                *(vec + position) = 0;
                next_vec_per2(vec, num_casillas, range, position - 1);
            }
        }
        if (position == 3) {
            if (*(vec + position) > range) {
                *(vec + position) = 0;
                next_vec_per2(vec, num_casillas, range, position - 1);
            }
        }
        if (position == 2) {
            if (*(vec + position) > 25) {
                *(vec + position) = 0;
                next_vec_per2(vec, num_casillas, range, position - 1);
            }
        }
        if (position == 1) {
            if (*(vec + position) > 20) {
                *(vec + position) = 0;
                next_vec_per2(vec, num_casillas, range, position - 1);
            }
        }
        if (position == 0) {
            if (*(vec + position) >20) {
                *(vec + position) = 0;
                next_vec_per2(vec, num_casillas, range, position - 1);
            }
        }

    }
    else {
        return;
    }
}

bool Operation::complete_per1(int* vec, int num_casillas, int range)
{
    int cont = 0;
    if (*(vec) == 20) {
        
        if (*(vec+1) == 20) {
            
            if (*(vec + 2) == 25) {
                if (*(vec + 3) == range ) {
                    if (*(vec+4) == range) {
                        
                        if (*(vec + 5) == range ) {
                            
                            if (*(vec + 6) == range / 5) {
                                if (*(vec + 7) == range / 10) {
                                    //if (*(vec + 8) == range / 20) {
                                        return true;
                                    //}
                                }
                            }
                        }
                    }
                    
                }
            }
        }
    }
    
    return false;
}

void Operation::encerar_array(int* array, int n)
{
    for (int i = 0; i < n; i++) {
        *(array + i) = 0;
    }
}







