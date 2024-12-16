template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

int Length(LinkedListNode<int> *head)
{

    if (head == nullptr)
        return 0;

    auto currentNode = head;
    int count = 0;
    while (currentNode != nullptr)
    {
        currentNode = currentNode->next;
        count++;
    }

    return count;
}