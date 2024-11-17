#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

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
class single_linked_list
{
    Node<T> *head;

public:
    single_linked_list(T data);

    bool insert_to_head(T data);

    bool insert_to_last(T data);

    bool insert_by_index(T data);

    bool insert_to_specified_index(int index, T data);

    bool delete_first_node();

    bool delete_last_node();

    bool delete_head();

    bool delete_last();

    bool delete_by_index(int index);

    bool delete_by_value(T value);

    bool update_by_index(int index, T new_data);

    void forEach(void (*callback_ptr)(T data));

    T search_by_index(int index);
};

#endif // SINGLE_LINKED_LIST_H