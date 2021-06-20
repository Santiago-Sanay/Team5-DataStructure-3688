#include "Doubt.h"
#include "CalendarOperation.h"

Doubt::Doubt(double new_initial_amount, string new_initial_date, int new_payment_time, string new_rate_of_interest, double new_interest)
{
	this->initial_amount = new_initial_amount;
	this->initial_date = new_initial_date;
	this->payment_time = new_payment_time;
	this->rate_of_interest = new_rate_of_interest;
	this->interest = new_interest;
	CalendarOperation op;
	if (rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(new_initial_date, new_initial_amount, new_payment_time, new_interest, this->dues, this->final_amount);
	}
	else {
		op.french_amortization(new_initial_date, new_initial_amount, new_payment_time, new_interest, this->dues, this->final_amount);
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
	this->dues.vaciar_lista();
	if (this->rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(this->initial_date, new_initial_amount, this->payment_time, this->interest, this->dues, this->final_amount);
	}
	else {
		op.french_amortization(this->initial_date, new_initial_amount, this->payment_time, this->interest, this->dues, this->final_amount);
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
	this->dues.vaciar_lista();
	if (this->rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(this->initial_date, this->initial_amount, new_payment_time, this->interest, this->dues, this->final_amount);
	}
	else {
		op.french_amortization(this->initial_date, this->initial_amount, new_payment_time, this->interest, this->dues, this->final_amount);
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
	this->dues.vaciar_lista();
	if (this->rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(this->initial_date, this->initial_amount, this->payment_time, this->interest, this->dues, this->final_amount);
	}
	else {
		op.french_amortization(this->initial_date, this->initial_amount, this->payment_time, this->interest, this->dues, this->final_amount);
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
	this->dues.vaciar_lista();
	if (this->rate_of_interest.compare("ALEMAN") == 0) {
		op.german_amortization(this->initial_date, this->initial_amount, this->payment_time, this->interest, this->dues, this->final_amount);
	}
	else {
		op.french_amortization(this->initial_date, this->initial_amount, this->payment_time, this->interest, this->dues, this->final_amount);
	}
}

List<Due> Doubt::get_dues()
{
	return dues;
}

double Doubt::get_final_amount()
{
	return final_amount;
}

string Doubt::to_string1()
{
	return string();
}

Doubt Doubt::from_string_to_doubt(string)
{
	return Doubt();
}
