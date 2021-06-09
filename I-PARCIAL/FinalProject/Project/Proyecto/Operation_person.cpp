﻿/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
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

#include "Operation_person.h"
#include <time.h>
bool Operation_person::validate_id(string _id) {
	int tam = _id.size();
	for (int i = 0; i < tam; i++)
	{
		if (_id[i] <= 40 || _id[i] >= 57) {
			return true;
		}
	}
	return false;
}
string Operation_person::get_actual_date()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%e-%m-%Y", &tstruct);
	return buf;
}
int Operation_person::calculate_age(string birth_date_) {
	int day = stoi(birth_date_.substr(0, 2));
	int month = stoi(birth_date_.substr(3, 2));
	int year = stoi(birth_date_.substr(6, 9));
	int age;
	string date = Operation_person::get_actual_date();
	int day_actual = stoi(date.substr(0, 2));
	int month_actual = stoi(date.substr(3, 2));
	int year_actual = stoi(date.substr(6, 9));
	if (day_actual < day) {
		day_actual = day + 30;
		month_actual -= 1;
	}
	if (month_actual < month) {
		month_actual += 12;
		year_actual -= 1;
	}
	age = year_actual - year;
	return age;
}
Person Operation_person::data_entry() {
	string _name;
	string _last_name;
	string _birth_date;
	string _address;
	string _id1;
	int _age;
	cout << "Ingrese sus nombres:";
	cin >> _name;
	while(getchar()!='\n');
	cout << "Ingrese sus apellidos:";
	cin >> _last_name;
	while (getchar() != '\n');
	cout << "Ingrese su direccion domiciliaria:";
	cin >> _address;
	while (getchar() != '\n');
	cout << "Ingrese la fecha de nacimiento:";
	cin >> _birth_date;
	do {
		while (getchar() != '\n');
		cout << "Ingrese su id:";
		cin >> _id1;
	} while (Operation_person::validate_id(_id1) || _id1.length()!=10);
	_age = Operation_person::calculate_age(_birth_date);
	Person person(_name, _last_name, _id1,_birth_date, _age, _address, "email");
	return person;
}

