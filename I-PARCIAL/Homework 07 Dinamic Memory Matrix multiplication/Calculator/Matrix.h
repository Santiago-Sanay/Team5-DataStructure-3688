/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Multiplicacion matriz dinamica
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/
#pragma once
class Matrix
{
private:
	int **matrix;

public:
	/**
	 * @brief 
	 * 
	 */

	Matrix() = default;
	/**
	 * @brief Get the matrix object
	 * 
	 * @return int** 
	 */
	int **get_matrix();
	/**
	 * @brief Set the matrix object
	 * 
	 */
	void set_matrix(int **);
};
