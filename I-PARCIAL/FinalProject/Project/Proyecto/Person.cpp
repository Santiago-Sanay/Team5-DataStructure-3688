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

#include "Person.h"

Person::Person(string _name, string _last_name, string _id, string _birth_date, int _age, string _address, string _email) {
	this->name = _name;
	this->last_name = _name;
	this->id = _id;
	this->birth_date = _birth_date;
	this->age = _age;
	this->address = _address;
	this->email = _email;

}

void Person::set_name(string _name)
{
	this->name = _name;
}

string Person::get_name()
{
	return name;
}

void Person::set_last_name(string _last_name)
{
	this->last_name = _last_name;
}

string Person::get_last_name()
{
	return last_name;
}

void Person::set_id(string _id)
{
	this->id = _id;
}

string Person::get_id()
{
	return id;
}


void Person::set_birth_date(string _birth_date)
{
	this->birth_date = _birth_date;
}

string Person::get_birth_date()
{
	return birth_date;
}

void Person::set_address(string _address)
{
	this->address = _address;
}

string Person::get_address()
{
	return address;
}

void Person::set_email(string _email)
{
	this->email = _email;
}

string Person::get_email()
{
	return email;
}

void Person::set_age(int _age)
{
	this->age = _age;
}

int Person::get_age()
{
	return age;
}
