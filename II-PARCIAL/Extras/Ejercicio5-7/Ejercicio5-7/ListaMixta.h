#pragma once
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
template<typename T>
class ListaMixta {
private: 
	Node<T>* back = NULL;
	Node<T>* _top = NULL;
	Node<T>* actual = NULl;
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
