/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Ordenamiento de datos
*FECHA DE CREACION : 25 DE JULIO DE 2021
*FECHA DE MODIFICACION: 26 DE JUNIO 2021
*/
#pragma once
class Vector
{
private:
	int *arreglo;
public:
	/**
	 * @brief constructor
	 *
	 * @void
	 */
	Vector() = default;
	/**
	 * @brief constructor programado
	 *
	 * @void
	 */
	Vector(int*);
	/**
	 * @brief setter
	 *
	 * @void
	 */
	void set_arreglo(int*);
	/**
	 * @brief ogetter
	 *
	 * @un puntero entero
	 */
	int* get_arreglo();
};

