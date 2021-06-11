#include "Nodo.h"

Nodo::Nodo(int val, Nodo* sig = NULL)
{
	this->dato = val;
	this->siguiente = sig;
}

int Nodo::get_dato()
{
	return this->dato;
}

void Nodo::set_dato(int val)
{
	this->dato = val;
}

Nodo* Nodo::get_siguiente()
{
	return this->siguiente;
}

void Nodo::set_siguiente(Nodo* nuevo)
{
	this->siguiente = nuevo;
}
