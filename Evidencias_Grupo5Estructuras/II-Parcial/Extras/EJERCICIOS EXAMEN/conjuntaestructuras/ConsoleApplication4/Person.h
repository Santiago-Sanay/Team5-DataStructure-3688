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
	string email;
	string cesar_code;
public:
	Person(string , string , string, string,string );
	Person()=default;
	void set_name(string);
	string get_name();
	void set_last_name(string);
	string get_last_name();
	void set_id(string);
	string get_id();
	void set_email(string);
	string get_email();
	void set_cesar_code(string);
	string get_cesar_code();
	string to_string_person();
	


};

