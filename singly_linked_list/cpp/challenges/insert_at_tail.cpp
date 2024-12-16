#include <iostream>

template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

LinkedListNode<int> *InsertAtTail(LinkedListNode<int> *head, int value)
{

    if (value < -5e3 || value > 5e3)
        return nullptr;

    auto *newNode = new LinkedListNode<int>{value};

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        auto tempNode = head;
        int count = 0;
        while (tempNode->next != nullptr)
        {
            if (++count > 5e2)
                return nullptr;

            tempNode = tempNode->next;
        }

        tempNode->next = newNode;
    }

    return head;
}
