#include <unordered_set>
#include "LinkedList.cpp"
using namespace std;

bool DetectCycle(EduLinkedListNode<int> *head)
{
    unordered_set<int> uniqueNodes;
    auto temNode = head;
    while (temNode != nullptr)
    {
        if (uniqueNodes.find(temNode->data) != uniqueNodes.end())
            return true;

        uniqueNodes.insert(temNode->data);
        temNode = temNode->next;
    }

    return false;
}