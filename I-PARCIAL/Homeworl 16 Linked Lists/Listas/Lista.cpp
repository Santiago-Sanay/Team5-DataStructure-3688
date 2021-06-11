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

#include "Lista.h"
bool Lista::listaVacia()
{
	return (this->primero == NULL);
}

Lista::Lista()
{
	this->primero = NULL;
	this->actual = NULL;
}

void Lista::insertar_por_la_cola(int val)
{
	Nodo* nuevo = new Nodo(val,NULL);
	if (listaVacia()) {
		this->primero = nuevo;
	}
	else {
		this->actual->set_siguiente(nuevo);
	}
	this->actual = nuevo;
}

void Lista::insertar_por_la_cabeza(int val)
{
	Nodo* nuevo = new Nodo(val, NULL);

	if (listaVacia()) {
		this->actual = nuevo;
	}
	else {
		nuevo->set_siguiente(this->primero);
	}
	this->primero = nuevo;
}

void Lista::borrar_por_la_cola()
{
	if (!listaVacia()) {
		Nodo* temp = this->actual;
		Nodo* temp1 = this->primero;
		while (temp1->get_siguiente()->get_siguiente() != NULL) {
			temp1 = temp1->get_siguiente();
		}
		temp1->set_siguiente(NULL);
		this->actual = temp1;
		free(temp);
	}
}

void Lista::borrar_por_la_cabeza()
{
	if (!listaVacia()) {
		Nodo* temp;
		temp = this->primero;
		this->primero = this->primero->get_siguiente();
		free(temp);
	}
}
	
	
	

void Lista::mostrar()
{
	Nodo* temporal = this->primero;
	//la direccion le apunta a primero
	while (temporal) {
		cout << temporal->dato << "->";
		temporal = temporal->siguiente;

	}
	cout << "NULL\n";
}
