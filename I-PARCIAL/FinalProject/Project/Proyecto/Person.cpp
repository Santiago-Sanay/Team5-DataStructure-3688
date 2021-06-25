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
*FECHA DE CREACION : 15 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 25 DE JUNIO 2021
*/

#include "Person.h"

Person::Person(std::string id, std::string name,
	std::string last_name, std::string date_of_birth, std::string number, std::string addres)
	: id_(id), name_(name), last_name_(last_name), date_of_birth_(date_of_birth), number_phone_(number),addres_(addres)
{

}

void Person::set_name(std::string name)
{
	this->name_ = name;
}

void Person::set_last_name(std::string last_name)
{
	this->last_name_ = last_name;
}

void Person::set_addres(std::string adress)
{
	this->addres_ = adress;
}

void Person::set_number(std::string phone)
{
	this->number_phone_= phone;
}

void Person::set_email(std::string email)
{
	this->email_ = email;
}

void Person::set_id(std::string id)
{
	this->id_ = id;
}

void Person::set_age(int age)
{
	this->age_ = age;
}

void Person::set_date_of_birth(std::string date_of_birth)
{
	this->date_of_birth_ = date_of_birth;
}

std::string Person::get_name()
{
	return name_;
}

std::string Person::get_last_name()
{
	return last_name_;
}

std::string Person::get_addres()
{
	return addres_;
}

std::string Person::get_number()
{
	return number_phone_;
}

std::string Person::get_email()
{
	return email_;
}

std::string Person::get_id()
{
	return id_;
}

std::string Person::get_date_of_birth()
{
	return date_of_birth_;
}

int Person::get_age()
{
	return age_;
}