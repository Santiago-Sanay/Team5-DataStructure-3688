#pragma once
#include "Node.h"
#include <functional>
#include <iostream>

template <class T>
class LinkedList
{
private:
    Node<T> *_head = nullptr;
    Node<T> *_tail = nullptr;
    int _lenght = 0;

public:
    bool is_empty();
    void add(const T element);
    void remove(const T &value);
    void remove_at(int index);
    void for_each(std::function<void(Node<T> *, int)> );
    void for_each(std::function<void(Node<T> *)> );
    void for_each(std::function<void(T, int)> );
    void for_each(std::function<void(T)>);
    int find(const int found);
    void clear();
    void print();
    Node<T> *at(int index);
    int get_size();
    Node<T>* get_front();
};

template <typename T>
void LinkedList<T>::for_each(std::function<void(Node<T> *, int)> callback)
{
    Node<T> *current = _head;
    int index = 0;

    while (current != nullptr)
    {
        callback(current, index);
        current = current->get_next();
        index++;
    }
}

template <typename T>
void LinkedList<T>::for_each(std::function<void(Node<T> *)> callback)
{
    for_each([&](Node<T> *node, int index)
             { callback(node->get_data()); });
}

template <typename T>
void LinkedList<T>::for_each(std::function<void(T)> callback)
{
    for_each([&](Node<T> *node, int index)
             { callback(node->get_data()); });
}

template <typename T>
void LinkedList<T>::for_each(std::function<void(T, int)> callback)
{
    for_each([&](Node<T> *node, int index)
             { callback(node->get_data(), index); });
}

template <class T>
bool LinkedList<T>::is_empty()
{
    return (_head == nullptr);
}
template <class T>
void LinkedList<T>::add(const T element)
{

    Node<T> *_new_node = new Node<T>(element);
    if (_head == nullptr)
    {
        _head = _new_node;
        _tail = _new_node;
    }
    else
    {
        _tail->set_next(_new_node);
        _tail = _new_node;
    }
    _lenght++;
}
template <class T>
void LinkedList<T>::remove(const T &value)
{

    int num_deleted = 0;
    Node<T> *curr = this->_head;
    Node<T> *tmp;
    while (!is_empty() && curr->get_data() == value)
    {
        tmp = curr;
        this->_head = curr->get_next();
        curr = curr->get_next();
        delete tmp;
        num_deleted++;
    }
    while (!is_empty() && curr->get_next() != nullptr)
    {
        if (curr->get_next()->get_data() == value)
        {
            tmp = curr->get_next();
            curr->set_next(curr->get_next()->get_next());
            delete tmp;
            if (curr->get_next() == nullptr)
            { // Update tail
                this->_tail = curr;
            }
            num_deleted++;
        }
        curr = curr->get_next();
    }
    if (is_empty())
    {
        this->_tail = nullptr;
    }
    if (num_deleted)
    {
        std::cout << "Se ha eliminado  " << num_deleted
                  << " nodo que contenia el valor de " << value << '.' << std::endl;
    }
    else
    {
        if (!is_empty())
        {
            std::cout << "El valor " << value << " no se ha encontrado en la lista"
                      << std::endl;
        }
        else
        {
            std::cout << "Lista Vaccia." << std::endl;
        }
    }
}

template <class T>
void LinkedList<T>::remove_at(int index)
{
    if ((index < 0) || (index >= this->_lenght))
    {
        std::cout << "Index " << index << " exccede la longitud de la lista de tamanio" << this->_lenght << '.' << std::endl;
    }
    else
    {
        Node<T> *node = this->_head;
        if (index == 0)
        { // Update head
            this->_head = node->get_next();
            delete node;
            if (is_empty())
            {
                this->_tail = nullptr;
            }
        }
        else
        {
            for (int i = 0; i < index - 1; ++i)
            {
                node = node->get_next();
            }
            Node<T> *tmp = node->get_next();
            node->set_next(node->get_next()->get_next());
            delete tmp;
            if (index == this->_lenght - 1)
            { // Update tail to point to end node
                this->_tail = node;
            }
        }
        this->_lenght--;
    }
}

template <class T>
int LinkedList<T>::find(const int find)
{
    int i = 0;
    int found = -1;
    if (is_empty())
    {
        std::cout << "Lista Vacia" << std::endl;
    }
    else
    {
        Node<T> *node = _head;
        while (node != nullptr)
        {
            if (node->get_data() == find)
            {
                found = i;
            }
            node = node->get_next();
            i++;
        }
    }
    return found;
}

template <class T>
inline void LinkedList<T>::clear()
{
    Node<T> *next = this->_head;
    Node<T> *curr = nullptr;
    while (next != nullptr)
    {
        curr = next;
        next = next->get_next();
        delete curr;
    }
    next = nullptr;
    _head = nullptr;
    _lenght = 0;
    std::cout << "Lista Eliminada." << std::endl;
}

template <class T>
void LinkedList<T>::print()
{
    if (is_empty())
    {
        std::cout << "Lista Vacia" << std::endl;
    }
    else
    {
        Node<T> *_current = this->_head;
        while (_current != nullptr)
        {
            std::cout << _current->get_data() << std::endl;
            _current = _current->get_next();
        }
    }
}

template <typename T>
Node<T> *LinkedList<T>::at(int index)
{
    if (index < 0 || index >= _lenght)
    {
        throw std::invalid_argument("index out of bounds");
    }

    if (index == 0)
    {
        return _head;
    }

    int current_index = 0;
    Node<T> *last = _head;

    while (last->get_next() != nullptr)
    {
        if (current_index == index)
        {
            break;
        }

        current_index++;
        last = last->get_next();
    }

    return last;
}

template <class T>
int LinkedList<T>::get_size()
{
    return _lenght;
}

template <class T>
Node<T>* LinkedList<T>::get_front()
{
    return _head;
}