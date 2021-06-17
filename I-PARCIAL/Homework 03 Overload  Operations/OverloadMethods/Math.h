/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: SOBRECARGA DE OPERADORES
*FECHA DE CREACION : 26 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 28 DE MAYO 2021
*/
#pragma once
#include "Vector.h"
#include <cmath>
#include <iomanip>
#include <iostream>
class Math
{

public:
	//Theo
	//static Vector operator+(Vector&, Vector&);
	//static Vector operator-(Vector&, Vector&);
	//static double operator*(Vector&, Vector&);
	////Yuli
	//static Vector operator++(Vector&);
	//static Vector operator--(Vector&);
	//static double operator/=(Vector&, Vector&);
	//Santiago
	/*static Vector operator~(Vector&);*/
	/*static Vector operator>(Vector&, Vector&);*/
	//static Vector operator<(Vector&, Vector&);
	////Alex
	//static bool operator==(Vector&, Vector&);
	//static Vector operator^(Vector&, int&);
	//static bool operator!=(Vector&, Vector&);
	//Junior
	//static int operator<=(Vector&, Vector&);
	//static Vector operator>=(Vector&, Vector&);
	//static Vector operator<<=(Vector&, Vector&);
	Vector operator+(Vector*);
	Vector operator-(Vector*);
	double operator*(Vector*);
	//Yuli
	int operator++(int);
	int operator--(int);
	double operator/=(Vector*);
	//Santiago
	//std::ostream& operator<<(std::ostream&, Vector*);
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
