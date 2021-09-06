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
    int size;
    int l = 0;

    Operation op;
    int* vec = new int[9];
    for (int i = 1; i < 10; i++) {
        *(vec + i - 1) = i;
    }
    Matrix matrix;
    matrix.set_matrix(op.segmentar(3));
    op.encerar(matrix, 3);
    int sol = 0;
    op.perm(vec, 9, 0,matrix,sol);
    cout << " El numero de soluciones validas es: " << sol << endl;
    exit(0);
   
}

