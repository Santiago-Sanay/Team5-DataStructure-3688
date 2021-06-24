#pragma once

template <class T>
class Node
{
private:
    T _data;
    Node<T> *_next = nullptr;

public:
    Node<T>() = default;
    Node<T>(T);
    void set_data(T);
    void set_next(Node<T> *);
    T get_data() const;
    Node<T> *get_next() const noexcept;
};

template <class T>
Node<T>::Node(T _value) : _data(_value)
{
}

template <class T>
void Node<T>::set_data(T _value)
{
    this->_data = _value;
}

template <class T>
void Node<T>::set_next(Node<T> *_next_node)
{
    this->_next = _next_node;
}

template <class T>
T Node<T>::get_data() const
{
    return this->_data;
}

template <class T>
Node<T> *Node<T>::get_next() const noexcept
{
    return _next;
}