#include "LinkedListNode.cpp"
template <typename T>
class EduLinkedList
{
public:
    EduLinkedListNode<T> *head;

    EduLinkedList() : head(nullptr) {}

    void CreateLinkedList(std::vector<T> &list)
    {
        for (const T &item : list)
        {
            InsertNode(item);
        }
    }

    void InsertNode(T value)
    {
        EduLinkedListNode<T> *newNode = new EduLinkedListNode<T>(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            EduLinkedListNode<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // returns the number of nodes in the linked list
    int GetLength(EduLinkedListNode<int> *h)
    {
        EduLinkedListNode<int> *temp = h;
        int length = 0;
        while (temp != nullptr)
        {
            length += 1;
            temp = temp->next;
        }
        return length;
    }

    // returns the node at the specified position(index) of the linked list
    EduLinkedListNode<int> *GetNode(EduLinkedListNode<int> *h, int pos)
    {
        if (pos != -1)
        {
            int p = 0;
            EduLinkedListNode<int> *ptr = h;
            while (p < pos)
            {
                ptr = ptr->next;
                p += 1;
            }
            return ptr;
        }
        return h;
    }
};