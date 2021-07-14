/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROGRAMA DE COLAS
*FECHA DE CREACION : 05 DE JULIO DE 2021
*FECHA DE MODIFICACION: 11 DE JULIO 2021
*/
#pragma once
template <typename T>
class Node {
private:
	T data;
	Node<T>*  next;
public:
	/**
	 * @brief Construct a new Node< T> object
	 * 
	 */
	Node<T>() = default;
	/**
	 * @brief Construct a new Node< T> object
	 * 
	 */
	Node<T>(T, Node*);
	/**
	 * @brief Get the dato object
	 * 
	 * @return T 
	 */
	T get_dato();
	/**
	 * @brief Set the dato object
	 * 
	 */
	void set_dato(T);
	/**
	 * @brief Get the siguiente object
	 * 
	 * @return Node<T>* 
	 */
	Node<T>* get_siguiente();
	/**
	 * @brief Set the siguiente object
	 * 
	 */
	void set_siguiente(Node*);
};

template<class T>
Node<T>::Node(T val, Node* sig)
{
	sig = NULL;
	this->data = val;
	this->next = sig;
}
template<class T>
T Node<T>::get_dato()
{
	return this->data;
}

template<class T>
void Node<T>::set_dato(T val)
{
	this->data = val;
}


template<class T>
Node<T>* Node<T>::get_siguiente()
{
	return this->next;
}
template<class T>
void Node<T>::set_siguiente(Node<T>* nuevo)
{
	this->next = nuevo;
}