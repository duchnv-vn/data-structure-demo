#include <iostream>
#include "single_linked_list.h"
using namespace std;

template <class T>
single_linked_list<T>::single_linked_list(T data)
{
    Node<T> *node = new Node<T>(data);
    head = node;
};

template <class T>
bool single_linked_list<T>::insert_to_head(T data)
{
    Node<T> *newHead = new Node<T>(data, head);
    head = newHead;
    return true;
};

template <class T>
void single_linked_list<T>::forEach(void (*callback_ptr)(T data))
{
    Node<T> *tempNode = head;
    while (tempNode != nullptr)
    {
        callback_ptr(tempNode->data);
        tempNode = tempNode->next;
    }
}

template <class T>
void print_list(T data)
{
    cout << "data: " << data << endl;
}

int main()
{
    single_linked_list<int> list1(2);
    list1.insert_to_head(1);
    list1.insert_to_head(0);
    list1.forEach(print_list);
}