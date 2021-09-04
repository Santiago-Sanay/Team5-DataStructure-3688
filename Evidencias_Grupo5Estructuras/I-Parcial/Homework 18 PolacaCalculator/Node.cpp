#include "Node.h"


Node::Node(const char c)
{
	this->a = c;
}

Node* Node::getNext()
{
	if (this != nullptr) {
		return next;
	}
	else
	{
		return nullptr;
	}
}

char Node::getChar()
{
	if (this != nullptr) {
		return a;
	}
	else {
		return 0;
	}
}

void Node::setNext(Node* nodo)
{
	if (this != nullptr) {
		this->next = nodo;
	}
}
