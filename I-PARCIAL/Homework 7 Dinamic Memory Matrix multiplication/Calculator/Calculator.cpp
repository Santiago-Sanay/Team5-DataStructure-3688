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

