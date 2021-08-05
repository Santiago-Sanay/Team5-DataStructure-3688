#pragma once
#include <string>
using namespace std;
class mystring
{
public:
	/**
	 * @brief a minusculas
	 * 
	 * @return char 
	 */
	char to_lower( char);
	/**
	 * @brief a mayusculas
	 * 
	 * @return char 
	 */
	char to_upper(char);
	/**
	 * @brief capitaliza
	 * 
	 * @return string 
	 */
	string capitalize(string);
	/**
	 * @brief Hace minuscula
	 * 
	 * @return string 
	 */
	string minusculize(string);
	/**
	 * @brief Encontrar caracter
	 * 
	 * @return int 
	 */
	int find_character(string, char, int);
	/**
	 * @brief Encontrar
	 * 
	 * @return int 
	 */
	int find(string, string, int);
	/**
	 * @brief Devolver size
	 * 
	 * @return int 
	 */
	int length(string);
	/**
	 * @brief Quitar
	 * 
	 * @return string 
	 */
	string substract(string, int, int);
	/**
	 * @brief Es igual 
	 * 
	 * @return true 
	 * @return false 
	 */
	bool is_equal(string, string);
	/**
	 * @brief Char a int
	 * 
	 * @return int 
	 */
	int atoi(char);
	/**
	 * @brief String a int
	 * 
	 * @return int 
	 */
	int stoi(string);
	/**
	 * @brief String a long
	 * 
	 * @return long 
	 */
	long stol(string);
	/**
	 * @brief String a double
	 * 
	 * @return double 
	 */
	double stod(string);
	/**
	 * @brief Invierte string
	 * 
	 * @return string 
	 */
	string reverse(string);
	/**
	 * @brief Comprueba si es numero
	 * 
	 * @return true 
	 * @return false 
	 */
	bool is_number(string);
	/**
	 * @brief Potencia
	 * 
	 * @param num 
	 * @param pot 
	 * @return double 
	 */
	double potencia(double num, double pot);
};


