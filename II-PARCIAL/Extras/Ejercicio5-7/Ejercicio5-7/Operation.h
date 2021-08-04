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

