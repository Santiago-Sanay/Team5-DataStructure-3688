/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA?AY
*TEMA: Multiplicacion matriz dinamica
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#pragma once
#include <string>
#include <iostream>
using namespace std;
class Operation
{
public:
	Operation() = default;
	/**
	 * @brief Get permutar
	 *
	 * @return string
	 */
	void permutar_letras(string aux, string* letras, int n, int r);
	/**
	 * @brief imprimir array
	 *
	 * @return string int
	 */
	void imprimir_array(string* array, int dim);
};

