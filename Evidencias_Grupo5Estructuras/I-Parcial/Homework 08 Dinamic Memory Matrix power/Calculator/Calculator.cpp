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

#include <iostream>
#include "OperationMatrix.h"
#include "Matrix.h"
#include "Utils.h"
using namespace std;

int main()
{
    int size, pot;
    Operation op;
    Matrix matrix_1, matrix_r;
    std::cout << "Potencia de matriz\n";
    size = Utils::Validation::validation_numbers<int>("ingrese la dimension de la matriz");
    pot = Utils::Validation::validation_numbers<int>("ingrese la potencia a la que desea elevar la matriz");

    matrix_1.set_matrix(op.segmentar(size));
    matrix_r.set_matrix(op.segmentar(size));
    op.encerar(matrix_1, size);
    op.encerar(matrix_r, size);
    op.ingresar(matrix_1, size);
    op.calcular_potencia(matrix_1, matrix_r, size, pot);
    op.imprimir(matrix_r, size);
}

