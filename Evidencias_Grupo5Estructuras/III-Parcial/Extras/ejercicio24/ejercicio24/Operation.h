#pragma once
#include <string>
#include <iostream>
using namespace std;
class Operation
{
public:
	Operation() = default;
	void permutar_letras(string aux, string* letras, int n, int r);
	void imprimir_array(string* array, int dim);
};

