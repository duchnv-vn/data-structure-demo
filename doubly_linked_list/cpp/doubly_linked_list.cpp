#include "doubly_linked_list.h"

template <class T>
Node<T>::Node(T d, Node<T> *p = nullptr, Node<T> *n = nullptr)
{
    data = d;
    previous = p;
    next = n;
}

template <class T>
doubly_linked_list<T>::doubly_linked_list(T data)
{
    head = new Node<T>(data);
    tail = head;
}