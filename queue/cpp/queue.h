#ifndef QUEUE_H
#define QUEUE_H

#include "DoublyLinkedList.h"

class Queue
{
private:
    DoublyLinkedList items;

public:
    Queue()
    {
        items = *(new DoublyLinkedList{});
    };

    ~Queue() {};

    bool isEmpty()
    {
        return items.size == 0;
    }

    int getSize()
    {
        return items.size;
    }

    int getFront()
    {
        return items.getHead();
    }

    int enqueue(int value)
    {
        return items.insertTail(value);
    }

    int dequeue()
    {
        return items.deleteHead();
    }

    int getTail()
    {
        return items.getTail();
    }

    bool showqueue()
    {
        return items.printList();
    }
};

#endif // QUEUE_H
