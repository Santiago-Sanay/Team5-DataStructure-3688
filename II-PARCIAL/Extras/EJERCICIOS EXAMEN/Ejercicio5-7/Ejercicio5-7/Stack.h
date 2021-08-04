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
#include <iostream>
#include "Node.h"
using namespace std;
template <typename T>
class Stack
{
public:
/**
 * @brief Construct a new Stack object
 * 
 */
	Stack();
	/**
	 * @brief returns the start of a stack
	 * 
	 * @return Node<T>* 
	 */
	Node<T>* top();
	/**
	 * @brief add a element in the stack
	 * 
	 */
	void push(T);
	/**
	 * @brief verify the stack is empty
	 * 
	 * @return true 
	 * @return false 
	 */
	bool empty();
	/**
	 * @brief delete a element in stack
	 * 
	 */
	void pop();
	/**
	 * @brief print all elements
	 * 
	 */
	void mostrar();
private:
	Node<T>* _top = nullptr;
	Node<T>* actual = nullptr;
};

template<typename T>
inline Stack<T>::Stack()
{
	_top = nullptr;
}

template<typename T>
inline Node<T>* Stack<T>::top()
{
	if (_top != nullptr) {
		return _top;
	}
	else {
		return nullptr;
	}
}

template<typename T>
inline void Stack<T>::push(T _data)
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
inline bool Stack<T>::empty()
{
	return (this->_top == NULL);
}

template<typename T>
inline void Stack<T>::pop()
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
inline void Stack<T>::mostrar()
{
	Node<T>* temporal = this->_top;
	//la direccion le apunta a primero
	while (temporal) {
		cout << temporal->get_dato() << "->";
		temporal = temporal->get_siguiente();

	}
	cout << "NULL\n";
}

