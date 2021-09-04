/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE SIMULE UNA CALCULADORA POLACA INVERSA
*FECHA DE CREACION : 03 DE JULIO DE 2021
*FECHA DE MODIFICACION:  04 DE JULIO DE 2021
*/
#pragma once
#include <string>
using namespace std;
class mystring
{
public:
	/**
	 * @brief Trasforma el texto a minusculas
	 *
	 * @return char
	 */
	char to_lower(char);
	/**
	 * @brief Trasforma el texto a mayusculas
	 *
	 * @return char
	 */
	char to_upper(char);
	/**
	 * @brief Trasforma el texto a minusculas 
	 *
	 * @return string
	 */
	string capitalize(string);
	/**
	 * @brief Trasforma el texto a mayusculas
	 *
	 * @return string
	 */
	string minusculize(string);
	/**
	 * @brief busca la posicion de una letra en un string
	 *
	 * @return int
	 */
	int find_character(string, char, int);
	/**
	 * @brief busca la posicion de una letra en un string
	 *
	 * @return int
	 */
	int find(string, string, int);	
	/**
	 * @brief Cuenta el tamaño del string
	 *
	 * @return int
	 */
	int length(string);
	/**
	 * @brief Copia una parte de la cadena
	 *
	 * @return string
	 */
	string substract(string, int, int);
	/**
	 * @brief Compara una cadena con otra cadena
	 *
	 * @return string
	 */
	bool is_equal(string, string);
	/**
	 * @brief Trasforma de char a entero
	 *
	 * @return int
	 */
	int atoi(char);
	/**
	 * @brief Trasforma de char a entero
	 *
	 * @return int
	 */
	int stoi(string);
	/**
	 * @brief Trasforma de char a entero
	 *
	 * @return long
	 */
	long stol(string);
	/**
	 * @brief Traspone las posciones del string
	 *
	 * @return string
	 */
	string reverse(string);
	/**
	 * @brief Traspone el string
	 *
	 * @return char
	 */
	char at(int,string);
};

