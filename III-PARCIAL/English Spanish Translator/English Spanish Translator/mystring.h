#pragma once
#include <string>
using namespace std;
class mystring
{
public:
	char to_lower( char);
	char to_upper(char);
	string capitalize(string);
	string minusculize(string);
	int find_character(string, char, int);
	int find(string cad, string cad_to_find, int position_initial);
	int length(string);
	string substract(string cad, int position_initial, int number_character);
	bool is_equal(string, string);
	int atoi(char);
	int stoi(string);
	long stol(string);
	double stod(string);
	string reverse(string);
	bool is_number(string);
	double potencia(double num, double pot);
};

