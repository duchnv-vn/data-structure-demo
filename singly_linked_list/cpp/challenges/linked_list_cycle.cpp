#include "EduLinkedList.cpp"

bool detectCycle(EduLinkedListNode *head)
{
    auto currNode = head;
    int count = 0;
    while (currNode != nullptr)
    {
        auto checkNode = head;
        for (int i = 0; i < count; i++)
        {
            if (checkNode->data == currNode->data)
                return true;

            checkNode = checkNode->nextElement;
        }

        currNode = currNode->nextElement;
        count++;
    }

    return false;
}