template <typename T>
struct EduLinkedListNode
{
    T data;
    EduLinkedListNode *next;
    EduLinkedListNode(T value) : data(value), next(nullptr) {}
};