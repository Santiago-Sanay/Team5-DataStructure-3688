#pragma once
#include "Matrix.h"
#include <exception>
#include <iostream>
class MatrixMath
{

public:
    template <typename T>
    static inline void gauss_jordan(Matrix<T> &);
    template <typename T>
    static void print(Matrix<T>);
};

template <typename T>
static void inline MatrixMath::gauss_jordan(Matrix<T> &_matrix)
{
    T **_matrix_ptr = _matrix.get_matrix();
    int n = _matrix.get_size();
    T may;   //variable para almacenar el mayor de la columna k
    int ind; //indice del mayor-->indice de may
    T aux;
    T pivote;

    for (int k = 0; k < n; k++)
    { //recorrer columnas de la matriz reducida
        may = abs(_matrix_ptr[k][k]);
        ind = k;
        //recorrer filas de la columna k para buscar el indice del mayor
        for (int l = k + 1; l < n; l++)
        {
            if (may < abs(_matrix_ptr[l][k]))
            {
                may = abs(_matrix_ptr[l][k]);
                ind = l;
            }
        }

        //cambiar filas
        if (k != ind)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    std::cout << "[" << _matrix_ptr[i][j] << "]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            for (int i = 0; i < n; i++)
            {
                aux = _matrix_ptr[k][i];
                _matrix_ptr[k][i] = _matrix_ptr[ind][i];
                _matrix_ptr[ind][i] = aux;
            }
        }
        if (_matrix_ptr[k][k] == 0)
        {
            std::cout << "no tiene solucion";
            break;
        }
        else
        {

            for (int i = 0; i < n; i++)
            { //recorrer fila
                if (i != k)
                {
                    pivote = -_matrix_ptr[i][k];
                    for (int j = k; j < n; j++)
                    { //recorrer elementos de una fila

                        _matrix_ptr[i][j] = _matrix_ptr[i][j] + pivote * _matrix_ptr[k][j] / _matrix_ptr[k][k];
                    }
                }
                else
                {
                    pivote = _matrix_ptr[k][k];
                    for (int j = k; j < n; j++)
                    {
                        _matrix_ptr[i][j] = _matrix_ptr[i][j] / pivote;
                    }
                }
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        std::cout << "[" << _matrix_ptr[i][j] << "]";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }
}

template <class T>
inline void MatrixMath::print(Matrix<T> _matrix)
{
    T **_matriz_print = _matrix.get_matrix();
    int size = _matrix.get_size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << "[" << _matriz_print[i][j] << "]";
        }
        std::cout << std::endl;
    }
}
