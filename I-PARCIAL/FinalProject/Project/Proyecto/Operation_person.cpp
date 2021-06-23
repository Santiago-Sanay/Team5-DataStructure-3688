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

#include "Operation_person.h"
#include <time.h>
/*bool Operation_person::validate_id(string _id) {
	int tam = _id.size();
	for (int i = 0; i < tam; i++)
	{
		if (_id[i] <= 40 || _id[i] >= 57) {
			return true;
		}
	}
	return false;
}
/*string Operation_person::get_actual_date()
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
}*/
/*Person Operation_person::data_entry() {
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
}*/
string Operation_person::create_email(List<Person> people, string name1, string last)
{
	string name, last_name;
	name = lower_case(name1);
	cout << name << endl;
	last_name = lower_case(last);
	cout << last_name << endl;
	string email;
	email += name.substr(0, 1);
	cout << email << endl;
	email += name.substr(name.find(" ", 0) + 1, 1);
	cout << email << endl;
	if (last_name.find(" ", 0) < last_name.length()) {
		email += last_name.substr(last_name.find(" ", 0), 1);
	}
	else {
		email += last_name;
	}

	cout << email << endl;
	string domain = "@espe.edu.ec";
	string email_temp, useremail;
	Nodo<Person>* person1 = people.get_primero();
	int positiondomain = 0;
	int last_digit = 0;
	while (person1) {
		email_temp = person1->get_dato().get_email();
		positiondomain = email_temp.find("@", 0);
		useremail = email_temp.substr(positiondomain, positiondomain + 1);
		if (useremail.length() == email.length()) {
			if (useremail.find(email, 0)) {
				if (isNumber(useremail.substr(useremail.length()))) {
					last_digit = stoi(email.substr(email.length() - 1, 1));
					last_digit = last_digit + 1;
					email = email.substr(email.length() - 1, 0) + to_string(last_digit);
				}
				else {
					email = email + "1";
				}
			}
		}
		person1 = person1->get_siguiente();
	}
	return email += domain;

}

string Operation_person::lower_case(string cad)
{

	for (int i = 0; i < cad.length(); i++) cad[i] = tolower(cad[i]);
	return cad;

}
bool Operation_person::isNumber(const string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}

