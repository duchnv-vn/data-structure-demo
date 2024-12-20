template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

LinkedListNode<int> *FindNth(LinkedListNode<int> *head, int n)
{

    int size = 0;
    auto currNode = head;
    while (currNode != nullptr)
    {
        size++;
        currNode = currNode->next;
    }

    if (n > size)
        return nullptr;

    currNode = head;
    for (int i = 0; i < size; i++)
    {
        if ((size - n) == i)
            return currNode;

        currNode = currNode->next;
    }

    return nullptr;
}