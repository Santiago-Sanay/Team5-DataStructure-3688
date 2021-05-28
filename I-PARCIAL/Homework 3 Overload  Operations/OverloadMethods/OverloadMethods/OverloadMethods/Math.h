#pragma once
#include "Vector.h"
#include <cmath>
#include <iomanip>
#include <iostream>
class Math
{

public:
	//Theo
	Vector operator+(Vector*);
	Vector operator-(Vector*);
	double operator*(Vector*);
	//Yuli
	int operator++(int);
	int operator--(int);
	double operator/=(Vector*);
	//Santiago
	std::ostream& operator<<(std::ostream&, Vector*);
	Vector operator>(Vector&);
	Vector operator<(Vector&);
	//Alex
	bool operator==(Vector&);
	Vector operator^(Vector&);
	bool operator!=(Vector&);
	//Junior
	int operator<=(Vector&);
	Vector operator>=(Vector&);
	Vector operator<<=(Vector&);


};
