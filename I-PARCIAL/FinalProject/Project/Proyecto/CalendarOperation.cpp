
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
#include "CalendarOperation.h"
#include <string>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Operation.h"
using namespace std;
string* CalendarOperation::segment(int dim)
{
	string* p = new string[dim];

	return p;
}
void CalendarOperation::wax(string* array, int dues)
{


	for (int i = 0; i < dues; i++)
	{
		*(array + i) = "0";

	}

}
int CalendarOperation::calculate_day(string date)
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
			if (month == 4 || month == 7) {
				month1 = 6;
			}
			else {
				if (month == 5) {
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
void CalendarOperation::date_vector(string date, int dues, Calendar calendar)
{


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
		//cout << "si entra" << endl;
		*(calendar.get_date() + i) = day1 + "-" + month1 + "-" + year1;
		month = month + 1;
		if (month == 13) {
			year = year + 1;
			month = 1;
		}
	}

	for (int i = 0; i < dues; i++) {
		*(calendar.get_date() + i) = set_valid_date(*(calendar.get_date() + i));
	}
	set_weekend(dues, calendar.get_date());
}



string CalendarOperation::set_valid_date(string date)
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

void CalendarOperation::print_calendar(int dues, string* vect)
{
	for (int i = 0; i < dues; i++) {
		cout << i + 1 << " " << *(vect + i) << endl;
	}
}

bool CalendarOperation::check_fds(string date)
{
	bool fds = false;
	if (calculate_day(date) == 6 || calculate_day(date) == 0) {
		fds = true;
	}
	return fds;
}



void CalendarOperation::set_weekend(int dues, string* vect)
{
	bool state = false;
	for (int i = 0; i < dues; i++) {

		while (check_fds(vect[i]) || check_holiday(vect[i])) {
			*(vect + i) = add_day(*(vect + i));

		}

	}

}

bool CalendarOperation::check_holiday(string date)
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
string CalendarOperation::add_day(string date)
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

string CalendarOperation::weekday_name(string day)
{
	int number_day = 0;
	string day_name;
	number_day = calculate_day(day);
	switch (number_day) {
	case 1:
		day_name = "LUNES";
		break;
	case 2:
		day_name = "MARTES";
		break;
	case 3:
		day_name = "MIERCOLES";
		break;
	case 4:
		day_name = "JUEVES";
		break;
	case 5:
		day_name = "VIERNES";
		break;
	case 6:
		day_name = "SABADO";
		break;
	default:
		day_name = "DOMINGO";
		break;
	}
	return day_name;
}

double** CalendarOperation::segment2(int rows, int columns)
{
	Matrix<double> matrix;
	int j;
	matrix.set_matrix((double**)malloc(columns * sizeof(double*)));
	for (j = 0; j < rows; j++) {
		*(matrix.get_matrix() + j) = (double*)malloc(columns * sizeof(double));
	}
	
	return matrix.get_matrix();
	
}

void CalendarOperation::french_amortization(string date, double initial_amount, int payment_time, double interest, List<Due> &dues, double& final_amount)
{
	cout << "si entra jshajksh" << endl;
	Calendar calendar;
	string* calendar_vector = new string[payment_time];
	calendar.set_date(calendar_vector);
	date_vector(date, payment_time, calendar);
	
	string date1;
	string weekday;
	double mounthly_amount;
	mounthly_amount = (initial_amount * (interest / 100) / 12) / (1 - pow(((interest / 100) + 1), -(payment_time)));

	Due due;
	for (int j = 0; j < payment_time; j++) {
		date1 = *(calendar.get_date() + j);
		
		weekday = weekday_name(date1);
		
		due.set_date(date1);
		due.set_weekday(weekday);
		due.set_mounthly_amount(mounthly_amount);
		
		dues.insertar_por_la_cola(due);

	}
	final_amount = payment_time * mounthly_amount;
	
}

void CalendarOperation::german_amortization(string date, double initial_amount, int payment_time, double interest, List<Due>& dues, double& final_amount)
{
	cout << "si entra jshajksh" << endl;
	Calendar calendar;
	string* calendar_vector = new string[payment_time];
	calendar.set_date(calendar_vector);
	date_vector(date, payment_time, calendar);

	string date1;
	string weekday;
	double mounthly_amount=0;
	Due due;

	double  capital=0,monthly_due = 0;
	capital = initial_amount / payment_time;
	
	double balance = initial_amount;
	double mountly_interest = 0;
	double sum = 0;
	for (int j = 0; j < payment_time; j++) {
		mountly_interest = balance * interest / 100;
		mounthly_amount = capital+ mountly_interest;
		balance = balance - capital;
		//asign to list of dues
		date1 = *(calendar.get_date() + j);
		weekday = weekday_name(date1);
		due.set_date(date1);
		due.set_weekday(weekday);
		due.set_mounthly_amount(mounthly_amount);
		dues.insertar_por_la_cola(due);
		sum = sum + mounthly_amount;
	}
	cout << sum << endl;
	final_amount = sum;
		
}

void CalendarOperation::payment_table(string date, double initial_amount, int payment_time, string rate_of_interest, double interest, List<Due> dues)
{
	Calendar calendar;
	string* calendar_vector = new string[payment_time];
	calendar.set_date(calendar_vector);
	date_vector(date, payment_time, calendar);
	Matrix<double> matrix;
	Operation<double> op;
	matrix.set_matrix(op.segmentar2(payment_time, 2));
	if (rate_of_interest.compare("ALEMAN") == 0) {
		//german_amortization(matrix, payment_time, interest, initial_amount);
	}
	else {
		//french_amortization(matrix, payment_time, interest, initial_amount);
	}
	string date1;
	string weekday;
	double mounthly_amount;
	Due due;
	for (int j = 0; j < payment_time; j++) {
		date1=*(calendar.get_date() + j);
		weekday = weekday_name(date1);
		mounthly_amount=*(*(matrix.get_matrix() + j) + 0);
		due.set_date(date1);
		due.set_weekday(weekday);
		due.set_mounthly_amount(mounthly_amount);
		dues.insertar_por_la_cola(due);
		
	}

}

double CalendarOperation::final_amount_payment(List<Due> dues)
{
	Nodo<Due>* temp = dues.get_primero();
	
	double final_amount=0;
	while (temp) {
		//final_amount = final_amount + double(temp->get_dato());
		temp = temp->get_siguiente();

	}
	return final_amount;
}


