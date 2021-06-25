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

#include "Doubt.h"
#include "CalendarOperation.h"
#include <string>

Doubt::Doubt(string new_id_person, double new_initial_amount, string new_initial_date, int new_payment_time, string new_rate_of_interest, double new_interest)
{
	this->id_person = new_id_person;
	this->initial_amount = new_initial_amount;
	this->initial_date = new_initial_date;
	this->payment_time = new_payment_time;
	this->rate_of_interest = new_rate_of_interest;
	this->interest = new_interest;
	CalendarOperation op;
	LinkedList<Due> dues;
	if (rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(new_initial_date, new_initial_amount, new_payment_time, new_interest, dues, this->final_amount);
	}
	else {
		op.french_amortization(new_initial_date, new_initial_amount, new_payment_time, new_interest, dues, this->final_amount);
	}

}

double Doubt::get_initial_amount()
{
	return initial_amount;
}

void Doubt::set_initial_amount(double new_initial_amount)
{
	this->initial_amount = new_initial_amount;
	CalendarOperation op;
	LinkedList<Due> dues;
	if (this->rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(this->initial_date, new_initial_amount, this->payment_time, this->interest, dues, this->final_amount);
	}
	else {
		op.french_amortization(this->initial_date, new_initial_amount, this->payment_time, this->interest, dues, this->final_amount);
	}
}

int Doubt::get_payment_time()
{
	return payment_time;
}

void Doubt::set_payment_time(int new_payment_time)
{
	this->payment_time = new_payment_time;
	CalendarOperation op;
	LinkedList<Due> dues;;
	if (this->rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(this->initial_date, this->initial_amount, new_payment_time, this->interest, dues, this->final_amount);
	}
	else {
		op.french_amortization(this->initial_date, this->initial_amount, new_payment_time, this->interest, dues, this->final_amount);
	}

}

string Doubt::get_rate_of_interest()
{
	return rate_of_interest;
}

void Doubt::set_rate_of_interest(string new_rate_of_interest)
{
	this->rate_of_interest = new_rate_of_interest;
	CalendarOperation op;
	LinkedList<Due> dues;
	if (this->rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(this->initial_date, this->initial_amount, this->payment_time, this->interest, dues, this->final_amount);
	}
	else {
		op.french_amortization(this->initial_date, this->initial_amount, this->payment_time, this->interest, dues, this->final_amount);
	}
}

double Doubt::get_interest()
{
	return interest;
}

void Doubt::set_interest(double new_interest)
{
	this->interest = new_interest;
	CalendarOperation op;
	LinkedList<Due> dues;
	if (this->rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(this->initial_date, this->initial_amount, this->payment_time, this->interest, dues, this->final_amount);
	}
	else {
		op.french_amortization(this->initial_date, this->initial_amount, this->payment_time, this->interest, dues, this->final_amount);
	}
}

double Doubt::get_final_amount()
{
	return final_amount;
}
void Doubt::set_final_amount(double new_final_aomunt)
{
	this->final_amount = new_final_aomunt;
}

string Doubt::get_id_person()
{
	return this->id_person;
}

void Doubt::set_id_person(string new_id_person)
{
	this->id_person = new_id_person;
}

void Doubt::set_initial_date(string new_initial_date )
{
	this->initial_date = new_initial_date;
}

string Doubt::get_initial_date()
{
	return this->initial_date;
}


