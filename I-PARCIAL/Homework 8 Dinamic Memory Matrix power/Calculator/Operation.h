/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 1 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 3 DE JUNIO 2021
*/

#pragma once
#include "Matrix.h"

class Operation
{
public:
	/**
	 * @brief Reserva memoria para la matriz
	 * 
	 * @param longitud 
	 * @return la dirreccion de una matriz 
	 */
	int **segmentar(int);

	/**
	 * @brief Inicializa la matriz en cero
	 * 
	 * @param matriz_a 
	 * @param longitud 
	 */
	void encerar(Matrix matriz_a, int longitud);

	/**
	 * @brief Asigna Valores a la matriz
	 * 
	 * @param matriz_a
	 * @param longitud 
	 */
	void ingresar(Matrix, int);

	/**
	 * @brief  Multiplicacion de Matrices
	 * 
	 * @param _matrix_a 
	 * @param _matrix_b 
	 * @param _matrix_c 
	 * @param longitud
	 */
	void calcular(Matrix, Matrix, Matrix, int);

	/**
	 * @brief Impresion de la matriz
	 * 
	 * @param _matrix_a 
	 * @param longitud 
	 */
	void imprimir(Matrix, int);

	/**
	 * @brief Copia los datos de una matriz
	 * 
	 * @param _matrix_a 
	 * @param _matrix_b 
	 * @param longitud
	 */
	void copiar_matriz(Matrix, Matrix, int);

	/**
	 * @brief  Calcula la potencia de una matriz
	 * 
	 * @param _matrix_a 
	 * @param _matrix_b 
	 * @param longitud
	 */
	void calcular_potencia(Matrix, Matrix, int, int);
};
