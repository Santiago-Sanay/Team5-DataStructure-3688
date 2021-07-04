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
	int find(string, string, int);
	int length(string);
	string substract(string, int, int);
	bool is_equal(string, string);
	int atoi(char);
	int stoi(string);
	long stol(string);
	string reverse(string);
};

