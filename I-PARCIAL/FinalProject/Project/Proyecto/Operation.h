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


#pragma once
#include "Matrix.h"
template<class T>
class Operation
{
public:
	/**
	 * @brief Reserva memoria para la matriz
	 *
	 * @param longitud
	 * @return la dirreccion de una matriz
	 */
	T** segmentar(int);
	T** segmentar2(int, int);

	/**
	 * @brief Inicializa la matriz en cero
	 *
	 * @param matriz_a
	 * @param longitud
	 */
	void encerar(Matrix<T> matriz_a, int, int);

};

template<class T>
T** Operation<T>::segmentar(int dim) {
    Matrix matrix;
    int j;
    matrix.set_matrix((T**)malloc(dim * sizeof(T*)));
    for (j = 0; j < dim; j++) {
        *(matrix.get_matrix() + j) = (T*)malloc(dim * sizeof(T));
    }
    return matrix.get_matrix();
}
template<class T>
T** Operation<T>::segmentar2(int filas, int columnas)
{
    Matrix<T> matrix;
    int j;
    matrix.set_matrix((T**)malloc(columnas * sizeof(T*)));
    for (j = 0; j < filas; j++) {
        *(matrix.get_matrix() + j) = (T*)malloc(columnas * sizeof(T));
    }
    return matrix.get_matrix();
}
template<class T>
void Operation<T>::encerar(Matrix<T> matrix, int dim,int column) {
    int i, j;
    for (i = 0; i < dim; i++)
        for (j = 0; j < column; j++)
            *(*(matrix.get_matrix() + i) + j) = 0;
}
