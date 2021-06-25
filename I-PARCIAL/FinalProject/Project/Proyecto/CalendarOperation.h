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
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#pragma once
#include "Calendar.h"
#include <iostream>
#include "Due.h"
#include "LinkedList.h"
using namespace std;
class CalendarOperation
{
public:
	/**
	 * @brief Reserva memoria para la matriz
	 *
	 * @param longitud
	 * @return la dirreccion de una matriz
	 */

	string* segment(int);

	/**
	 * @brief encerar vector
	 * 
	 */
	void wax(string*, int);

	/**
	 * @brief calcula dia de semana
	 * 
	 * @return int 
	 */
	int calculate_day(string);

	/**
	 * @brief llena vector de cuotas
	 * 
	 */
	void date_vector(string, int, Calendar);

	/**
	 * @brief Set the valid date object
	 * 
	 * @return string 
	 */
	string set_valid_date(string);

	/**
	 * @brief imprime calendario
	 * 
	 */
	void print_calendar(int, string*);

	/**
	 * @brief Set the weekend object
	 * 
	 */
	void set_weekend(int, string*);
	
	/**
	 * @brief verifica feriados
	 * 
	 * @return true 
	 * @return false 
	 */
	bool check_holiday(string);
	
	/**
	 * @brief verifica finde semana
	 * 
	 * @return true 
	 * @return false 
	 */
	bool check_fds(string);
	
	/**
	 * @brief suma dia a fecha actual
	 * 
	 * @return string 
	 */
	string add_day(string);
		
	/**
	 * @brief devuelve nombre de dia
	 * 
	 * @return string 
	 */
	string weekday_name(string);
	
	/**
	 * @brief segmentar espacio memoria
	 * 
	 * @return double** 
	 */
	double** segment2(int, int);
	
	/**
	 * @brief amortizacion francesa
	 * 
	 * @param date 
	 * @param initial_amount 
	 * @param payment_time 
	 * @param interest 
	 * @param dues 
	 * @param final_amount 
	 */
	void french_amortization(string date, double initial_amount, int payment_time, double interest, LinkedList<Due> &dues, double &final_amount);
	
	/**
	 * @brief amortizacion alemana
	 * 
	 * @param date 
	 * @param initial_amount 
	 * @param payment_time 
	 * @param interest 
	 * @param dues 
	 * @param final_amount 
	 */
	void german_amortization(string date, double initial_amount, int payment_time, double interest, LinkedList<Due>& dues, double &final_amount);
	
	/**
	 * @brief imprime tabla de pago
	 * 
	 */
	void payment_table(string,double,int,string,double, LinkedList<Due>);
	
	/**
	 * @brief pago final
	 * 
	 * @return double 
	 */
	double final_amount_payment(LinkedList<Due>);

};

