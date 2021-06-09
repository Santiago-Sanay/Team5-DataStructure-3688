#include <iostream>
#include <string>
#include "Matrix.h"
#include "MatrixMath.h"
int main()
{
    Matrix<int> _matrix{3};
    int **_matrix_test = _matrix.get_matrix();
    int j = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << "Ingrese los elementos [" << i << "][" << j << "]:";
            std::cin >> _matrix_test[i][j];
        }
    }
    MatrixMath::gauss_jordan(_matrix);
    MatrixMath::print(_matrix);
    return (0);
}