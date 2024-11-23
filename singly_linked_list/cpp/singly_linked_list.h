#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T d, Node<T> *n = nullptr)
    {
        data = d;
        next = n;
    }
};

template <class T>
class singly_linked_list
{
    Node<T> *head;

public:
    singly_linked_list(T data);

    ~singly_linked_list();

    bool insert_to_head(T data);

    bool insert_to_last(T data);

    bool insert_by_index(int index, T data);

    bool update_by_index(int index, T new_data);

    bool update_many_by_value(T value, T new_data);

    bool remove_head();

    bool remove_last();

    bool remove_by_index(int index);

    bool remove_many_by_value(T value);

    void forEach(void (*callback_ptr)(T data));

    T search_by_index(int index);
};

#endif // SINGLY_LINKED_LIST_H