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
	static Person data_entry();
	static string get_actual_date();
	static int calculate_age(string);
	static void create_email(Person);
<<<<<<< HEAD
	static bool validate_id(string);
=======
	static bool validate_id(string);*/
	string create_email(List<Person>, string, string);
	static string lower_case(string);
	bool isNumber(const string& str);
>>>>>>> f9a5fb61329db66b0a03b646b0e4eeda3f90ac9a
};

