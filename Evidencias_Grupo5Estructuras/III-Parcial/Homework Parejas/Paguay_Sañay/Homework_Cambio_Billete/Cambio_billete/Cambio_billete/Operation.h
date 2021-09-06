/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/
#pragma once
#include "Matrix.h"
#include <time.h>
#include <ctime>
#include <random>
#include <string>
using namespace std;
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
	
	bool verificar_matrix_suma15(Matrix matrix);
	void vec_to_matrix(int*,  Matrix matrix);
	
	void swap(int *v, int i, int j);
	void perm(int *v, int n, int i,Matrix matrix,int &sol);
	void generar_tabla_aleatoria(Matrix matrix, int dim);
	void permutacion(string aux, int* items, int n, int r);
	int contar_colores(int n,int *vec, int** matrix);
	bool process(int* vec,int n, int** matrix);
	bool adyacent(int i, int j,int **matrix);
	bool nextPermutation(int* vec, int color,int n);
	void imprimir_vec(int* vec, int n);
	void next_vec_per(int* &vec, int num_casillas, int range,int position);
	bool complete_per(int* vec, int num_casillas, int range);
	bool suma_billete(int* vec, int valor);
	void next_vec_per1(int*& vec, int num_casillas, int range, int position);
	void imprimir_vec2(int* vec, int n);
	void next_vec_per2(int*& vec, int num_casillas, int range, int position);
	bool complete_per1(int* vec, int num_casillas, int range);
	void encerar_array(int* array, int n);
};
