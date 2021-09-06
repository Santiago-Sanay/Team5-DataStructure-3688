/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*

*@author ALEX PAGUAY
*@author SANTIAGO SA�AY

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
