class DoublyLinkedListNode
{
public:
    int data;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;

    DoublyLinkedListNode(int data, DoublyLinkedListNode *prev, DoublyLinkedListNode *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    DoublyLinkedListNode(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};