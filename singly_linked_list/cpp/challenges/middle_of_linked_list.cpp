template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

LinkedListNode<int> *FindMid1(LinkedListNode<int> *head)
{
    int len = 0;
    LinkedListNode<int> *midNode = nullptr;
    auto currNode = head;
    while (currNode != nullptr)
    {
        len++;
        int mid = len / 2;

        auto scanMidNode = head;
        for (int i = 0; i < mid; i++)
            scanMidNode = scanMidNode->next;
        midNode = scanMidNode;

        currNode = currNode->next;
    }

    return midNode;
}

LinkedListNode<int> *FindMid2(LinkedListNode<int> *head)
{
    int len = 0;
    auto currNode = head;

    while (currNode != nullptr)
    {
        len++;
        currNode = currNode->next;
    }

    int mid = len / 2;

    auto midNode = head;
    for (int i = 0; i < mid; i++)
        midNode = midNode->next;

    return midNode;
}