/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Cuadro Latino
*FECHA DE CREACION : 6 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/
#pragma once
class Matrix
{
private:
	int **matrix;
	int dim;
public:
	/**
	 * @brief Construct a new Matrix object
	 * 
	 */
	Matrix();

	/**
	 * @brief Construct a new Matrix object
	 * 
	 * @param dim 
	 */
	Matrix(int dim);
	
	/**
	 * @brief Get the matrix object
	 * 
	 * @return int** 
	 */
	int **get_matrix();
	
	/**
	 * @brief Get the dim object
	 * 
	 * @return int 
	 */
	int get_dim();
	
	/**
	 * @brief Set the matrix object
	 * 
	 */
	void set_matrix(int **);
	
	/**
	 * @brief Set the dim object
	 * 
	 */
	void set_dim(int);
	
	/**
	 * @brief reserve memory space
	 * 
	 */
	void segmentar();
	
	/**
	 * @brief assigns 0 to the matrix data
	 * 
	 */
	void encerar();

	/**
	 * @brief enter data into the matrix
	 * 
	 */
	void ingresar();
	
	/**
	 * @brief print data to the matrix
	 * 
	 */
	void imprimir();
};
