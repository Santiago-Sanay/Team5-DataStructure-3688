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
#include "Nodo.h"
class List
{
private:
	Nodo* head=nullptr;
public:
	List() = default;
	/**
	 * @brief suma al areeglo
	 *
	 * @void
	 */
	void add(int a, int b);
	/**
	 * @brief ordena
	 *
	 * @void
	 */
	void sort();
	/**
	 * @brief  imprime
	 *
	 * @void
	 */
	void print();
	
};

