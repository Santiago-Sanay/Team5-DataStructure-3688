#pragma once

#include "List.h"
#include "Due.h"
#include "Person.h"
using namespace std;
class Doubt
{
private:
	string id_person;
	double initial_amount;
	string initial_date;
	int payment_time;
	string rate_of_interest;
	double interest;
	double final_amount;
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

	double get_final_amount();
	string get_id_person();
	void set_id_person(string);
	string to_string1();
	Doubt from_string_to_doubt(string);
	string to_string_doubt();
	Doubt deserialization_doubt(string);



};