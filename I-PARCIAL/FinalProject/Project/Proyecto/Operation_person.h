/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROYECTO FINAL
*FECHA DE CREACION : 09 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  09 DE JUNIO DE 2021
*/

#pragma once
#include <conio.h>
#include<string>
#include <stdio.h>
#include "Person.h"
#include "List.h"
class Operation_person
{
public:
	Person data_entry();
	string get_actual_date();
	int calculate_age(string);
	//static void create_email(Person);

	

	bool validate_id(string);
	string create_email(List<Person>, string, string);
	string lower_case(string);
	bool isNumber(const string& str);

};

