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

#include "Due.h"
#include "Person.h"
using namespace std;
class Doubt
{
private:
	string id_person;
	double initial_amount{0.0}; //PRESTAMO
	string initial_date; // FECHA DE PRIMER PAGO
	int payment_time{0}; // NUMERO DE CUETOS
	string rate_of_interest; // TIPO DE INTERES
	double interest{0.0}; // PORCENTAJE ANUAL 
	double final_amount{0.0}; // SUMA EL CREDITO MAS EL INTERES.
public:

	/**
	 * @brief Construct a new Doubt object
	 * 
	 */
	Doubt(string, double, string, int, string, double);
	
	/**
	 * @brief Construct a new Doubt object
	 * 
	 */
	Doubt() = default;
	
	/**
	 * @brief Get the initial amount object
	 * 
	 * 
	 * @return double 
	 */
	double get_initial_amount();

	/**
	 * @brief Set the initial amount object
	 * 
	 */
	void set_initial_amount(double);
	
	/**
	 * @brief Get the payment time object
	 * 
	 * @return int 
	 */
	int get_payment_time();
	
	/**
	 * @brief Set the payment time object
	 * 
	 */
	void set_payment_time(int);
	
	/**
	 * @brief Get the rate of interest object
	 * 
	 * @return string 
	 */
	string get_rate_of_interest();
	
	/**
	 * @brief Set the rate of interest object
	 * 
	 */
	void set_rate_of_interest(string);
	
	/**
	 * @brief Get the interest object
	 * 
	 * @return double 
	 */
	double get_interest();
	
	/**
	 * @brief Set the interest object
	 * 
	 */
	void set_interest(double);
	
	/**
	 * @brief Set the final amount object
	 * 
	 */
	void set_final_amount(double);
	
	/**
	 * @brief Get the final amount object
	 * 
	 * @return double 
	 */
	double get_final_amount();
	
	/**
	 * @brief Get the id person object
	 * 
	 * @return string 
	 */
	string get_id_person();
	
	/**
	 * @brief Set the id person object
	 * 
	 */
	void set_id_person(string);
	
	/**
	 * @brief Set the initial date object
	 * 
	 */
	void set_initial_date(string);
	
	/**
	 * @brief Get the initial date object
	 * 
	 * @return string 
	 */
	string get_initial_date();

};