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
#include "Queue.h"
#include "Client.h"


class Operation
{
public:
	/**
	 * @brief register the firts client
	 * 
	 * @return Client 
	 */
	Client first();
	/**
	 * @brief generate data table
	 * 
	 * @return Queue<Client> 
	 */
	Queue<Client> generate_table(int); 
	/**
	 * @brief calculate arrival time
	 * 
	 * @return Queue<Client> 
	 */
	Queue<Client> calculate_arrival_time(function<void(int&, Node<Client>*, Client&, int&)>assign, Queue<Client>&, int);
	/**
	 * @brief calculate service time
	 * 
	 * @param clients 
	 * @param index 
	 * @return Queue<Client> 
	 */
	Queue<Client> calculate_service_time(function<void(int&, Queue<Client>, Client&, Queue<Client>&, int&)>assign, Queue<Client>& clients, int index);
	/**
	 * @brief print all clients
	 * 
	 */
	void mostrar(Queue<Client>);
	/**
	 * @brief calculate waiting time
	 * 
	 * @return Queue<Client> 
	 */
	Queue<Client> calculate_waiting_time(Queue<Client>&,int);
	/**
	 * @brief calculate exit time
	 * 
	 * @return int 
	 */
	int calculate_exit_time(Client);
	/**
	 * @brief calculate summary
	 * 
	 */
	void calculate_summary(Queue<Client>&);
};

