/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Multiplicacion matriz dinamica
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
	/**
	 * @brief Get the matrix object
	 *
	 * @return int**
	 */
	bool verificar_matrix_suma15(Matrix matrix);
	/**
	 * @brief Get the matrix object
	 *
	 * @return int**
	 */
	void vec_to_matrix(int*,  Matrix matrix);
	/**
	 * @brief Get the matrix object
	 *
	 * @return int**
	 */
	 
	bool process(int* vec,int n, int** matrix);
	/**
	 * @brief Get the matrix object
	 *
	 * @return true False
	 */
	bool adyacent(int i, int j,int **matrix);
	/**
	 * @brief Get the matrix object
	 *
	 * @return true False
	 */
	void imprimir_vec(int* vec, int n);
	/**
	 * @brief Get the matrix object
	 *
	 * @return true False
	 */
	void next_vec_per(int* &vec, int num_casillas, int range,int position);
	/**
	 * @brief Get the matrix object
	 *
	 * @return true False
	 */
	bool complete_per(int* vec, int num_casillas, int range);
	/**
	 * @brief Get the matrix object
	 *
	 * @return true False
	 */
	void calcular_minimo_cd(int* vec_perm, int* vec_size_files, int range, int tamanio_cd,int &max,int num_archivos);
	int max_de_vector(int* vec, int tamanio);
	/**
	 * @brief Get the matrix object
	 *
	 * @return true False
	 */
	bool cumple_tamanio_del_cd(int* vec_per, int* vec_size_files, int range,int max, int tamanio_cd);
	/**
	 * @brief Get the matrix object
	 *
	 * @return true False
	 */
	void minimo_cds_para_archivos();

};
