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
#include "List.h"
#include "Person.h"
class Operation_person
{
public:
	
	string create_email(List<Person>, string,string);
	static string lower_case(string);
	bool isNumber(const string& str);
	bool validate_id(string _id);
	long cifrar(string,int);
	int cesar(int,int);
	long ingreso(const char*,int);
};

