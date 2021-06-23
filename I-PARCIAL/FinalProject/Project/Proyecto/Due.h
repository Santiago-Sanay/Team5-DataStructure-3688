#pragma once
#include <string>
using namespace std;
class Due
{
private:
	string date;
	string weekday;
	double mounthly_amount;
	double interest;
	double capital;
public:
	Due(string, string, double, double, double);
	Due() = default;
	string get_date();
	void set_date(string);
	string get_weekday();
	void set_weekday(string);
	double get_mounthly_amount();
	double get_interest();
	double get_capital();
	void set_mounthly_amount(double);
	void set_interest(double);
	void set_capital(double);
	string to_string1();
	Due from_string_to_due(string);


};


