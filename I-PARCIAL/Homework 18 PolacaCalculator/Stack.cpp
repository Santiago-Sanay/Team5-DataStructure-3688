#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    top_ = nullptr;
}

char Stack::top()
{
    if (top_ != nullptr) {
        return top_->getChar();
    }
    else {
        return 0;
    }
}

void Stack::push(const char c)
{
    Node* nodo = new Node(c);
    nodo->setNext(top_);
    top_ = nodo;
}

bool Stack::empty()
{
    if (top_ == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::pop()
{
    if (top_ != nullptr) {
        Node* n = top_;
        top_ = top_->getNext();
        delete n;
    }
}
