#pragma once
class Node
{
public:
	Node(const char c);
	Node* getNext();
	char getChar();
	void setNext(Node*);
private:
	char a = 0;
	Node* next= nullptr;
};

