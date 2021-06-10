#pragma once
#include <iostream>
class Nodo
{
private:
	int dato;
	Nodo* siguiente;
public:
	Nodo(int, Nodo*);

	int get_dato();
	void set_dato(int);
	Nodo* get_siguiente();
	void set_siguiente(Nodo*);
	friend class Lista;
};

