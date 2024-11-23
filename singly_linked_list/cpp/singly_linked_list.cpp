#include <iostream>
#include "singly_linked_list.h"
using namespace std;

template <class T>
singly_linked_list<T>::singly_linked_list(T data)
{
    Node<T> *node = new Node<T>(data);
    head = node;
};

template <class T>
singly_linked_list<T>::~singly_linked_list()
{
    while (head != nullptr)
        remove_head();
}

template <class T>
void singly_linked_list<T>::forEach(void (*callback_ptr)(T data))
{
    Node<T> *tempNode = head;
    while (tempNode != nullptr)
    {
        callback_ptr(tempNode->data);
        tempNode = tempNode->next;
    }
}

template <class T>
bool singly_linked_list<T>::insert_to_head(T data)
{
    Node<T> *newHead = new Node<T>(data, head);
    head = newHead;
    return true;
};

template <class T>
bool singly_linked_list<T>::insert_to_last(T data)
{
    Node<T> *tempNode = head;
    while (tempNode->next != nullptr)
    {
        tempNode = tempNode.next;
    }

    Node<T> *newTail = new Node<T>(data);
    tempNode->next = newTail;
    return true;
}

template <class T>
bool singly_linked_list<T>::insert_by_index(int index, T data)
{
    int count = 0;
    Node<T> *tempNode = head;

    while (tempNode->next != nullptr)
    {
        if ((count + 1) == index)
        {
            Node<T> *newNode = new Node<T>(data);
            newNode->next = tempNode->next;
            tempNode->next = newNode;
            return true;
        }

        count++;
        tempNode = tempNode->next;
    }

    return false;
}

template <class T>
bool singly_linked_list<T>::update_by_index(int index, T new_data)
{
    int count = 0;
    Node<T> *tempNode = head;

    while (tempNode != nullptr)
    {
        if (count == index)
        {
            tempNode->data = new_data;
            return true;
        }

        count++;
        tempNode = tempNode->next;
    }

    return false;
}

template <class T>
bool singly_linked_list<T>::update_many_by_value(T value, T new_data)
{
    Node<T> *tempNode = head;

    while (tempNode != nullptr)
    {
        if (tempNode->data == value)
        {
            tempNode->data = new_data;
        }

        tempNode = tempNode->next;
    }

    return true;
}

template <class T>
bool singly_linked_list<T>::remove_head()
{
    if (head->next == nullptr)
        return false;

    Node<T> *oldHead = head;
    head = head->next;
    delete oldHead;
    return true;
}

template <class T>
bool singly_linked_list<T>::remove_last()
{
    Node<T> *tempNode = head;

    while (tempNode->next->next != nullptr)
    {
        tempNode = tempNode->next;
    }

    delete tempNode->next;
    tempNode->next = nullptr;
    return true;
}

template <class T>
bool singly_linked_list<T>::remove_by_index(int index)
{
    Node<T> *tempNode = head;
    int count = 0;

    while (tempNode->next->next != nullptr)
    {
        if ((count + 1) == index)
        {
            Node<T> *deleteNode = tempNode->next;
            tempNode->next = tempNode->next->next;
            delete deleteNode;
            return true;
        }

        count++;
        tempNode = tempNode->next;
    }

    return false;
}

template <class T>
bool singly_linked_list<T>::remove_many_by_value(T value)
{
    Node<T> *tempNode = head;

    while (tempNode->next->next != nullptr)
    {
        if (tempNode->next->data == value)
        {
            Node<T> *deleteNode = tempNode->next;
            tempNode->next = tempNode->next->next;
            delete deleteNode;
            return true;
        }

        tempNode = tempNode->next;
    }

    return false;
}

template <class T>
T singly_linked_list<T>::search_by_index(int index)
{
    Node<T> *tempNode = head;
    int count = 0;

    while (tempNode != nullptr)
    {
        if (count == index)
            return tempNode;

        count++;
        tempNode = tempNode->next;
    }
}
