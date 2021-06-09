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
#include <iostream> 

using namespace std;
class Person
{
private:
	string name;
	string last_name;
	string id;
	string birth_date;
	int age;
	string address;
	string email;
public:
	Person(string, string, string, string, int, string, string);
	void set_name(string);
	string get_name();
	void set_last_name(string);
	string get_last_name();
	void set_id(string);
	string get_id();
	void set_birth_date(string);
	string get_birth_date();
	void set_address(string);
	string get_address();
	void set_email(string);
	string get_email();
	void set_age(int);
	int get_age();

};

