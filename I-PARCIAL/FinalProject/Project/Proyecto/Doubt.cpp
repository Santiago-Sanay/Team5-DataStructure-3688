
#include "Doubt.h"
double initial_amount;
int payment_time;
string rate_of_interest;
double interest;
Lista<Due> dues;
double final_amount;
Doubt::Doubt(double new_initial_amount, int new_payment_time, string new_rate_of_interest, double new_interest)
{
	this->initial_amount = new_initial_amount;
	this->payment_time = new_payment_time;
	this->rate_of_interest = new_rate_of_interest;
	this->interest = new_interest;
	this->dues =
		this->
}

double Doubt::get_initial_amount()
{
	return 0.0;
}

void Doubt::set_initial_amount(double)
{
}

int Doubt::get_payment_time()
{
	return 0;
}

void Doubt::set_payment_time(int)
{
}

string Doubt::get_rate_of_interest()
{
	return string();
}

void Doubt::set_rate_of_interest(string)
{
}

double Doubt::get_interest()
{
	return 0.0;
}

void Doubt::set_interest(double)
{
}

Lista<Due> Doubt::get_dues()
{
	return Lista<Due>();
}

double Doubt::get_final_amount()
{
	return 0.0;
}

string Doubt::to_string1()
{
	return string();
}

Doubt Doubt::from_string_to_doubt(string)
{
	return Doubt();
}
