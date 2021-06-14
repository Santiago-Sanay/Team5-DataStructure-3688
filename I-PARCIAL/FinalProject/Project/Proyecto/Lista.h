#pragma once
//#pragma once
#include "Nodo.h"
#include <ctime>
#include <random>
using namespace std;
template <typename T>
class Lista
{
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
public:
	bool listaVacia();
	Lista();
	void insertar_por_la_cola(T);
	void insertar_por_la_cabeza(T);
	void borrar_por_la_cola();
	void borrar_por_la_cabeza();
	void mostrar();
	void llenar_aleatorio_lista();
	T maximo_comun_divisor(T);
	T contar_elementos();



};
//#include "Lista.cpp"
template<class T>
bool Lista<T>::listaVacia()
{
	return (this->primero == NULL);
}
template<class T>
Lista<T>::Lista()
{
	this->primero = NULL;
	this->actual = NULL;
}

template<class T>
void Lista<T>::insertar_por_la_cola(T val)
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
void Lista<T>::insertar_por_la_cabeza(T val)
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
void Lista<T>::borrar_por_la_cola()
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
void Lista<T>::borrar_por_la_cabeza()
{
	if (!listaVacia()) {
		Nodo<T>* temp;
		temp = this->primero;
		this->primero = this->primero->get_siguiente();
		free(temp);
	}
}
template<class T>
void Lista<T>::llenar_aleatorio_lista()
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
T Lista<T>::maximo_comun_divisor(T elementos)
{
	int mcd = 0;
	int contador = 0;
	Nodo<T>* temporal = this->primero;
	for (int i = 1; i < 1000; i++) {
		contador = 0;
		temporal = this->primero;
		while (temporal) {
			//elementos = elementos + 1;

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
T Lista<T>::contar_elementos()
{
	int elementos = 0;
	Nodo<T>* temporal = this->primero;
	//la direccion le apunta a primero
	while (temporal) {
		elementos = elementos + 1;
		temporal = temporal->get_siguiente();

	}
	return T(elementos);
}



template<class T>
void Lista<T>::mostrar()
{
	Nodo<T>* temporal = this->primero;
	//la direccion le apunta a primero
	while (temporal) {
		cout << temporal->get_dato() << "->";
		temporal = temporal->get_siguiente();

	}
	cout << "NULL\n";
}

