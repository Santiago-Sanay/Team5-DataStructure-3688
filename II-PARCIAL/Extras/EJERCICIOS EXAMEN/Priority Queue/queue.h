#pragma once
#include "doubly_linked_list.h"
#include <functional>
template <typename T>
class Queue
{
public:
    Queue() = default;
    void push(T value);
    bool is_empty();
    void for_each(std::function<void(Node<T> *)> callback);
    int size();

private:
    DoublyLinkedList<T> elements;
};

template <typename T>
void Queue<T>::push(T value)
{
    elements.push_back(value);
    elements.for_each([&](Node<T> *nodo)
                      {
                          elements.for_each([&](Node<T> *node2)
                                            {
                                                if (nodo->get_data() > node2->get_data())
                                                {
                                                    T temp = nodo->get_data();
                                                    nodo->set_data(node2->get_data());
                                                    node2->set_data(temp);
                                                }
                                            });
                      });

}

template <typename T>
bool Queue<T>::is_empty()
{
    return elements.empty();
}

template <typename T>
void Queue<T>::for_each(std::function<void(Node<T> *)> callback)
{
    elements.for_each(callback);
}

template <typename T>
int Queue<T>::size()
{
    return elements.size();
}
