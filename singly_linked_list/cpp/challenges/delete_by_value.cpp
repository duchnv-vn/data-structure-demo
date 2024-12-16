template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

bool Delete(LinkedListNode<int> *head, int value)
{
    if (head == nullptr)
        return false;

    auto currentNode = head;
    while (currentNode->next != nullptr)
    {
        if (currentNode->next->data == value)
        {
            auto tempNode = currentNode->next;
            currentNode->next = tempNode->next;
            delete tempNode;
            return true;
        }

        currentNode = currentNode->next;
    }

    return false;
}