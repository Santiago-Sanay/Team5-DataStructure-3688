#pragma once
#include "Queue.h"
#include "Client.h"
class Operation
{
public:
	Client first();
	Queue<Client> generate_table(int);
	Queue<Client> calculate_arrival_time(Queue<Client>&,int);
	void mostrar(Queue<Client>);
	Queue<Client> calculate_service_time(Queue<Client>&,int);
	Queue<Client> calculate_waiting_time(Queue<Client>&,int);
	int calculate_exit_time(Client);
	void calculate_summary(Queue<Client>&);
};

