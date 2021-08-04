#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template <typename T>
class Stack
{
public:
	Stack();
	Node<T>* top();
	void push(T);
	bool empty();
	void pop();
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

