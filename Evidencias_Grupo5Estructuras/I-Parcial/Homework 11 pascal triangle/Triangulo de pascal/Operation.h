/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Triangulo de pascal
*FECHA DE CREACION : 6 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#pragma once
#include "Data.h"

class Operation
{
public:
	/**
	 * @brief calculate the factorial of number
	 * 
	 * @return int 
	 */
	int factorial(int);
	
	/**
	 * @brief calculate the combinatorial of numbers
	 * 
	 * @return int 
	 */
	int combinatorial(int, int);
	
	/**
	 * @brief print pascal triangle
	 * 
	 */
	void print(Data);
};

