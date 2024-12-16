template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

bool search(LinkedListNode<int> *head, int value)
{
    if (value < -5000 || value > 5000)
        return false;

    auto currentNode = head;
    int count = 0;
    while (currentNode != nullptr)
    {
        if (count > 500)
            return false;

        if (currentNode->data == value)
            return true;

        currentNode = currentNode->next;
    }

    return false;
}