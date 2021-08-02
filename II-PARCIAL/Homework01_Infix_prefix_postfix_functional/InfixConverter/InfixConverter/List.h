/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE SIMULE UNA CALCULADORA POLACA INVERSA
*FECHA DE CREACION : 03 DE JULIO DE 2021
*FECHA DE MODIFICACION:  04 DE JULIO DE 2021
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
	/**
	 * @brief Lista Vacia
	 *
	 * @return Lista
	 */
	bool listaVacia();
	List<T>() ;
	/**
	 * @brief Insertar por la cola  de una Lista 
	 *
	 * @return Lista T
	 */
	void insertar_por_la_cola(T);
	/**
	 * @brief setter
	 *
	 * @return Lista T
	 */
	void set_primero(Nodo<T>*);
	/**
	 * @brief getter
	 *
	 * @return Lista T
	 */
	Nodo<T>* get_primero();
	/**
	 * @brief setter
	 *
	 * @return Lista T
	 */
	void set_actual(Nodo<T>*);
	/**
	 * @brief setter
	 *
	 * @return Lista T
	 */
	Nodo<T>* get_actual();
	/**
	 * @brief Insertar por la cabeza  de una Lista
	 *
	 * @return Lista T
	 */
	void insertar_por_la_cabeza(T);
	/**
	 * @brief Borrar por la cola  de una Lista
	 *
	 * @return Lista T
	 */
	void borrar_por_la_cola();
	/**
	 * @brief Borrar por la cabeza  de una Lista
	 *
	 * @return Lista T
	 */
	void borrar_por_la_cabeza();
	/**
	 * @brief Mostar Lista
	 *
	 * @return Lista T
	 */
	void mostrar();
	/**
	 * @brief Llena de numeros aleatorios en la lista
	 *
	 * @return Lista T
	 */
	void llenar_aleatorio_lista();
	/**
	 * @brief vacia una en la lista
	 *
	 * @return Lista T
	 */
	void vaciar_lista();
	T maximo_comun_divisor(T);
	T contar_elementos();
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
template<class T>
void List<T>::llenar_aleatorio_lista()
{
	Nodo<T>* temp = this->primero;
	std::srand(std::time(nullptr));
	int aleatorio = 0;
	while (aleatorio != 5) {
		aleatorio = 1 + rand() % (6);
		if (aleatorio == 2 || aleatorio == 4) {
			insertar_por_la_cola(aleatorio);
		}
	}



}
template<class T>
T List<T>::maximo_comun_divisor(T elementos)
{
	int mcd = 0;
	int contador = 0;
	Nodo<T>* temporal = this->primero;
	for (int i = 1; i < 1000; i++) {
		contador = 0;
		temporal = this->primero;
		while (temporal) {
			
			if (temporal->get_dato() % i == 0) {

				contador = contador + 1;
			}
			temporal = temporal->get_siguiente();


		}

		if (elementos == contador) {
			mcd = i;
		}

	}

	return T(mcd);
}
template<class T>
T List<T>::contar_elementos()
{
	int elementos = 0;
	Nodo<T>* temporal = this->primero;
	while (temporal) {
		elementos = elementos + 1;
		temporal = temporal->get_siguiente();

	}
	return T(elementos);
}

