#pragma once
#include "Nodo.h"
#include "mystring.h"
#include "Operation.h"
//#include "Due.h"
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
	void borrar_por_indice(int indice);
	void mostrar();
	void mostrar_due();
	void llenar_aleatorio_lista();
	void vaciar_lista();
	T maximo_comun_divisor(T);
	T contar_elementos();
	void recorrer_print(Nodo<T>*);
	//string to_string_list();
	void reparar(Nodo<T>* cabeza, int x, int correccion);
	List<T> concatenar_listas(List<T> list1, List<T> list2);
	void crop(Nodo<T>* cabeza, int* excepciones,int tamanio);
	void eliminar(List<List<int> > c, int dato);
	void eliminar_lista_simple(List<int> list, int dato);
	void imprimir_lista_compuesta(Nodo<List<int>>* c);
};

template<class T>
void List<T>::mostrar()
{
	Nodo<T>* temporal = this->primero;
	//la direccion le apunta a primero
	while (temporal) {
		cout << temporal->get_dato() << "->"<<endl;
		temporal = temporal->get_siguiente();

	}
	cout << "NULL\n";
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
void List<T>::borrar_por_indice(int indice)
{
	if (!listaVacia()) {
		Nodo<T>* aux = nullptr;
		Nodo<T>* temp1 = this->primero;
		int cont = 0;
		while (temp1) {
			if (cont == indice) {
				if (indice == 0) {
					borrar_por_la_cabeza();
					return;
				}
				else {
					aux->set_siguiente(temp1->get_siguiente());
					free(temp1);
					return;
				}
			}
			aux = temp1;
			temp1 = temp1->get_siguiente();
			cont++;
		}
		
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
T List<T>::contar_elementos()
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
void List<T>::recorrer_print(Nodo<T>* list)
{
	if (list) {
		cout << list->get_dato() <<"	";
		recorrer_print(list->get_siguiente());
	}
	else {
		cout << endl;
	}
	
}
template<class T>
void List<T>::reparar(Nodo<T>*cabeza,int x,int correccion )
{
	
	while (cabeza) {
		
		if (cabeza->get_dato() == x) {
			cabeza->set_dato(cabeza->get_dato() + correccion);
		}
		cabeza = cabeza->get_siguiente();

	}
	
}
template<class T>
List<T> List<T>::concatenar_listas(List<T> list1, List<T> list2)
{
	List<T> list3;
	mystring str;
	Nodo<T> *nodo1=list1.get_primero();
	Nodo<T>* nodo2 = list2.get_primero();
	string data;
	while (nodo1 || nodo2) {

		if (nodo1 && nodo2) {
			data = to_string(nodo1->get_dato()) + to_string(nodo2->get_dato());
			list3.insertar_por_la_cola(str.stoi(data));
		}
		if (nodo1 && !nodo2) {
			
			list3.insertar_por_la_cola(nodo1->get_dato());
		}
		if (!nodo1 && nodo2) {

			list3.insertar_por_la_cola(nodo2->get_dato());
		}
		if (nodo1) {
			nodo1 = nodo1->get_siguiente();
		}
		if (nodo2) {
			nodo2 = nodo2->get_siguiente();
		}
		

	}
	return list3;
}
template<class T>
void List<T>::crop(Nodo<T>* cabeza, int* excepciones,int tamanio)
{
	Operation op;
	
	Nodo<T> *aux=nullptr;
	int cont_borrados = 0;
	int indice = 0;
	int newe = 0;
	while (cabeza) {
		
		if (!op.verificar_en_arreglo(excepciones,indice,tamanio)) {
			
			aux= cabeza->get_siguiente();
			newe = indice - cont_borrados;
			
			this->borrar_por_indice(newe);
			
			cont_borrados++;
			cabeza = aux;
			
		}
		else {
			cabeza = cabeza->get_siguiente();
		}
		indice++;
		

	}

}
template<class T>
void List<T>::eliminar(List<List<int>> c, int dato)
{
	
	/*if (c) {
		
		eliminar_lista_simple(c->get_dato(), dato);
		cout << "otra lista" << endl;
		if (c->get_siguiente()) {
			eliminar(c->get_siguiente(), dato);
		}
		
	}
	
		cout << "acabo" << endl;*/
	Nodo<List<int>>* temp = c.get_primero();
	while (temp) {
		
		eliminar_lista_simple(temp->get_dato(), dato);
		
		temp = temp->get_siguiente();
	}
	return;
		
	
}
template<class T>
void List<T>::eliminar_lista_simple(List<int> list, int dato)
{
	Nodo<int>* temp = list.get_primero();
	int indice = 0;
	Nodo<int>* aux=nullptr;
	while (temp) {
		if (temp->get_dato() == dato) {
			
			aux= temp->get_siguiente();
			list.borrar_por_indice(indice);
			temp = aux;
			indice--;
		}
		else {
			
			temp = temp->get_siguiente();
		}
		indice++;
		
	}
	return;

}
template<class T>
void List<T>::imprimir_lista_compuesta(Nodo<List<int>>* c)
{
	if (c) {
		c->get_dato().recorrer_print(c->get_dato().get_primero());
		imprimir_lista_compuesta(c->get_siguiente());
	}
	else {
		cout << endl;
		return;
	}
}