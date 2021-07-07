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
	Client() = default;
	Client(int, int, int, int, int, int);

	string _to_string();
	void set_arrival_time(int);
	int get_arrival_time();
	
	void set_waiting_time(int);
	int get_waiting_time();
	
	void set_service_time(int);
	int get_service_time();
	
	void set_time_off(int);
	int get_time_off();
	
	void set_exit_time(int);
	int get_exit_time();
	
	void set_time_between_arrival(int);
	int get_time_between_arrival();
};

