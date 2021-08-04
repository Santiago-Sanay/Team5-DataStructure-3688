#pragma once
#include "Stack.h"
#include "Queue.h"

template <typename T>
class Operation {
public:
	int contarElementos(Stack<T>);
	void pilaCola(Stack<T>&, Queue<T>&, Stack<T>&);
};

template<typename T>
inline int Operation<T>::contarElementos(Stack<T> stack)
{
	int cont=0;
	Node<T>* temporal = stack.top();
	//la direccion le apunta a primero
	while (temporal) {
		cont++; 
		temporal = temporal->get_siguiente();
	}
	return cont;
}

template<typename T>
inline void Operation<T>::pilaCola(Stack<T> &stack, Queue<T>& queue, Stack<T> &newStack)
{
	Node<T>* temp = stack.top();
	while (temp)
	{
		if ((temp->get_dato() % 2) == 0) {
			queue.encolar(temp->get_dato());			
		}
		else {
			newStack.push(temp->get_dato());
		}
		temp = temp->get_siguiente();
	}
}

