/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 28 DE MAYO DE 2021
*FECHA DE MODIFICACION: 29 DE MAYO 2021
*/
#pragma once
#include "Vector.h"
class Operaciones
{
public:
	Operaciones();

	/**
	 * @brief Initializes the vector with the data at 0
	 * 
	 * @param vector Object 
	 */
	void encerar(Vector &);

	/**
	 * @brief Generates randoms from 1 -10 to fill the vector
	 * 
	 * @param vector Object
	 */
	void ingresar(Vector &);

	/**
	 * @brief Calculates the average of the vector sent
	 * 
	 * @param vector Object 
	 * @return the average calculation
	 */
	float procesar(Vector &);

	/**
	 * @brief Displays the elements of the Vector
	 * 
	 * @param vector Object 
	 */
	void imprimir(Vector &);
};
