/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: MULTIPLICACION DE MATRICES
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/

#pragma once
#include <iostream>
#include <string>

class Operation
{
public:
	/**
		 * @brief Contructor
		 *
		 */
	Operation();
	/**
		 * @brief multiply matrices
		 *
		 * @return void
		
		 */
	void multiply(int[10][10], int[10][10], int[10][10]);
	/**
		 * @brief wax matrices
		 *
		 * @return void

		 */
	void wax(int[10][10]);
	/**
		 * @brief read matrices
		 *
		 * @return void

		 */
	void read(int[10][10],int,int);
	/**
		 * @brief print matrices
		 *
		 * @return void

		 */
	void print(int[10][10],int,int);

	
	
};

