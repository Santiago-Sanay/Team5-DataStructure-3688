/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SA�AY
*TEMA: 5.	Defina una funci�n que reciba una Pila como par�metro y devuelva la cantidad de elementos que tiene, sin alterar el orden o la cantidad de elementos que contenga.
6.	Defina la clase ListaMixta, la que implementa los m�todos push, pop, desencolar y encolar, y opera sobre una misma lista de elementos. Para efectos de implementaci�n considere que la extracci�n de elementos se hace desde el inicio de la lista.
7.	Se insertan mediante push() en una pila, los siguientes elementos (en este orden):
1, 40, 2, 50, 3, 60, 45, 33, 65, 21, 19, 4,  5
Luego la pila es vaciada, y a medida que los elementos son extra�dos, los elementos pares se insertan en una cola mediante encolar() y los impares se insertan en otra pila.
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
	/**
	 * @brief Construct a new Lista Mixta object
	 * 
	 */
	ListaMixta() = default;
	/**
	 * @brief add elements in the stack
	 * 
	 */
	void push(T);
	/**
	 * @brief verify queue is empty
	 * 
	 * @return true 
	 * @return false 
	 */
	bool empty();
	/**
	 * @brief delete element in the stack
	 * 
	 */
	void pop();
	/**
	 * @brief print all elements in the stack
	 * 
	 */
	void mostrar();
	/**
	 * @brief add element in the queue
	 * 
	 */
	void encolar(T);
	/**
	 * @brief delete a element in the queue
	 * 
	 */
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
