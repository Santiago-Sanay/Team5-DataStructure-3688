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
#include <cstring>
#include <string>
Person::Person(string _name, string _last_name, string _id, string _birth_date, int _age, string _address, string _email) {
	this->name = _name;
	this->last_name = _last_name;
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

string Person::to_string_person()
{
	string data;
	string age1 = to_string(this->age);
	data= name+","+last_name+","+id + ","+birth_date + ","+age1+"," +address + ","+email;
	
	return data;
}

Person Person::deserialization_person(string data)
{
	string name1;
	string last_name1;
	string id1;
	string birth_date1;
	int age1;
	string address1;
	string email1;
	int pos1,pos2,pos3,pos4,pos5,pos6,pos7;
	pos1 = data.find(",", 0);
	name1 = data.substr(0, pos1);
	cout << name1<<endl;
	pos2= data.find(",", pos1+1);

	last_name1= data.substr(pos1+1, pos2-pos1-1);
	cout << last_name1<<endl;
	pos3 = data.find(",", pos2 + 1);

	id1 = data.substr(pos2 + 1, pos3 - pos2 - 1);
	cout << id1 << endl;
	pos4 = data.find(",", pos3 + 1);

	birth_date1 = data.substr(pos3 + 1, pos4 - pos3 - 1);
	cout << birth_date1 << endl;
	pos5 = data.find(",", pos4 + 1);

	age1 = stoi(data.substr(pos4 + 1, pos5 - pos4 - 1));
	cout << age1 << endl;
	pos6 = data.find(",", pos5 + 1);

	address1 = data.substr(pos5 + 1, pos6 - pos5 - 1);
	cout << address1 << endl;
	pos7 = data.find(",", pos6 + 1);

	email1 = data.substr(pos6 + 1, pos7 - pos6 - 1);
	cout << email1 << endl;
	return Person(name1, last_name1, id1, birth_date1, age1, address1, email1);
	
}
