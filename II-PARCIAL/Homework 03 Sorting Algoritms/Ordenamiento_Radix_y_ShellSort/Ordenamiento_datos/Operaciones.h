/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Ordenamiento de datos
*FECHA DE CREACION : 25 DE JULIO DE 2021
*FECHA DE MODIFICACION: 26 DE JUNIO 2021
*/
#pragma once
#include "Vector.h"
#include <string>
#include<functional>
using namespace std;
class Operaciones
{
public:
	/**
	 * @brief genera un arreglo
	 *
	 * @void
	 */
	void generar_arreglo(Vector, int,int);
	/**
	 * @brief imprime un arreglo
	 *
	 * @void
	 */
	void imprimir_arreglo(Vector, int);
	/**
	 * @brief ordenamiento burbuja
	 *
	 * @void
	 */
	void ordenar_Bubble_sort(Vector,int);
	/**
	 * @brief ordenamiento quicksort
	 *
	 * @void
	 */
	void ordenar_quicksort(Vector, int, int izq, int der);
	/**
	 * @brief ordenamiento shellsort
	 *
	 * @void
	 */
	void ordenar_shellsort(Vector, int);
	/**
	 * @brief ordenamiento por intercambio
	 * @void
	 */
	void ordenar_intercambio(Vector, int);
	/**
	 * @brief ordenamiento shell sort con lamda
	 *
	 * @void
	 */
	void ordenar_shellsort1(Vector, int, function<void(int&, int&)>intercambio);
	/**
	 * @brief ordenamiento shellsort con lamda
	 *
	 * @void
	 */
	void ordenar_shellsort2(Vector, int, function<bool(int&, int&)>ordenar);
	/**
	 * @brief ordenar por seleccion
	 *
	 * @void
	 */
	void ordenar_seleccion(Vector, int,string);
	/**
	 * @brief ordenamiento por seleecion usando lamda
	 *
	 * @void
	 */
	void ordenar_seleccion1(function<void(int&, int&)>intercambio,Vector, int, string);
	/**
	 * @brief verifica si es ascendete
	 *
	 * @true or false
	 */
	bool ascendente(int a,int b);
	/**
	 * @brief verifica si el ordenamiento es descendente
	 *
	 * @return true or false
	 */
	bool descendente(int a, int b);
	/**
	 * @brief encera el arreglo
	 *
	 * @void
	 */
	void encerar_arreglo(Vector, int);
	/**
	 * @brief devuelve el maximo
	 *
	 * @devuelve un entero
	 */
	int maxm(Vector, int n); 
	/**
	 * @brief Get the dato object
	 *
	 * @return T
	 */
	void countingSort(Vector, int n, int place);
	/**
	 * @brief ordena por el metodo de radixsort
	 *
	 * @void
	 */
	void radixsort(Vector, int n);
	/**
	 * @brief Get the dato object
	 *
	 * @return T
	 */
	void merge(Vector, int, int, int);
	/**
	 * @brief Get the dato object
	 *
	 * @return T
	 */
	void merge_sort(int izquierda, int derecha);
};

