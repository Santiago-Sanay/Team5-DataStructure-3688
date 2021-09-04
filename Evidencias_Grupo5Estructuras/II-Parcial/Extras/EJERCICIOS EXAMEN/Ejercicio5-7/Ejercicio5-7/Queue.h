/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: 5.	Defina una función que reciba una Pila como parámetro y devuelva la cantidad de elementos que tiene, sin alterar el orden o la cantidad de elementos que contenga.
6.	Defina la clase ListaMixta, la que implementa los métodos push, pop, desencolar y encolar, y opera sobre una misma lista de elementos. Para efectos de implementación considere que la extracción de elementos se hace desde el inicio de la lista.
7.	Se insertan mediante push() en una pila, los siguientes elementos (en este orden):
1, 40, 2, 50, 3, 60, 45, 33, 65, 21, 19, 4,  5
Luego la pila es vaciada, y a medida que los elementos son extraídos, los elementos pares se insertan en una cola mediante encolar() y los impares se insertan en otra pila.
*FECHA DE CREACION : 04 DE AGOSTO DEL 2021
*FECHA DE MODIFICACION: 04 DE AGOSTO 2021
*/
#pragma once
#include "Node.h"
#include<functional>
using namespace std;
template<typename T>
class Queue {
private:
	Node<T>* head = nullptr;
	Node<T>* back= nullptr;
	int size = 0;
public:
	Queue<T>() = default;
	void encolar(T);
	void desencolar();
	void mostrar();
	bool es_vacia();
	int get_size();
	Node<T>* get_head();
	Node<T>* get_back();
	void recorrer(std::function<int()>recorrido);
	void modify(T data);
	void modify_for_index(T data, int);
	T search(int);
};

template<typename T>
inline Node<T>* Queue<T>::get_head()
{
	return this->head;
}

template<typename T>
inline Node<T>* Queue<T>::get_back()
{
	return this->back;
}

template<typename T>
inline void Queue<T>::recorrer(std::function<int()> recorrido)
{
	Node<T>* tmp = head;	
	int indice = 0;
	while (tmp != NULL) {
		recorrido();
		tmp = tmp->get_siguiente();
	}
}

template<class T>
bool Queue<T>::es_vacia()
{
	return (this->head == nullptr);
}

template<typename T>
inline int Queue<T>::get_size()
{
	return this->size;
}

template<typename T>
inline void Queue<T>::encolar(T _data)
{
	Node<T>* node = new Node<T>();
	node->set_dato(_data);
	node->set_siguiente(nullptr);
	if (head == nullptr)
		head = node;
	else
		back->set_siguiente(node);
	back = node;
	size++;
}

template<typename T>
inline void Queue<T>::desencolar()
{
	Node<T>* aux = new Node<T>();
	aux = this->head;
	head = head->get_siguiente();	
	delete(aux);
	size--;
}

template<typename T>
inline void Queue<T>::mostrar()
{
	Node<T>* aux = new Node<T>();
	aux = head;
	while (aux!=nullptr) {
		cout << aux->get_dato() << "->";
		aux = aux->get_siguiente();
	}	
	cout << "Null";
}

template<typename T>
inline void Queue<T>::modify(T data)
{
	Node<T>* temp = head;
	while (temp!=nullptr)
	{
		if (data==temp->get_dato())
		{
			break;
		}
		temp = temp->get_siguiente();
	}
	temp->set_dato(data);
}

template<typename T>
inline void Queue<T>::modify_for_index(T data, int index)
{
	Node<T>* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->get_siguiente();
	}
	temp->set_dato(data);
}

template<typename T>
inline T Queue<T>::search(int indice)
{
	if (indice >= size || indice < 0) {
		cout << "Indice fuera de rango" << endl;		
	}
	Node<T>* tmp = head;

	int indice1 = 0;
	while (indice != indice1) {
		tmp = tmp->get_siguiente();
		indice1++;
	}
	return tmp->get_dato();
}
