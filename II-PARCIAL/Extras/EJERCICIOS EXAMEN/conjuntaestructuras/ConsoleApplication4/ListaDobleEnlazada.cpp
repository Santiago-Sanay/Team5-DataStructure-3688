#include "ListaDobleEnlazada.h"
#include <iostream>
#include <string>
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
		cout << "Indice fuera de la lista" << endl;
		return NULL;
	}
	Nodo* tmp = cabeza;
	
	int indice1 = 0;
	while (indice != indice1) {
		tmp = tmp->get_siguiente();
		indice1++;
	}
	return tmp->get_valor();
}

int ListaDobleEnlazada::numero_ajustado(int numero1, int valor)
{
	string numero;
	string caracter;
	string digito;
	numero = to_string(numero1);
	caracter = to_string(valor);
	if (numero.find(caracter, 0) == 0) {
		digito = numero.substr(2, 1);
		numero = digito+"";
	}
	if (numero.find(caracter, 0) == 1) {
		digito = numero.substr(0, 1);
		numero = digito + "";
	}
	numero1 = stoi(numero);
	/*while (numero.find(caracter, 0)>=0 && numero.find(caracter, 0) < numero.length()) {
		if (numero.find(caracter, 0) == 0) {

		}
		numero1 = numero1 + valor;
		numero = to_string(numero1);
		
	}*/
	return numero1;
}

void ListaDobleEnlazada::ajustar_lista(int valor)
{
	Nodo* tmp = cabeza;
	int num_ajustado;
	int indice = 0;
	while (tmp != nullptr) {
		num_ajustado = numero_ajustado(tmp->get_valor(),valor);
		tmp->set_valor(num_ajustado);
		
		tmp = tmp->get_siguiente();
	}

}
char* ListaDobleEnlazada::ingreso(string msj) {
	char dato[5];
	char c;
	int i = 0;
	cout << msj << endl;
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato[i++] = c;
		}
	}
	dato[i] = '\0';
	return dato;
}
