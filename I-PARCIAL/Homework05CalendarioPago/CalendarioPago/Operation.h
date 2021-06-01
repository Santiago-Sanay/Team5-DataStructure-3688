#pragma once
#include "Calendar.h"
#include <iostream>
using namespace std;
class Operation
{
public:
	void wax(Calendar);
	int calculate_day(string);
	void date_vector(string, int, Calendar&);
	string set_valid_date(string);
	void print_calendar(int, string[100]);
	void set_weekend(int, string[100]);
	bool check_holiday(string);
	bool check_fds(string);
	string add_day(string);

};


