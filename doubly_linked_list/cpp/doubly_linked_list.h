#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <class T>
class Node
{
public:
    T data;
    Node<T> previous;
    Node<T> next;

    Node(T d, Node<T> *p = nullptr, Node<T> *n = nullptr);
};

template <class T>
class doubly_linked_list
{
    Node<T> *head;
    Node<T> *tail;

public:
    doubly_linked_list(T data);

    void forEach(bool fromHead, void (*callback_ptr)(T data));

    T search_by_index(int index);

    bool insert_to_head(T data);

    bool insert_to_tail(T data);

    bool insert_by_index(int index, T data);

    bool update_by_index(int index, T data);

    bool update_many_by_value(T value, T data);

    bool remove_head();

    bool remove_tail();

    bool remove_by_index(int index);

    bool remove_many_by_value(T value);
};

#endif // DOUBLY_LINKED_LIST_H
