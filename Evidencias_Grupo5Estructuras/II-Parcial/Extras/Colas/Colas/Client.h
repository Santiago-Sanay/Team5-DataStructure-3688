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
#include <iostream>
using namespace std;
class Client
{
private:
	int arrival_time;
	int waiting_time;
	int service_time;
	int time_off;
	int exit_time;
	int time_between_arrival;
public:
/**
 * @brief Construct a new Client object
 * 
 */
	Client() = default;
	/**
	 * @brief Construct a new Client object
	 * 
	 */
	Client(int, int, int, int, int, int);
	/**
	 * @brief To string 
	 * 
	 * @return string 
	 */
	string _to_string();
	/**
	 * @brief Set the arrival time object
	 * 
	 */
	void set_arrival_time(int);
	/**
	 * @brief Get the arrival time object
	 * 
	 * @return int 
	 */
	int get_arrival_time();
	
	/**
	 * @brief Set the waiting time object
	 * 
	 */
	void set_waiting_time(int);
	/**
	 * @brief Get the waiting time object
	 * 
	 * @return int 
	 */
	int get_waiting_time();
	
	/**
	 * @brief Set the service time object
	 * 
	 */
	void set_service_time(int);
	/**
	 * @brief Get the service time object
	 * 
	 * @return int 
	 */
	int get_service_time();
	
	/**
	 * @brief Set the time off object
	 * 
	 */
	void set_time_off(int);
	/**
	 * @brief Get the time off object
	 * 
	 * @return int 
	 */
	int get_time_off();
	
	/**
	 * @brief Set the exit time object
	 * 
	 */
	void set_exit_time(int);
	/**
	 * @brief Get the exit time object
	 * 
	 * @return int 
	 */
	int get_exit_time();
	
	/**
	 * @brief Set the time between arrival object
	 * 
	 */
	void set_time_between_arrival(int);
	/**
	 * @brief Get the time between arrival object
	 * 
	 * @return int 
	 */
	int get_time_between_arrival();
};

