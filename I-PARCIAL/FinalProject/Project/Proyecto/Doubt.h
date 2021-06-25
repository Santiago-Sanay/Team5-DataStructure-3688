#pragma once

#include "Due.h"
#include "Person.h"
using namespace std;
class Doubt
{
private:
	string id_person;
	double initial_amount{0.0}; //PRESTAMO
	string initial_date; // FECHA DE PRIMER PAGO
	int payment_time{0}; // NUMERO DE CUETOS
	string rate_of_interest; // TIPO DE INTERES
	double interest{0.0}; // PORCENTAJE ANUAL 
	double final_amount{0.0}; // SUMA EL CREDITO MAS EL INTERES.
public:
	Doubt(string, double, string, int, string, double);
	Doubt() = default;
	double get_initial_amount();

	void set_initial_amount(double);
	int get_payment_time();
	void set_payment_time(int);
	string get_rate_of_interest();
	void set_rate_of_interest(string);
	double get_interest();
	void set_interest(double);
	void set_final_amount(double);
	double get_final_amount();
	string get_id_person();
	void set_id_person(string);
	void set_initial_date(string);
	string get_initial_date();

};