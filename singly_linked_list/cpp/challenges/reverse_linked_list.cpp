template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

LinkedListNode<int> *Reverse(LinkedListNode<int> *head)
{
    auto currNode = head;
    LinkedListNode<int> *newHead = nullptr;

    while (currNode != nullptr)
    {
        auto newNode = new LinkedListNode<int>{currNode->data};
        newNode->next = newHead;
        newHead = newNode;

        currNode = currNode->next;
    }

    return newHead;
}