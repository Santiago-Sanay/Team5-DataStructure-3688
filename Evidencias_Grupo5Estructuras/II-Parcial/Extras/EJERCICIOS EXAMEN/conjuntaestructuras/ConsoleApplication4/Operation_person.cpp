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
#include <Math.h>
bool Operation_person::validate_id(string _id)
{
	vector<int> v1;
	int _id_num = stoi(_id, nullptr, 10);
	int temp;
	int sum_par = 0;
	int sum_impar = 0;
	int sum;
	while (_id_num > 0)
	{
		int temp = _id_num % 10;
		_id_num /= 10;
		v1.push_back(temp);
	}
	for (int i = 1; i < _id.size(); i++)
	{
		if (i % 2) {
			temp = v1.at(i) * 2;
			if (temp > 9) {
				temp -= 9;
			}
			sum_par += temp;
		}
		else {
			sum_impar += v1.at(i);
		}
	}
	sum = sum_par + sum_impar;
	if ((10 - (sum % 10)) == v1.front()) {
		return true;
	}
	else {
		cout << "\nLa cedula ingresada es invalida" << endl;
		return false;
	}
}

long Operation_person::cifrar(string num,int cod)
{
	
	if (num.length()<=1) {
		return 0;
	}
	
	
	return cesar(stoi(num.substr(0,1)),cod) * pow(10, num.length()-2) +cifrar(num.substr(1,num.length()-1),cod);
}

int Operation_person::cesar(int num,int cod)
{
	int dig = 0;
	dig = num + cod;
	if (dig > 9) {
		dig =dig- 9;
	}
	
	return dig;
}


long Operation_person::ingreso(const char* msj,const int dim) {
	char dato[11];
	char c;
	int i = 0;
	printf("%s", msj);
	cout << endl;
	while ((c = _getch()) != 13 && i<dim) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato[i++] = c;
		}
	}
	//cout << i << endl;
	dato[i] = '\0';
	long date;
	date = atol(dato);
	return date;
}


string Operation_person::create_email(List<Person> people, string name1, string last)
{
	string name, last_name;
	name = lower_case(name1);

	last_name = lower_case(last);

	string email;
	email += name.substr(0, 1);

	email += name.substr(name.find(" ", 0) + 1, 1);
	//cout << last_name.find(" ", 0) << endl;

	if (last_name.find(" ", 0) < last_name.length()) {
		email += last_name.substr(0, last_name.find(" ", 0));
	}
	else {
		email += last_name;
	}


	string domain = "@espe.edu.ec";
	string email_temp, useremail;
	Nodo<Person>* person1 = people.get_primero();
	int positiondomain = 0;
	int last_digit = 0;
	while (person1) {
		email_temp = person1->get_dato().get_email();
		positiondomain = email_temp.find("@", 0);
		useremail = email_temp.substr(0, positiondomain);

		if (useremail.length() == email.length()) {

			if (useremail.find(email, 0) == 0) {
				if (isNumber(useremail.substr(useremail.length() - 1, 1))) {
					last_digit = stoi(email.substr(email.length() - 1, 1));
					last_digit = last_digit + 1;
					email = email.substr(0, email.length() - 1) + to_string(last_digit);
				}
				else {

					email += "1";

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
