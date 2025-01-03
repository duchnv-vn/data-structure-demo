#include <unordered_set>
using namespace std;
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
    if (head == nullptr || head->next == nullptr)
        return head;

    unordered_set<int> uniqueNodes;
    auto newHead = new LinkedListNode<int>{head->data};
    uniqueNodes.insert(head->data);
    auto tempNewNode = newHead;

    auto tempNode = head->next;
    while (tempNode != nullptr)
    {
        if (uniqueNodes.find(tempNode->data) == uniqueNodes.end())
        {
            tempNewNode->next = new LinkedListNode<int>{tempNode->data};
            tempNewNode = tempNewNode->next;
            uniqueNodes.insert(tempNode->data);
        }

        tempNode = tempNode->next;
    }

    return newHead;
}
