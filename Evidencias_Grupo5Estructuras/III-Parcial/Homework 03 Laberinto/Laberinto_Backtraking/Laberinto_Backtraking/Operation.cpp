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

void Operation::generar_t(Matrix matrix)
{
    
    int col_ini = 0;
    int fil_ini= 1 + (rand() % 8)-1;
    encerar(matrix, 8);
    * (*(matrix.get_matrix() + fil_ini) + col_ini) = 1;
    int dir = 0;
    int fil = fil_ini;
    int col = col_ini;
    int aux = fil;
    int aux2 = col;
    for (int i = 1; i < 8; i++) {
        col = i;
        dir = 1 + (rand() % 8)-1;
        fil = dir;
        if (!validate_fila(fil, matrix)) {
            dir = 1 + (rand() % 8)-1;
            fil = dir;
        }

        while (!validate_position(fil, col, matrix)) {
            dir = 1 + (rand() % 8)-1;
            fil = dir;
            if (!validate_fila(fil, matrix)) {
                dir = 1 + (rand() % 8)-1;
                fil = dir;
            }
        }
        *(*(matrix.get_matrix() + fil) + col) = 1;

        
    }

}




bool Operation::validate_position(int fila, int col, Matrix matrix)
{
    if (fila < 0) {
        return false;
    }
    if (col < 0) {
        return false;
    }
    if (fila > 7) {
        return false;
    }
    if (col > 7) {
        return false;
    }
    if (*(*(matrix.get_matrix() + fila) + col) == 1) {
        return false;
    }
    return true;
}

int Operation::num_ataques(Matrix matrix)
{
    int num_ata = 0;
    int cont_fil_1 = 0;
    int cont_col_1 = 0;
    int data = 0;
    for (int i = 0; i < 8; i++) {
        cont_fil_1 = 0;
        cont_col_1 = 0;
        for (int j = 0; j < 8; j++) {
            if (*(*(matrix.get_matrix() + i) + j) == 1) {
                cont_fil_1++;
               
            }
            if (*(*(matrix.get_matrix() + j) + i) == 1) {
                cont_col_1++;
            }

        }
        if (cont_fil_1 >= 1) {
            num_ata = num_ata+ cont_fil_1  - 1;
        }
        if (cont_col_1 >= 1) {
            num_ata = num_ata + cont_col_1 - 1;
        }
        
        
    }
   int fil = 0;
    int col = 0;
    int cont1 = 0;
    for (int i = 0; i < 8; i++) {
        fil = 0;
        col = i;
        cont1 = 0;

        while (fil < 8 && col < 8) {
           
            data = *(*(matrix.get_matrix() + fil) + col);
            if (data == 1) {
                cont1++;

            }
           
            fil++;
            col++;

        }
        if (cont1 >= 1) {
            num_ata = num_ata + cont1 - 1;
        }
       
        
    }
    
    for (int i = 1; i < 8; i++) {
        col= 0;
        fil = i;
        cont1 = 0;

        while (fil < 8 && col < 8) {
           
            data = *(*(matrix.get_matrix() + fil) + col);
            if (data == 1) {
                cont1++;

            }
            fil++;
            col++;

        }
        if (cont1 >= 1) {
            num_ata = num_ata + cont1 - 1;
        }

    }
    
    for (int i = 7; i >= 0; i--) {
        fil = 0;
        col = i;
        cont1 = 0;

        while (fil <8 && col >= 0) {
            data = *(*(matrix.get_matrix() + fil) + col);
            if (data == 1) {
                cont1++;
               
            }
            
            fil++;
            col--;
           

        }
      
       
        if (cont1 >= 1) {
            num_ata = num_ata + cont1 - 1;
        }

    }
    for (int i = 1; i < 8; i++) {
        col = 7;
        fil = i;
        cont1 = 0;

        while (fil < 8 && col >=0) {

            data = *(*(matrix.get_matrix() + fil) + col);
            if (data == 1) {
                cont1++;

            }
            fil++;
            col--;

        }
        if (cont1 >= 1) {
            num_ata = num_ata + cont1 - 1;
        }

    }
    return num_ata;
}

bool Operation::validate_fila(int fil, Matrix matrix)
{
    int cont = 0;
    for (int i = 0; i < 8; i++) {
        if ((*(*(matrix.get_matrix() + fil) + i)) == 1) {
            return false;
        }
    }
    return true;
}









