/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROYECTO FINAL
*FECHA DE CREACION : 15 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 25 DE JUNIO 2021
*/
#pragma once
#include <string>
using namespace std;
class Due
{
private:
	string date;
	string weekday;
	double mounthly_amount{0.0};
	double interest{0.0};
	double capital{0.0};
public:
	/**
	 * @brief Construct a new Due object
	 * 
	 */
	Due(string, string, double, double, double);
	
	/**
	 * @brief Construct a new Due object
	 * 
	 */
	Due() = default;
	
	/**
	 * @brief Get the date object
	 * 
	 * @return string 
	 */
	string get_date();
	
	/**
	 * @brief Set the date object
	 * 
	 */
	void set_date(string);
	
	/**
	 * @brief Get the weekday object
	 * 
	 * @return string 
	 */
	string get_weekday();
	
	/**
	 * @brief Set the weekday object
	 * 
	 */
	void set_weekday(string);
	
	/**
	 * @brief Get the mounthly amount object
	 * 
	 * @return double 
	 */
	double get_mounthly_amount();
	
	/**
	 * @brief Get the interest object
	 * 
	 * @return double 
	 */
	double get_interest();
	
	/**
	 * @brief Get the capital object
	 * 
	 * @return double 
	 */
	double get_capital();
	
	/**
	 * @brief Set the mounthly amount object
	 * 
	 */
	void set_mounthly_amount(double);
	
	/**
	 * @brief Set the interest object
	 * 
	 */
	void set_interest(double);
	
	/**
	 * @brief Set the capital object
	 * 
	 */
	void set_capital(double);
	
	/**
	 * @brief devuelve a string la clase
	 * 
	 * @return string 
	 */
	string to_string1();
	
	/**
	 * @brief deserializar string
	 * 
	 * @return Due 
	 */
	Due from_string_to_due(string);


};


