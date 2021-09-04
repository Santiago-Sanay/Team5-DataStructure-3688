/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: CALENDAR DATA PAYMENT
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#pragma once
#include <string>
class Calendar
{
private:
	
	std::string date[100];
public:
	/**
	 * @brief Member Constructor of Calendar
	 *
	 * @
	 */
	Calendar(std::string [100]);
	/**
	 * @brief set a date array to the Calendar
	 *
	 * @void.
	 */
	void set_date(std::string [100]);
	/**
	 * @brief get a date array of Calendar
	 *
	 * @return date array.
	 */
	std::string* get_date();


};

