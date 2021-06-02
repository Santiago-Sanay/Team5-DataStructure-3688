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
using namespace std;
class Operation
{
public:
	void wax(Calendar);
	int calculate_day(string);
	void date_vector(string, int, Calendar&);
	string set_valid_date(string);
	void print_calendar(int, string[100]);
	void set_weekend(int, string[100]);
	bool check_holiday(string);
	bool check_fds(string);
	string add_day(string);

};


