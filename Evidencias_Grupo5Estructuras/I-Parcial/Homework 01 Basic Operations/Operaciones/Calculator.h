/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: CREACION DE UN PROGRAMA DE OPERACIONES BASICAS(SUMA, RESTA, MULTIPLICAION, DIVISION) CON TEMPLATES<>
*FECHA DE CREACION : 19 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 20 DE MAYO 2021
*/
#pragma once
#include "Number.h"

template <typename T>
class Calculator
{
public:
	/**
	 * @brief Member function to add two numbers
	 *
	 * @return the sum.
	 */
	static T add(Number<T>&);

	/**
	 * @brief Member function to subtract two numbers
	 *
	 * @return the subtraction
	 */
	static T subtract(Number<T>&);

	/**
	 * @brief Member function to multiply two numbers
	 *
	 * @return the multiplication
	 */
	static T multiply(Number<T>&);

	/**
	 * @brief Member function to divide two numbers
	 *
	 * @return the divide
	 */
	static T divide(Number<T>&);
};

#include "Calculator.cpp"