/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: CALENDAR DATA PAYMENT
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#pragma once
#include "Nodo.h"
#include <ctime>
#include <random>
#include <functional>
#include <iostream>
using namespace std;
template <class T>
class List
{
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
public:
	bool listaVacia();
	List<T>() ;
	void insertar_por_la_cola(T);
	void set_primero(Nodo<T>*);
	Nodo<T>* get_primero();
	void set_actual(Nodo<T>*);
	Nodo<T>* get_actual();
	void insertar_por_la_cabeza(T);
	void borrar_por_la_cola();
	void borrar_por_la_cabeza();
	void mostrar();
	
	void vaciar_lista();
	
	
};

template<class T>
void List<T>::mostrar()
{
	Nodo<T>* temporal = this->primero;
	while (temporal) {
		cout << temporal->get_dato() << " "<<endl;
		temporal = temporal->get_siguiente();

	}
	cout << endl;
}
template<class T>
void List<T>::vaciar_lista() {
	while (listaVacia()) {
		borrar_por_la_cola();
	}
}
template<class T>
bool List<T>::listaVacia()
{
	return (this->primero == NULL);
}
template<class T>
List<T>::List()
{
	this->primero = NULL;
	this->actual = NULL;
}
template<class T>
void List<T>::insertar_por_la_cola(T val)
{
	Nodo<T>* nuevo = new Nodo<T>(val, NULL);
	if (listaVacia()) {
		this->primero = nuevo;
	}
	else {
		this->actual->set_siguiente(nuevo);
	}
	this->actual = nuevo;
}
template<class T>
void List<T>::set_primero(Nodo<T>* new_primero) {
	this->primero = new_primero;
}
template<class T>
Nodo<T>* List<T>::get_primero() {
	return primero;
}
template<class T>
void List<T>::set_actual(Nodo<T>* new_actual) {
	this->actual = new_actual;
}
template<class T>
Nodo<T>* List<T>::get_actual() {
	return actual;
}
template<class T>
void List<T>::insertar_por_la_cabeza(T val)
{
	Nodo<T>* nuevo = new Nodo<T>(val, NULL);

	if (listaVacia()) {
		this->actual = nuevo;
	}
	else {
		nuevo->set_siguiente(this->primero);
	}
	this->primero = nuevo;
}
template<class T>
void List<T>::borrar_por_la_cola()
{
	if (!listaVacia()) {
		Nodo<T>* temp = this->actual;
		Nodo<T>* temp1 = this->primero;
		while (temp1->get_siguiente()->get_siguiente() != NULL) {
			temp1 = temp1->get_siguiente();
		}
		temp1->set_siguiente(NULL);
		this->actual = temp1;
		free(temp);
	}
}
template<class T>
void List<T>::borrar_por_la_cabeza()
{
	if (!listaVacia()) {
		Nodo<T>* temp;
		temp = this->primero;
		this->primero = this->primero->get_siguiente();
		free(temp);
	}
}

