/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: CALENDAR PAYMENT
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#pragma once
#include "Calendar.h"
#include <iostream>
using namespace std;
class Operation
{
public:
	/**
	 * @brief way the array date in Calendar
	 *
	 * @void.
	 */
	void wax(Calendar);
	/**
	 * @brief calculate el number of the date in calendar
	 *
	 * @return int.
	 */
	int calculate_day(string);
	/**
	 * @brief put dates in calendar vector
	 *
	 * @void.
	 */
	void date_vector(string, int, Calendar&);
	/**
	 * @brief verify a date in calendar
	 *
	 * @return date array.
	 */
	string set_valid_date(string);
	/**
	 * @brief print calendar vector
	 *
	 * @void.
	 */
	void print_calendar(int, string[100]);
	/**
	 * @brief gverify weekend in calednar vector
	 *
	 * @void.
	 */
	void set_weekend(int, string[100]);
	/**
	 * @brief check hollidays in calendar vector
	 *
	 * @rbool.
	 */
	bool check_holiday(string);
	/**
	 * @brief check weekends in a array
	 *
	 * @return true or false.
	 */
	bool check_fds(string);
	/**
	 * @briefput a day to a day
	 *
	 * @return the next date as string.
	 */
	string add_day(string);

};


