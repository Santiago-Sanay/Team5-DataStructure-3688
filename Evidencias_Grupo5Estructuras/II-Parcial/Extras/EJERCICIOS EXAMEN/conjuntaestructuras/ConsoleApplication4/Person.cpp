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

Person::Person(string _name, string _last_name, string _id, string _email, string new_cesar_code) {
	this->name = _name;
	this->last_name = _last_name;
	this->id = _id;
	
	this->email = _email;
	this->cesar_code = new_cesar_code;
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




void Person::set_email(string _email)
{
	this->email = _email;
}

string Person::get_email()
{
	return email;
}

void Person::set_cesar_code(string new_cesar_code)
{
	this->cesar_code = new_cesar_code;
}

string Person::get_cesar_code()
{
	return cesar_code;
}

string Person::to_string_person()
{
	string data = "NOMBRE: " + name + " APELLIDO: " + this->last_name + " ID: " + id + " EMAIL: " + email + " CODIFICACION: " + cesar_code;
	return data;
}



