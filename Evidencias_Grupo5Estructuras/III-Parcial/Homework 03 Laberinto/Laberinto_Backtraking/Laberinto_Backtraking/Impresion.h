#pragma once
#include <stdio.h>
#include <conio.h>
#include "Matrix.h"
#include "Operation.h"
#include <string>
#include <fstream>
class Impresion
{
public:
	Impresion() = default;
	int** recuperar_matrix_file(string file);
	void imprimir_matrix(Matrix matrix, int fila, int col);
	void imprimir_sol(int** m1, int** m2, int fila, int col);
};

