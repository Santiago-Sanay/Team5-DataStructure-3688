#pragma once
#include "Queue.h"
#include "Client.h"


class Operation
{
public:
	Client first();
	Queue<Client> generate_table(int); 
	Queue<Client> calculate_arrival_time(function<void(int&, Node<Client>*, Client&, int&)>assign, Queue<Client>&, int);
	Queue<Client> calculate_service_time(function<void(int&, Queue<Client>, Client&, Queue<Client>&, int&)>assign, Queue<Client>& clients, int index);
	void mostrar(Queue<Client>);
	Queue<Client> calculate_waiting_time(Queue<Client>&,int);
	int calculate_exit_time(Client);
	void calculate_summary(Queue<Client>&);
};

