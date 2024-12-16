#ifndef QUEUE_H
#define QUEUE_H

#include "doubly_linked_list/cpp/doubly_linked_list.h"

template <typename T>
class Queue
{
private:
    int size;
    T *items;

public:
    Queue()
    {
        size = 0;
    };

    ~Queue() {};

    bool enqueue(T value) {};

    bool dequeue() {};

    bool isEmpty() {};

    T getFront() {};
};

#endif // QUEUE_H
