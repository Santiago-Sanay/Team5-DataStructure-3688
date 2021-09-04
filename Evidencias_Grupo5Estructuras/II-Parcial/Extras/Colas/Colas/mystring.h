/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROGRAMA DE COLAS
*FECHA DE CREACION : 05 DE JULIO DE 2021
*FECHA DE MODIFICACION: 11 DE JULIO 2021
*/
#pragma once
#include <string>
using namespace std;
class mystring
{
public:
	/**
 	* @brief convert a character to lowercase
 	* 
 	* @return char 
 	*/
	char to_lower(char);
	/**
	 * @brief convert a character to uppercase
	 * 
	 * @return char 
	 */
	char to_upper(char);
	/**
	 * @brief convert to uppercase
	 * 
	 * @return string 
	 */
	string capitalize(string);
	/**
	 * @brief convert to lowercase
	 * 
	 * @return string 
	 */
	string minusculize(string);
	/**
	 * @brief find character
	 * 
	 * @return int 
	 */
	int find_character(string, char, int);
	int find(string, string, int);
	/**
	 * @brief get the size of a character string
	 * 
	 * @return int 
	 */
	int length(string);
	/**
	 * @brief subtract a substring
	 * 
	 * @return string 
	 */
	string substract(string, int, int);

	/**
	 * @brief compare two strings
	 * 
	 * @return true 
	 * @return false 
	 */
	bool is_equal(string, string);
	/**
	 * @brief convert a character to int
	 * 
	 * @return int 
	 */
	int atoi(char);

	/**
	 * @brief convert string to int
	 * 
	 * @return int 
	 */
	int stoi(string);
	/**
	 * @brief convert string to long
	 * 
	 * @return long 
	 */
	long stol(string);
	/**
	 * @brief reverse string
	 * 
	 * @return string 
	 */
	string reverse(string);
	/**
	 * @brief get a char in the sttring
	 * 
	 * @return char 
	 */
	char at(int, string);
};

