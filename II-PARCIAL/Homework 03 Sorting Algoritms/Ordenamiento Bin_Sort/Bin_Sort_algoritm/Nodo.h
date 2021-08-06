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
#include <iostream>
class Nodo
{
private:
	int bin_no;
	int data;
	Nodo* next;
public:
	Nodo() = default;
	/**
	 * @brief genera un arreglo
	 *
	 * @int
	 */
	int get_bin_no();
	/**
	 * @brief genera un arreglo
	 *
	 * @int
	 */
	int get_data();
	Nodo* get_next();
	/**
	 * @brief genera
	 *
	 * @void
	 */
	void set_bin_no(int new_bin_no);
	/**
	 * @brief siguientdato
	 *
	 * @void
	 */
	void set_data(int new_data);
	/**
	 * @brief setter
	 *
	 * @void
	 */
	void set_next(Nodo* new_next);
};

