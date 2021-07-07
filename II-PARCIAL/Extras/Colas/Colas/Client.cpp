#include "Client.h"
#include <string>
string Client::_to_string()
{
    string cad = "{\"";
    cad += "arrival_time\"";
    cad += ":";
    cad += "\"";
    cad += to_string(arrival_time);
    cad += "\"";
    cad += ",";
    cad += "\"";
    cad += "waiting_time";
    cad += "\"";
    cad += ":";
    cad += "\"";
    cad += to_string(waiting_time);
    cad += "\"";
    cad += ",";
    cad += "\"";
    cad += "service_time";
    cad += "\"";
    cad += ":";
    cad += "\"";
    cad += to_string(service_time);
    cad += "\"";
    cad += ",";
    cad += "\"";
    cad += "time_off";
    cad += "\"";
    cad += ":";
    cad += "\"";
    cad += to_string(time_off);
    cad += "\"";
    cad += ",";
    cad += "\"";
    cad += "exit_time";
    cad += "\"";
    cad += ":";
    cad += "\"";
    cad += to_string(exit_time);
    cad += "\"";
    cad += ",";
    cad += "\"";
    cad += "time_between_arrival";
    cad += "\"";
    cad += ":";
    cad += "\"";
    cad += to_string(time_between_arrival);
    cad += "}";
    return cad;
}
Client::Client(int _arrival_time, int _waiting_time, int _service_time, int _time_off, int _exit_time, int _time_between_arrival)
{
	this->arrival_time = _arrival_time;
	this->waiting_time = _waiting_time;
	this->service_time= _service_time;
	this->time_off=_time_off;
	this->exit_time=_exit_time;
	this->time_between_arrival=_time_between_arrival;
}
void Client::set_arrival_time(int time)
{
	this->arrival_time = time;
}

int Client::get_arrival_time()
{
	return this->arrival_time;
}

void Client::set_waiting_time(int time)
{
	this->waiting_time = time;
}

int Client::get_waiting_time()
{
	return this->waiting_time;
}

void Client::set_service_time(int time)
{
	this->service_time = time;
}

int Client::get_service_time()
{
	return this->service_time;
}

void Client::set_time_off(int time)
{
	this->time_off = time;
}

int Client::get_time_off()
{
	return this->time_off;
}

void Client::set_exit_time(int time)
{
	this->exit_time = time;
}

int Client::get_exit_time()
{
	return this->exit_time;
}

void Client::set_time_between_arrival(int time)
{
	this->time_between_arrival = time;
}

int Client::get_time_between_arrival()
{
	return this->time_between_arrival;
}
