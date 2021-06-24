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
#include "Calendar.h"
#include <iostream>
#include "Due.h"
#include "List.h"
using namespace std;
class CalendarOperation
{
public:
	/**
	 * @brief Reserva memoria para la matriz
	 *
	 * @param longitud
	 * @return la dirreccion de una matriz
	 */
	string* segment(int);
	void wax(string*, int);
	int calculate_day(string);
	void date_vector(string, int, Calendar);
	string set_valid_date(string);
	void print_calendar(int, string*);
	void set_weekend(int, string*);
	bool check_holiday(string);
	bool check_fds(string);
	string add_day(string);
	string weekday_name(string);
	double** segment2(int, int);
	void french_amortization(string date, double initial_amount, int payment_time, double interest, List<Due> &dues, double &final_amount);
	void german_amortization(string date, double initial_amount, int payment_time, double interest, List<Due>& dues, double &final_amount);
	void payment_table(string,double,int,string,double, List<Due>);
	double final_amount_payment(List<Due>);

};

