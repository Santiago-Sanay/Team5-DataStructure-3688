/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#include "Operation.h"
#include <string>
using namespace std;
void Operation::wax(Calendar calendar)
{
	string vect[100];
	for (int i = 0; i < 100; i++) 
	{
		vect[i] = "0";
	}
	calendar.set_date(vect);
}
int Operation::calculate_day(string date)
{
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 9));

	int month1 = 0;
	if (month == 1 || month == 10) 
	{
		month1 = 0;
	}
	else {
		if (month == 2 || month == 13 || month == 11) {
			month1 = 3;
		}
		else {
			if (month == 4 || month == 7 ) {
				month1 = 6;
			}
			else {
				if (month == 5 ) {
					month1 = 1;
				}
				else {
					if (month == 6) {
						month1 = 4;
					}
					else {
						if (month == 8) {
							month1 = 2;
						}
						else {
							month1 = 5;
						}
					}
				}

			}
		}
	}
	int century = 0;
	if (year <= 1999) {
		century = 0;
	}
	else {
		if (year <= 2099 && year > 1999) {
			century = 6;
		}
	}
	int year1 = year % 100;
	int zeller_sum = day + month1 + year1 + (year1 / 4) + century;
	
	int day_week = zeller_sum % 7;
	return day_week;
}
void Operation::date_vector(string date, int dues, Calendar& calendar)
{
	string* vect = calendar.get_date();

	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 9));
	string day1;
	string month1;
	string year1;
	if (day < 10) {
		day1 = "0" + to_string(day);
	}
	else {
		day1 = to_string(day);
	}
	for (int i = 0; i < dues; i++) {
		if (month < 10) {
			month1 = "0" + to_string(month);
		}
		else {
			month1 = to_string(month);
		}
		year1 = "" + to_string(year);
		vect[i] = day1 + "-" + month1 + "-" + year1;
		month = month + 1;
		if (month == 13) {
			year = year + 1;
			month = 1;
		}
	}
	for (int i = 0; i < dues; i++) {
		vect[i] = set_valid_date(vect[i]);
	}
	set_weekend(dues, vect);
}



string Operation::set_valid_date(string date)
{
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 9));
	string day1;
	string month1;
	string year1;
	if (month > 12) {
		month = 12;

	}

	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
		day = 31;

	}
	else {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			day = 30;
		}
		else {
			if (year % 4 == 0 && day > 29 && month == 2) {
				day = 29;
			}
			else {
				if (year % 4 != 0 && day > 28 && month == 2) {
					day = 28;
				}
			}
		}

	}
	if (month < 10) {
		month1 = "0" + to_string(month);
	}
	else {
		month1 = to_string(month);
	}
	if (day < 10) {
		day1 = "0" + to_string(day);
	}
	else {
		day1 = to_string(day);
	}
	date = day1 + "-" + month1 + "-" + to_string(year);
	return date;
}

void Operation::print_calendar(int dues, string vect[100])
{
	for (int i = 0; i < dues; i++) {
		cout << i + 1 << " " << vect[i] << endl;
	}
}

bool Operation::check_fds(string date)
{
	bool fds = false;
	if (calculate_day(date) == 6 || calculate_day(date) == 0) {
		fds = true;
	}
	return fds;
}



void Operation::set_weekend(int dues, string vect[100])
{
	bool state = false;
	for (int i = 0; i < dues; i++) {

		while (check_fds(vect[i]) || check_holiday(vect[i])) {
			vect[i] = add_day(vect[i]);

		}

	}

}

bool Operation::check_holiday(string date)
{
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	string day1;
	string month1;
	string holiday[15];
	holiday[0] = "01-01";
	holiday[1] = "15-02";
	holiday[2] = "16-02";
	holiday[3] = "02-04";
	holiday[4] = "01-05";
	holiday[5] = "28-05";
	holiday[6] = "25-07";
	holiday[7] = "10-08";
	holiday[8] = "09-10";
	holiday[9] = "02-11";
	holiday[10] = "03-11";
	holiday[11] = "06-12";
	holiday[12] = "24-12";
	holiday[13] = "25-12";
	holiday[14] = "31-12";
	bool state = false;

	if (month < 10) {
		month1 = "0" + to_string(month);
	}
	else {
		month1 = to_string(month);
	}
	if (day < 10) {
		day1 = "0" + to_string(day);
	}
	else {
		day1 = to_string(day);
	}
	string date_verify = day1 + "-" + month1;

	for (int i = 0; i < 20; i++) {
		if (date_verify == holiday[i]) {
			state = true;


		}
	}

	return state;
}
string Operation::add_day(string date)
{
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 9));
	string day1;
	string month1;
	string year1;
	day = day + 1;


	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
		day = 1;
		month = month + 1;


	}
	else {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			day = 1;
			month = month + 1;
		}
		else {
			if (year % 4 == 0 && day > 29 && month == 2) {
				day = 1;
				month = month + 1;
			}
			else {
				if (year % 4 != 0 && day > 28 && month == 2) {
					day = 1;
					month = month + 1;
				}
			}
		}

	}
	if (month > 12) {
		month = 1;
		year = year + 1;

	}
	if (month < 10) {
		month1 = "0" + to_string(month);
	}
	else {
		month1 = to_string(month);
	}
	if (day < 10) {
		day1 = "0" + to_string(day);
	}
	else {
		day1 = to_string(day);
	}
	date = day1 + "-" + month1 + "-" + to_string(year);
	return date;
}

bool Operation::valid_date(string date1)
{
	int cont = 0;
	if (date1.length() != 10) {
		return false;
	}
	if (stoi(date1.substr(3, 2))>12) {
		return false;
	}
	if (date1.substr(2, 1).find('-', 0) == 0) {
		cont++;
	}
	if (date1.substr(5, 1).find('-', 0) == 0) {
		cont++;
	}
	if (isNumber(date1.substr(0, 2))) {
		cont++;
	}
	if (isNumber(date1.substr(3, 2))) {
		cont++;
	}
	if (isNumber(date1.substr(6, 4))) {
		cont++;
	}
	if (cont == 5) {
		return true;
	}
	return false;
}
bool Operation::isNumber(const string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}


 
