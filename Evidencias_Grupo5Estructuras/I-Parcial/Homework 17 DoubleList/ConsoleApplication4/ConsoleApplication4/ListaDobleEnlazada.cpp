/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: Listas dobles
*FECHA DE CREACION : 14 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 17 DE MAYO 2021
*/

#include "ListaDobleEnlazada.h"
#include <iostream>
using namespace std;
Nodo* ListaDobleEnlazada::ultimo_nodo()
{
	Nodo* tmp = cabeza;
	while (tmp->get_siguiente() != nullptr) {
		
		tmp = tmp->get_siguiente();
	}
	return tmp;
}

void ListaDobleEnlazada::insertar(int valor)
{
	Nodo* nodo = new Nodo(valor);
	if (cabeza == nullptr) {
		this->cabeza = nodo;
		tamanio++;
		return;
	}
	Nodo* ultimo = ultimo_nodo();
	ultimo->set_siguiente(nodo);
	nodo->set_anterior(ultimo);
	tamanio++;
}

void ListaDobleEnlazada::insertar_cabeza(int valor)
{
	Nodo* nodo = new Nodo(valor);
	if (cabeza == nullptr) {
		this->cabeza = nodo;
		tamanio++;
		return;
	}
	cabeza->set_anterior(nodo);
	nodo->set_siguiente(cabeza);
	cabeza = nodo;
	tamanio++;

}

void ListaDobleEnlazada::insertar_por_indice(int indice,int valor)
{
	if (indice >= tamanio || indice <0 ) {
		cout << "Indice fuelra de la lista" << endl;
		return;
	}
	if (indice == 0) {
		insertar_cabeza(valor);
		return;
	}
	if (indice == tamanio-1) {
		insertar(valor);
		return;
	}
	Nodo* tmp = cabeza;
	Nodo* anterior;
	Nodo* nodo = new Nodo(valor);
	int indice1 = 0;
	while (indice != indice1) {
		tmp = tmp->get_siguiente();
		indice1++;
	}
	anterior = tmp->get_anterior();
	anterior->set_siguiente(nodo);
	tmp->set_anterior(nodo);
	nodo->set_anterior(anterior);
	nodo->set_siguiente(tmp);
	tamanio++;
}

void ListaDobleEnlazada::eliminar_por_indice(int indice)
{
	if (indice >= tamanio || indice < 0) {
		cout << "Indice fuelra de la lista" << endl;
		return;
	}
	if (indice == 0) {
		eliminar_cabeza();
		return;
	}
	if (indice == tamanio - 1) {
		eliminar_cola();
		return;
	}
	Nodo* tmp = cabeza;
	Nodo* anterior;
	Nodo* posterior;
	int indice1 = 0;
	while (indice != indice1) {
		tmp = tmp->get_siguiente();
		indice1++;
	}
	anterior = tmp->get_anterior();
	posterior = tmp->get_siguiente();
	
	posterior->set_anterior(anterior);
	anterior->set_siguiente(posterior);
	free(tmp);
	tamanio--;



}

void ListaDobleEnlazada::eliminar_cabeza()
{
	if (cabeza == nullptr) {
		return;
	}
	if (tamanio == 1) {
		free(cabeza);
		cabeza = nullptr;
		return;
	}
	Nodo* tmp;
	tmp = cabeza->get_siguiente();
	tmp->set_anterior(nullptr);
	free(cabeza);
	
	cabeza = tmp;
	tamanio--;
}

void ListaDobleEnlazada::eliminar_cola()
{
	
	if (cabeza == nullptr) {
		return;
	}
	if (tamanio == 1) {
		free(cabeza);
		cabeza = nullptr;
		return;
	}
	Nodo* tmp=cabeza;
	Nodo* ultimo = ultimo_nodo();
	while (tmp->get_siguiente()->get_siguiente() != nullptr) {

		tmp = tmp->get_siguiente();
	}
	tmp->set_siguiente(nullptr);
	free(ultimo);
	tamanio--;
	
}

void ListaDobleEnlazada::recorrer(function<void(int, int)> recorrido)
{
	Nodo* tmp = cabeza;
	int indice = 0;
	while (tmp != nullptr) {
		recorrido(tmp->get_valor(), indice++);
		tmp = tmp->get_siguiente();
	}
}

int ListaDobleEnlazada::consultar(int indice)
{
	if (indice >= tamanio || indice < 0) {
		cout << "Indice fuelra de la lista" << endl;
		return 0;
	}
	Nodo* tmp = cabeza;
	
	int indice1 = 0;
	while (indice != indice1) {
		tmp = tmp->get_siguiente();
		indice1++;
	}
	return tmp->get_valor();
}
