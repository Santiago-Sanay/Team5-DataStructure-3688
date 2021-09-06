/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY

*/

#include <iostream>
#include "Operation.h"
#include "Matrix.h"
#include "Utils.h"
using namespace std;

int main()
{
    Operation op;
    srand(time(NULL));
    int size=5;
    cout << "INGRESE EL NUMERO DE CIUDADES" << endl;
    cin >> size;
    Matrix matrix1;
    matrix1.set_matrix(op.segmentar(size));
    op.encerar(matrix1, size);
    op.generar_tabla_aleatoria(matrix1, size);
    op.imprimir(matrix1, size);
    int l = 0;
    int* vec1 = new int[5];
    *(vec1 + 0) = 1;
    *(vec1 + 1) = 2;
    *(vec1 + 2) = 3;
    *(vec1 + 3) = 4;
    *(vec1 + 4) = 5;

   
    /*int* vec = new int[9];
    for (int i = 1; i < 10; i++) {
        *(vec + i - 1) = i;
    }*/
    
    cout<<op.contar_colores(size, vec1, matrix1.get_matrix())<<endl;
    int* vec2 = new int[6];
    *(vec2 + 0) = 0;
    *(vec2 + 1) = 0;
    *(vec2 + 2) = 0;
    *(vec2 + 3) = 0;
    *(vec2 + 4) = 0;
    cout << "ingrese el valor que quiere" << endl;
    int n = 0;
    cin >> n;
    while (!op.complete_per1(vec2, 4, n)) {
       
        if (op.suma_billete(vec2, n)) {
            op.imprimir_vec2(vec2, 4);
        }
        op.next_vec_per2(vec2, 4, n, 3);
    }
    /*for (int i = 1; i < 10; i++) {
        *(vec + i - 1) = i;
    }
   
   while(!op.complete_per(vec2,4,5)) {
        op.imprimir_vec(vec2, 4);
        op.next_vec_per(vec2, 4, 5, 3);
    }
    /*
    int n, r;
    cout << endl << "N:";
    cin >> n;
    cout << endl << "R:";
    cin >> r;
    cout << endl << "listar elementos" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(vec + i) << endl;
    }
    op.permutacion("", vec, n, r);
    /*
    Matrix matrix;
    matrix.set_matrix(op.segmentar(3));
    op.encerar(matrix, 3);
    int sol = 0;
    op.perm(vec, 9, 0,matrix,sol);
    cout << " El numero de soluciones validas es: " << sol << endl;
    exit(0);*/
   
}

