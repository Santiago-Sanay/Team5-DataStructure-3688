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
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/


#include <iostream>
#include <string>
#include "Operation.h"
#include "Utils.h"
using namespace std;

int main()
{
    int m1[10][10];
    int m2[10][10];
    int mr[10][10];
    int row1 = 0;
    int column1=0;
    int row2 = 0;
    int column2 = 0;
    Operation op;
    
    
    row1=Utils::Validation::validation_numbers<int>("ingrese el numero de filas de la primera matriz");
    column1 = Utils::Validation::validation_numbers<int>("ingrese el numero de columnas de la primera matriz");
    row2 = Utils::Validation::validation_numbers<int>("ingrese el numero de filas de la segunda matriz");
    column2 = Utils::Validation::validation_numbers<int>("ingrese el numero de columnas de la segunda matriz");

    
   

    
    op.read(m1,row1, column1);
    op.read(m2, row2, column2);
    op.multiply(m1, m2, mr);
    cout << "MATRIX 1" << endl;
    op.print(m1, row1, column1);
    cout << "MATRIX 2" << endl;
    op.print(m2, row2, column2);
    cout << "MATRIX Resultante" << endl;
    op.print(mr, row1, column2);
   
}
