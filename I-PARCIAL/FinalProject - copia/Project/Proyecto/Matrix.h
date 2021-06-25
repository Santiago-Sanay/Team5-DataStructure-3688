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
template <class T>
class Matrix
{
private:
	T **matrix;

public:
	/**
	 * @brief Construct a new Matrix object
	 * 
	 */
	Matrix() = default;

	/**
	 * @brief Get the matrix object
	 * 
	 * @return int** 
	 */
	T **get_matrix();

	/**
	 * @brief Set the matrix object
	 * 
	 */
	void set_matrix(T **);
};
template <class T>
T** Matrix<T>::get_matrix() {
	return matrix;
}
template <class T>
void Matrix<T>::set_matrix(T** matrix_1) {
	matrix = matrix_1;
}
