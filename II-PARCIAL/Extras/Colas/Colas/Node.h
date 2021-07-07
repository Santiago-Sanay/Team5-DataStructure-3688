#pragma once
template <typename T>
class Node {
private:
	T data;
	Node<T>*  next;
public:
	Node<T>() = default;
	Node<T>(T, Node*);
	T get_dato();
	void set_dato(T);
	Node<T>* get_siguiente();
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