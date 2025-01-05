#include <iostream>
using namespace std;

class Node
{
public:
    int data;          // Data to store (could be int,string,object etc)
    Node *nextElement; // Pointer to next element
    Node *previousElement;

    Node(int data)
    {
        // Constructor to initialize nextElement of newlyCreated Node
        this->data = data;
        nextElement = nullptr;
        previousElement = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    int size;

    DoublyLinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    };

    ~DoublyLinkedList()
    {
        auto currNode = head;
        while (currNode != nullptr)
        {
            auto deleteNode = currNode;
            currNode = currNode->nextElement;
            delete deleteNode;
        }
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getHead()
    {
        return size > 0 ? head->data : -1;
    }

    int getTail()
    {
        return size > 0 ? tail->data : -1;
    }

    int printList()
    {
        if (isEmpty())
        {
            cout << "List is Empty!" << endl;
            return false;
        }

        auto currNode = head;
        cout << "List : ";
        while (currNode != nullptr)
        {
            cout << currNode->data << "->";
            currNode = currNode->nextElement;
        }
        cout << "null" << endl;

        return true;
    }

    int insertTail(int value)
    {
        auto newNode = new Node{value};

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->previousElement = tail;
            tail->nextElement = newNode;
            tail = newNode;
        }

        size++;
        return value;
    }

    bool deleteHead()
    {
        if (isEmpty())
            return false;

        auto deleteNode = head;
        if (size == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->nextElement;
            head->previousElement = nullptr;
        }

        delete deleteNode;
        size--;
        return true;
    }

    bool deleteTail()
    {
        if (isEmpty())
            return false;

        auto deleteNode = tail;
        if (size == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->previousElement;
            tail->nextElement = nullptr;
        }

        delete deleteNode;
        size--;
        return true;
    }
};