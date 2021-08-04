#include <iostream>
#include "queue.h"
int main(int, char **)
{
    Queue<int> q;

    q.push(3);
    q.push(2);
     q.push(4);
    q.push(9);
    q.push(11);
    q.push(0);
    q.push(7);
    q.push(6);
    q.for_each([](Node<int> *i)
               { std::cout << i->get_data() << ","; });
               

    /*DoublyLinkedList<int> q;
    q.push_back(3);
    q.push_back(2);
    q.push_back(4);
    q.push_back(9);
    q.push_at(2, 6);
    q.push_at(5, 7);
    q.for_each([](Node<int> *i)
               { std::cout << i->get_data() << ","; });*/
}
