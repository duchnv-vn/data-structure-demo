#include "DoublyLinkedListNode.cpp"

bool isPalindrome(DoublyLinkedListNode *head)
{

    DoublyLinkedListNode *tail = nullptr;
    int size = 0;
    auto currNodeFromHead = head;
    while (currNodeFromHead != nullptr)
    {
        if (currNodeFromHead->next == nullptr)
            tail = currNodeFromHead;

        currNodeFromHead = currNodeFromHead->next;
        size++;
    }

    bool isPalindrome = true;
    currNodeFromHead = head;
    auto currNodeFromTail = tail;
    for (int i = 0; i < (size / 2); i++)
    {
        if (currNodeFromHead->data != currNodeFromTail->data)
        {
            isPalindrome = false;
            break;
        }

        currNodeFromHead = currNodeFromHead->next;
        currNodeFromTail = currNodeFromTail->prev;
    }

    return isPalindrome;
}
