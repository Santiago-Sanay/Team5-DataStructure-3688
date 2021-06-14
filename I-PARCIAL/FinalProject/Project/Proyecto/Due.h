#pragma once
#include <string>
using namespace std;
class Due
{
private:
	string date;
	string weekday;
	double mounthly_amount;
public:
	Due(string, string, double);
	Due() = default;
	string get_date();
	void set_date(string);
	string get_weekday();
	void set_weekday(string);
	double get_mounthly_amount();
	void set_mounthly_amount(double);
	string to_string1();
	Due from_string_to_due(string);


};


