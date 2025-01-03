#include <unordered_set>
#include <unordered_map>
using namespace std;

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
    unordered_set<int> uniqueNodes;
    LinkedListNode<int> *newHead = nullptr;
    auto tempNewNode = newHead;

    auto heads = new LinkedListNode<int> *[2]{head1, head2};
    for (auto i = 0; i < 2; i++)
    {
        auto tempNode = heads[i];
        while (tempNode != nullptr)
        {
            if (uniqueNodes.find(tempNode->data) == uniqueNodes.end())
            {
                auto newNode = new LinkedListNode<int>{tempNode->data};
                if (tempNewNode == nullptr)
                {
                    newHead = newNode;
                    tempNewNode = newNode;
                }
                else
                {
                    tempNewNode->next = newNode;
                    tempNewNode = newNode;
                }

                uniqueNodes.insert(newNode->data);
            }

            tempNode = tempNode->next;
        }
    }

    return newHead;
}

LinkedListNode<int> *Intersection(LinkedListNode<int> *head1, LinkedListNode<int> *head2)
{
    unordered_set<int> intersectionSet;

    unordered_set<int> set1;
    auto tempNode1 = head1;
    while (tempNode1 != nullptr)
    {
        set1.insert(tempNode1->data);
        tempNode1 = tempNode1->next;
    }

    unordered_set<int> set2;
    auto tempNode2 = head2;
    while (tempNode2 != nullptr)
    {
        set2.insert(tempNode2->data);
        tempNode2 = tempNode2->next;
    }

    for (int node : set2)
    {
        if (set1.find(node) != set1.end())
            intersectionSet.insert(node);
    }

    LinkedListNode<int> *newHead = nullptr;
    auto tempNewNode = newHead;

    for (int data : intersectionSet)
    {
        auto newNode = new LinkedListNode<int>(data);
        if (newHead == nullptr)
        {
            newHead = newNode;
            tempNewNode = newNode;
        }
        else
        {
            tempNewNode->next = newNode;
            tempNewNode = newNode;
        }
    }

    return newHead;
}
