/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE UTILICE LISTAS
*FECHA DE CREACION : 10 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  10 DE JUNIO DE 2021
*/

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
