#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;

struct Node
{
    DataType data;
    struct Node *next;
};
typedef struct Node Node;

Node *create_list(DataType data)
{
    Node *head = NULL;
    head = malloc(sizeof(Node));

    if (head == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    head->data = data;
    head->next = NULL;
    return head;
}

// Used to insert without considering the order
void insert_node_to_head(Node **head, DataType data)
{
    if ((*head) == NULL)
        return;

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = data;
    new_node->next = *head; // assign next pointer value to current head pointer address
    *head = new_node;       // assign head pointer value to new node address
}

// Used to insert a new node next in sequencing order
void insert_node_to_last(Node *head, DataType data)
{
    if (head == NULL)
        return;

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = new_node;
}

void insert_node_to_specified_index(Node **head, int index, DataType data)
{
    if ((*head) == NULL)
        return;

    if (index == 0)
        return insert_node_to_head(head, data);

    Node *curr = *head;
    for (int i = 0; i + 1 < index; i++)
    {
        // In case of indexing overflow
        if (curr->next == NULL)
            return;

        curr = curr->next;
    }

    // In case of indexing overflow
    if (curr->next == NULL)
        return;

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = curr->next;
    curr->next = newNode;
}

void delete_first_node(Node **head)
{
    if ((*head) == NULL || (*head)->next == NULL)
        return;

    Node *currHead = *head;
    *head = currHead->next;
    free(currHead);
}

void delete_last_node(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;
}

void delete_specified_node_by_value(Node **head, DataType data)
{
    if ((*head) == NULL)
        return;

    int count = 0;
    for (Node *curr = *head; curr->next != NULL; curr = curr->next)
    {
        if (count == 0 && curr->data == data)
            return delete_first_node(head);

        if (curr->next == NULL)
            return;

        if (curr->next->data == data)
        {
            Node *deleteNode = curr->next;
            curr->next = deleteNode->next;
            free(deleteNode);
            break;
        }

        count++;
    }
}
void delete_specified_node_by_index(Node **head, int index)
{
    if ((*head) == NULL)
        return;

    if (index == 0)
        return delete_first_node(head);

    Node *curr = *head;
    for (int i = 0; i + 1 < index; i++)
    {
        // In case of indexing overflow
        if (curr->next == NULL)
            return;

        curr = curr->next;
    }

    // In case of indexing overflow
    if (curr->next == NULL)
        return;

    Node *deleteNode = curr->next;
    curr->next = deleteNode->next;
    free(deleteNode);
}

void update_node_at_specified_index(Node *head, int index, DataType data)
{
    if (head == NULL)
        return;

    Node *curr = head;
    for (int i = 0; i < index; i++)
    {
        if (curr->next == NULL)
            return;
        curr = curr->next;
    }

    curr->data = data;
}

void main(void)
{
    printf("----- Single Linked List -----\n");
    // Node *list1 = create_list(1);
    // insert_node_to_head(&list1, 2);
    // insert_node_to_head(&list1, 3);

    Node *list2 = create_list(10);
    insert_node_to_last(list2, 20);
    insert_node_to_last(list2, 30);
    insert_node_to_last(list2, 40);
    insert_node_to_last(list2, 50);
    insert_node_to_last(list2, 60);
    insert_node_to_last(list2, 70);
    insert_node_to_last(list2, 80);
    insert_node_to_last(list2, 90);
    insert_node_to_last(list2, 100);
    insert_node_to_specified_index(&list2, 5, 55);

    update_node_at_specified_index(list2, 5, 59);

    delete_specified_node_by_index(&list2, 8); // Delete 80
    delete_specified_node_by_value(&list2, 10);
    delete_first_node(&list2); // Delete 20
    delete_last_node(list2);   // Delete 100

    Node *p_list2 = list2;
    do
    {
        printf("Data: %d\n", p_list2->data);
    } while (p_list2 != NULL, p_list2 = p_list2->next);

    printf("----------\n");
}