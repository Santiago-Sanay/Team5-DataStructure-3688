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
#include "OperationMatrix.h"
#include "Matrix.h"
using namespace std;

int main()
{
    int size;
    Operation op;
    Matrix matrix_1;
    std::cout << "CUADRADO SEMI MAGICO\n";
    cout << "Ingrese la dimension impar:";
    cin >> size;
    while(size%2==0){
        cout << "Ingrese la dimension impar:";
        cin >> size;
    }
    
    matrix_1.set_matrix(op.segmentar(size));
    
    op.encerar(matrix_1, size);
    op.semi_magic_square(matrix_1, size);
    
    op.imprimir(matrix_1, size);
}

