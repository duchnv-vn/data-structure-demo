

template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

LinkedListNode<int> *RemoveDuplicates(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prevNode = nullptr;
    auto currNode = head;
    int count = 0;
    while (currNode != nullptr)
    {
        auto scanNode = head;
        bool isDuplicate = false;
        for (int i = 0; i < count; i++)
        {
            if (currNode->data == scanNode->data)
            {
                isDuplicate = true;
                break;
            }

            scanNode = scanNode->next;
        }

        if (isDuplicate)
        {
            auto tempNode = currNode;
            prevNode->next = currNode->next;
            currNode = currNode->next;
            delete tempNode;
        }
        else
        {
            prevNode = currNode;
            currNode = currNode->next;
            count++;
        }
    }

    return head;
}