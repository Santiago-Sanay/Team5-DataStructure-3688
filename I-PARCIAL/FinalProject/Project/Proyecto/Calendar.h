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
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#pragma once
#include <string>
using namespace std;
class Calendar
{
private:
	string* date;
public:

	/**
	 * @brief Construct a new Calendar object
	 * 
	 */
	Calendar(string*);

	/**
	 * @brief Construct a new Calendar object
	 * 
	 */
	Calendar() = default;

	/**
	 * @brief Set the date object
	 * 
	 */
	void set_date(string*);

	/**
	 * @brief Get the date object
	 * 
	 * @return string* 
	 */
	string* get_date();


};
