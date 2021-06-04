/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 1 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 3 DE JUNIO 2021
*/

#include <iostream>
#include "Operation.h"
#include "Matrix.h"
using namespace std;

int main()
{
    int size, pot;
    Operation op;
    Matrix matrix_1, matrix_2, matrix_r;
    std::cout << "Potencia de matriz\n";
    cout << "Ingrese la dimension:";
    cin >> size;
    cout << "Ingrese la potencia:";
    cin >> pot;
    matrix_1.set_matrix(op.segmentar(size));
    matrix_r.set_matrix(op.segmentar(size));
    op.encerar(matrix_1, size);
    op.encerar(matrix_r, size);
    op.ingresar(matrix_1, size);
    op.calcular_potencia(matrix_1, matrix_r, size, pot);
    op.imprimir(matrix_r, size);
}

