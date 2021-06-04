#include <iostream>
#include "Operation.h"
#include "Matrix.h"
using namespace std;

int main()
{
    int size;
    Operation op;
    Matrix matrix_1, matrix_2, matrix_r;
    std::cout << "Multiplicacion de matrices\n";
    cout << "Ingrese la dimension:";
    cin >> size;
    matrix_1.set_matrix(op.segmentar(size));
    matrix_2.set_matrix(op.segmentar(size));
    matrix_r.set_matrix(op.segmentar(size));
    op.encerar(matrix_1, size);
    op.encerar(matrix_2, size);
    op.encerar(matrix_r, size);
    op.ingresar(matrix_1, size);
    op.ingresar(matrix_2, size);
    op.calcular(matrix_1, matrix_2, matrix_r,size);
    op.imprimir(matrix_r, size);
}

