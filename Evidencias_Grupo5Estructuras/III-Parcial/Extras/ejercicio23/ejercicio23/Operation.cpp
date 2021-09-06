/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Multiplicacion matriz dinamica
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
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
    
    for (int i = 0; i < num_casillas; i++) {
        
        if (*(vec + i) != range) {
           return false;
        }
    }
   
   
    return true;
}

void Operation::calcular_minimo_cd(int* vec_perm, int* vec_size_files, int range, int tamanio_cd, int& max,int num_archivos)
{
    
    max = range;
    
    if(cumple_tamanio_del_cd(vec_perm, vec_size_files, num_archivos, max, tamanio_cd)) {
        imprimir_vec(vec_perm, num_archivos);
        return;
    }
    else {
        next_vec_per(vec_perm, num_archivos, range, num_archivos - 1);
       
        if (complete_per(vec_perm, num_archivos, range)) {
            range++;
        }
        calcular_minimo_cd(vec_perm, vec_size_files, range, tamanio_cd, max, num_archivos);
    }

}

int Operation::max_de_vector(int* vec, int tamanio)
{
    int max = *(vec + 0);
    int data = 0;
    for (int i = 1; i < tamanio; i++) {
        data = *(vec + i);
        if (data > max) {
            max = data;
        }

    }
    return max;
}

bool Operation::cumple_tamanio_del_cd(int* vec_per, int* vec_size_files, int range,int max, int tamanio_cd)
{
    int suma;
    int data;
    for (int i = 1; i <= max; i++) {
        suma = 0;
       
        for (int j = 0; j < range; j++) {
            data = *(vec_per + j);
            if (data == i) {
                suma = suma + (*(vec_size_files + j));
            }

        }
        if (suma > tamanio_cd) {
            return false;
        }
    }
    return true;
}

void Operation::minimo_cds_para_archivos()
{
    int num_archivos = 0;
    int capacidad_cd = 0;
    int cd_minimos_necesarios = 1;
   
    cout << "ingrese el numero de archivos" << endl;
    cin>> num_archivos;
    cout << "ingrese la capacidad del cd" << endl;
    cin >> capacidad_cd;
    int* vec_per = new int[num_archivos];
    int* vec_size_files = new int[num_archivos];
    for (int i = 0; i < num_archivos; i++) {
        *(vec_per + i) = 1;
    }
    int min = capacidad_cd / 5;
    int max = capacidad_cd - capacidad_cd / 10;
    max = capacidad_cd / 3;
    int data = 0;
    
    for (int i = 0; i < num_archivos; i++) {
        data= min + (rand() % (max-min));
        *(vec_size_files + i) = data;
    }
    imprimir_vec(vec_size_files, num_archivos);
    calcular_minimo_cd(vec_per, vec_size_files, 1, capacidad_cd, cd_minimos_necesarios, num_archivos);
    cout << "la cantidad minima necesaria para grabar los archivos es: ";
    cout << cd_minimos_necesarios << endl;
}








