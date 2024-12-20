#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "DoublyLinkedListNode.cpp"

class DoublyLinkedList
{
public:
    DoublyLinkedListNode *head;

    DoublyLinkedList()
    {
        this->head = nullptr;
    }

    void insertNodeAtHead(DoublyLinkedListNode *node)
    {
        if (head != nullptr)
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
        else
        {
            head = node;
        }
    }

    void createLinkedList(std::vector<int> &lst)
    {
        for (int i = lst.size() - 1; i >= 0; i--)
        {
            DoublyLinkedListNode *newNode = new DoublyLinkedListNode(lst[i]);
            insertNodeAtHead(newNode);
        }
    }

    std::string toString()
    {
        std::stringstream result;
        DoublyLinkedListNode *temp = head;
        while (temp != nullptr)
        {
            result << temp->data;
            temp = temp->next;
            if (temp != nullptr)
            {
                result << ", ";
            }
        }
        return result.str();
    }
};