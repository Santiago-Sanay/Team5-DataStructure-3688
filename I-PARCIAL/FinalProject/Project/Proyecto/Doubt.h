#pragma once

#include "List.h"
#include "Due.h"
using namespace std;
class Doubt
{
private:
	double initial_amount;
	string initial_date;
	int payment_time;
	string rate_of_interest;
	double interest;
	List<Due> dues;
	double final_amount;
public:
	Doubt(double, string, int, string, double);
	Doubt() = default;
	double get_initial_amount();

	void set_initial_amount(double);
	int get_payment_time();
	void set_payment_time(int);
	string get_rate_of_interest();
	void set_rate_of_interest(string);
	double get_interest();
	void set_interest(double);
	List<Due> get_dues();
	double get_final_amount();
	string to_string1();
	Doubt from_string_to_doubt(string);



};