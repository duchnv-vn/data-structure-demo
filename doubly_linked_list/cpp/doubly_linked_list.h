#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> previous;
    Node<T> next;

    Node(T d, Node<T> *p = nullptr, Node<T> *n = nullptr) : data{d}, previous{p}, next{n} {};
};

template <class T>
class doubly_linked_list
{
    Node<T> *head;
    Node<T> *tail;

public:
    doubly_linked_list()
    {
        head = nullptr;
        tail = nullptr;
    };

    void forEach(bool fromHead, void (*callback_ptr)(T data))
    {
        if (head == nullptr)
        {
            cout << "EMPTY LIST" << endl;
            return;
        }

        Node<T> *tempNode = fromHead ? head : tail;
        while (tempNode != nullptr)
        {
            callback_ptr(tempNode->data);
            tempNode = fromHead ? tempNode->next : tempNode->previous;
        }
    };

    T search_by_index(int index)
    {
        if (head == nullptr)
        {
            cout << "EMPTY LIST" << endl;
            return;
        }

        int count = 0;
        Node<T> *tempNode = head;
        while (tempNode != nullptr)
        {
            if (count == index)
                return tempNode;

            tempNode = tempNode->next;
            count++;
        }
    };

    bool insert_to_head(T data)
    {
        Node<T> newNode = {data, nullptr, head};

        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            head->previous = &newNode;
            head = newNode;
        }

        return true
    };

    bool insert_to_tail(T data)
    {
        if (head == nullptr)
            return insert_to_head(data);

        Node<T> newNode = {data, tail, nullptr};
        tail->next = &newNode;
        tail = newNode;

        return true;
    };

    bool insert_by_index(int index, T data)
    {
        if (/* condition */)
        {
            /* code */
        }
    };

    bool update_by_index(int index, T data) {};

    bool update_many_by_value(T value, T data) {};

    bool remove_head() {};

    bool remove_tail() {};

    bool remove_by_index(int index) {};

    bool remove_many_by_value(T value) {};
};

#endif // DOUBLY_LINKED_LIST_H
