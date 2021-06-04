#pragma once
#include "Matrix.h"

class Operation
{
public:
	int** segmentar(int);
	void encerar(Matrix, int);
	void ingresar(Matrix, int);
	void calcular(Matrix, Matrix, Matrix, int);
	void imprimir(Matrix, int);
};

