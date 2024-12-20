template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

LinkedListNode<int> *Union(LinkedListNode<int> *head1, LinkedListNode<int> *head2)
{
    auto newHead = head1;
    auto currNode2 = head2;
    while (currNode2 != nullptr)
    {
        bool isDuplicate = false;
        auto currNode1 = head1;
        while (currNode1 != nullptr)
        {
            if (currNode2->data == currNode1->data)
            {
                isDuplicate = true;
                break;
            }

            currNode1 = currNode1->next;
        }

        if (!isDuplicate)
        {
            auto newNode = new LinkedListNode<int>{currNode2->data};
            newNode->next = newHead;
            newHead = newNode;
        }

        currNode2 = currNode2->next;
    }

    return newHead;
}

LinkedListNode<int> *Intersection(LinkedListNode<int> *head1, LinkedListNode<int> *head2)
{
    LinkedListNode<int> *newHead = nullptr;
    auto currNode2 = head2;
    while (currNode2 != nullptr)
    {
        bool isDuplicate = false;
        auto currNode1 = head1;
        while (currNode1 != nullptr)
        {
            if (currNode2->data == currNode1->data)
            {
                isDuplicate = true;
                break;
            }

            currNode1 = currNode1->next;
        }

        if (isDuplicate)
        {
            auto newNode = new LinkedListNode<int>{currNode2->data};
            newNode->next = newHead;
            newHead = newNode;
        }

        currNode2 = currNode2->next;
    }

    return newHead;
}