/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SA�AY
*TEMA: SACARA LA MATRIZ IDENTIDAD CON GAUSS 
*FECHA DE CREACION : 04-06-2021
*FECHA DE MODIFICACION: 18-06-2021
*/
#include <iostream>
#include <string>
#include "Matrix.h"
#include "MatrixMath.h"
#include "Utils.h"
int main()
{
    int size;
    bool validate_size = true;
    while (validate_size)
    {
        std::cout << "Ingrese el tamanio de una matriz: ";
        std::cin >> size;
        validate_size = Utils::Validation::validate_input_number(size);
    }
    validate_size = true;

    Matrix<int> _matrix{ size };
    int **_matrix_test = _matrix.get_matrix();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            bool validate = true;
            while (validate)
            {
                std::cout << "Ingrese los elementos [" << i << "][" << j << "]: ";
                std::cin >> _matrix_test[i][j];
                validate = Utils::Validation::validate_input_number(_matrix_test[i][j]);
            }
        }
    }
    MatrixMath::gauss_jordan(_matrix);
    MatrixMath::print(_matrix);
    return (0);
}
