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
*FECHA DE CREACION : 6 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 8 DE JUNIO 2021
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
    std::cout << "*****CUADRADO MAGICO*******\n";
    cout << "Ingrese la dimension del cuadrado (#impar):   ";
    cin >> size;
    while(size%2==0){
        cout << "Ingrese la dimension del cuadrado (#impar)";
        cin >> size;
    }
    
    matrix_1.set_matrix(op.segment(size));
    
    op.wax(matrix_1, size);
    op.magic_square(matrix_1, size);
    op.print(matrix_1, size);
}

