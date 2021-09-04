#pragma once
#include "Node.h"
class Stack
{
public:
	Stack();
	char top();
	void push(const char c);
	bool empty();
	void pop();
private:
	Node* top_ = nullptr;
};

