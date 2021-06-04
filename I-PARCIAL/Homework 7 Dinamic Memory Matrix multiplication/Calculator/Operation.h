#pragma once
#include "Matrix.h"

class Operation
{
public:
	/**
	 * @brief Reserva memoria para la matriz
	 * 
	 * @param lon 
	 * @return la dirreccion de una matriz 
	 */
	int **segmentar(int);

	/**
	 * @brief Inicializa la matriz en cero
	 * 
	 * @param longitud 
	 */
	void encerar(Matrix, int);

	/**
	 * @brief Asigna Valores a la matriz
	 * 
	 * @param longitud 
	 */
	void ingresar(Matrix, int);

	/**
	 * @brief  Multiplicacion entre matrices
	 * 
	 * @param _matrix_a 
	 * @param _matrix_b 
	 */
	void calcular(Matrix, Matrix, Matrix, int);

	/**
	 * @brief Impresion de la matriz
	 * 
	 * @param longitud 
	 */
	void imprimir(Matrix, int);
};
