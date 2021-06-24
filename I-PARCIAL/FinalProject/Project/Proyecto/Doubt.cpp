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
	List<Due> dues;
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
	List<Due> dues;
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
	List<Due> dues;;
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
	List<Due> dues;
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
	List<Due> dues;
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

string Doubt::get_id_person()
{
	return this->id_person;
}

void Doubt::set_id_person(string new_id_person)
{
	this->id_person = new_id_person;
}

string Doubt::to_string1()
{
	/*
	double initial_amount;
	string initial_date;
	int payment_time;
	string rate_of_interest;
	double interest;
	List<Due> dues;
	double final_amount;
	string cad = "{\"";

	cad += "initial_amount\"";

	cad += ":";
	//cad += "\"";
	cad += to_string(initial_amount);
	//cad += "\"";
	cad += ",";
	cad += "\"";
	cad += "initial_date";
	cad += "\"";
	cad += ":";
	cad += "\"";
	cad += initial_date;
	cad += "\"";
	cad += ",";
	cad += "\"";
	cad += "payment_time";
	cad += "\"";
	cad += ":";
	//cad += "\"";
	cad += to_string(payment_time);
	//cad += "\"";
	cad += ",";
	cad += "\"";
	cad += "rate_of_interest";
	cad += "\"";
	cad += ":";
	cad += "\"";
	cad += rate_of_interest;
	cad += "\"";
	cad += ",";
	cad += "\"";
	cad += "final_amount\"";

	cad += ":";
	//cad += "\"";
	cad += to_string(final_amount);
	//cad += "\"";
	cad += ",";
	cad += "\"";
	cad += "dues";
	cad += "\"";
	cad += ":";
	cad += "[";
	cad += dues.to_string_list();
	cad += "]";
	//cad += "\"";
	//cad += to_string(mounthly_amount);
	cad += "}";
	return cad;*/
	return string();
}

Doubt Doubt::from_string_to_doubt(string data)
{
	/*string a, b, c;
	string date, weekday, mounthly_amount1;
	int pos1 = 0;
	int pos2 = 0;
	int pos3 = 0;
	pos1 = data.find(",", 0);
	pos2 = data.find(",", pos1 + 1);
	pos3 = data.find("}", pos2 + 1);
	a = data.substr(0, pos1);
	b = data.substr(pos1 + 1, pos2 - pos1 - 1);
	c = data.substr(pos2 + 1, pos3 - pos2 - 1);
	pos1 = a.find(":", 0);
	date = a.substr(pos1 + 1, a.length() - pos1 - 1);
	date = date.replace(date.find("\"", 0), 1, "");
	date = date.replace(date.find("\"", 0), 1, "");
	pos2 = b.find(":", 0);
	weekday = b.substr(pos2 + 1, b.length() - pos2 - 1);
	weekday = weekday.replace(weekday.find("\"", 0), 1, "");
	weekday = weekday.replace(weekday.find("\"", 0), 1, "");
	pos3 = c.find(":", 0);
	mounthly_amount1 = c.substr(pos3 + 1, c.length() - pos3 - 1);

	cout << date << endl;
	cout << weekday << endl;
	cout << mounthly_amount1 << endl;

	return Due(date, weekday, stod(mounthly_amount1));*/
	return Doubt();
}
