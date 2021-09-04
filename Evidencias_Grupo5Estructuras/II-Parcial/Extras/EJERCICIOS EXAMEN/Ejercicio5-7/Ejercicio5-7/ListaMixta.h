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
#include "Queue.h"
#include "Stack.h"
template<typename T>
class ListaMixta {
private: 
	Node<T>* back = NULL;
	Node<T>* _top = NULL;
	Node<T>* actual = NULL;
public:
	ListaMixta() = default;
	void push(T);
	bool empty();
	void pop();
	void mostrar();
	void encolar(T);
	void desencolar();
};

template<typename T>
inline bool ListaMixta<T>::empty()
{
	return (this->_top == NULL);
}

template<typename T>
inline void ListaMixta<T>::pop()
{
	Node<T>* temp = this->actual;
	Node<T>* temp1 = this->_top;
	while (temp1->get_siguiente()->get_siguiente() != NULL) {
		temp1 = temp1->get_siguiente();
	}
	temp1->set_siguiente(NULL);
	this->actual = temp1;
	free(temp);
}

template<typename T>
inline void ListaMixta<T>::push(T _data)
{
	Node<T>* nuevo = new Node<T>(_data, NULL);
	if (empty()) {
		this->_top = nuevo;
	}
	else {
		this->actual->set_siguiente(nuevo);
	}
	this->actual = nuevo;
}

template<typename T>
inline void ListaMixta<T>::encolar(T _data)
{
	Node<T>* node = new Node<T>();
	node->set_dato(_data);
	node->set_siguiente(nullptr);
	if (_top == nullptr)
		_top = node;
	else
		back->set_siguiente(node);
	back = node;
}

template<typename T>
inline void ListaMixta<T>::desencolar()
{
	Node<T>* aux = new Node<T>();
	aux = this->_top;
	_top = _top->get_siguiente();
	delete(aux);	
}

template<typename T>
inline void ListaMixta<T>::mostrar()
{
	Node<T>* aux = new Node<T>();
	aux = _top;
	while (aux != nullptr) {
		cout << " " << aux->get_dato();
		aux = aux->get_siguiente();
	}
}
