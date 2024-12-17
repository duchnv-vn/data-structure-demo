#include <iostream>

using namespace std;

class EduLinkedListNode
{
public:
  int data;                       // Data to store (could be int,string,object etc)
  EduLinkedListNode *nextElement; // Pointer to next element

  EduLinkedListNode()
  {
    // Constructor to initialize nextElement of newlyCreated EduLinkedListNode
    nextElement = nullptr;
  }
};

class EduLinkedList
{
private:
  EduLinkedListNode *head;

public:
  EduLinkedList();
  EduLinkedListNode *getHead();
  bool isEmpty();
  bool printList();
  void insertAtHead(int value);
  string elements();
  void insertAtTail(int value);
  bool search(int value);
  bool deleteAtHead();
  bool Delete(int value);
  int length();
  string reverse();
  void insertLoop();
};

EduLinkedList::EduLinkedList()
{
  head = nullptr;
}

EduLinkedListNode *EduLinkedList::getHead()
{
  return head;
}

bool EduLinkedList::isEmpty()
{
  if (head == nullptr) // Check whether the head points to null
    return true;
  else
    return false;
}

bool EduLinkedList::printList()
{
  if (isEmpty())
  {
    return false;
  }
  EduLinkedListNode *temp = head;

  while (temp != nullptr)
  {
    temp = temp->nextElement;
  }
  return true;
}

// Function inserts a value/new EduLinkedListNode as the first Element of list
void EduLinkedList::insertAtHead(int value)
{
  EduLinkedListNode *newNode = new EduLinkedListNode();
  newNode->data = value;
  newNode->nextElement = head; // Linking newNode to head's nextNode
  head = newNode;
}

string EduLinkedList::elements()
{ // this function will return all values of linked List
  string elementsList = "";
  EduLinkedListNode *start = head;
  EduLinkedListNode *check = head;

  elementsList += std::to_string(start->data);
  elementsList += "->";
  start = start->nextElement;

  while (start != nullptr && start->data != check->data)
  {
    elementsList += std::to_string(start->data);
    elementsList += "->";
    start = start->nextElement;
  }

  if (start == nullptr)
    return elementsList + "null";

  elementsList += std::to_string(check->data);
  return elementsList;
}

void EduLinkedList::insertAtTail(int value)
{
  if (isEmpty())
  { // inserting first element in list
    insertAtHead(value);
  }
  else
  {
    EduLinkedListNode *newNode = new EduLinkedListNode();
    EduLinkedListNode *last = head;

    while (last->nextElement != nullptr)
    {
      last = last->nextElement;
    }

    newNode->data = value;
    newNode->nextElement = nullptr;
    last->nextElement = newNode;
  }
}

bool EduLinkedList::search(int value)
{
  EduLinkedListNode *temp = head; // pointing temp to the head

  while (temp != nullptr)
  {
    if (temp->data == value)
    { // if passed value matches with temp's data
      return true;
    }
    temp = temp->nextElement; // pointig to temp's nextElement
  }
  return false; // if not found
}

bool EduLinkedList::deleteAtHead()
{
  if (isEmpty())
  { // check if lis is empty
    return false;
  }
  // if list is not empty, start traversing it from the head
  EduLinkedListNode *currentNode = head; // currentNode pointing to head
  head = head->nextElement;              // nextNode point to head's nextElement

  delete currentNode;
  return true;
}

bool EduLinkedList::Delete(int value)
{
  bool deleted = false; // returns true if the node is deleted, false otherwise

  if (isEmpty())
  {                 // check if the list is empty
    return deleted; // deleted will be false
  }

  // if list is not empty, start traversing it from the head
  EduLinkedListNode *currentNode = head;     // currentNode to traverse the list
  EduLinkedListNode *previousNode = nullptr; // previousNode starts from null

  if (currentNode->data == value)
  { // deleting value of head
    deleted = deleteAtHead();
    deleted = true; // true because value found and deleted
    return deleted; // returns true if the node is deleted
  }
  previousNode = currentNode;
  currentNode = currentNode->nextElement; // pointing current to current's nextElement
  // Traversing/Searching for EduLinkedListNode to Delete
  while (currentNode != nullptr)
  {

    // EduLinkedListNode to delete is found
    if (value == currentNode->data)
    {
      // pointing previousNode's nextElement to currentNode's nextElement
      previousNode->nextElement = currentNode->nextElement;
      delete currentNode;
      currentNode = previousNode->nextElement;
      deleted = true;
      break;
    }
    previousNode = currentNode;
    currentNode = currentNode->nextElement; // pointing current to current's nextElement
  }
  // deleted is true only when value is found and delted
  if (deleted == false)
  {
  }
  else
  {
  }
  return deleted;
}

int EduLinkedList::length()
{
  EduLinkedListNode *current = head; // Start from the first element
  int count = 0;                     // in start count is 0

  while (current != nullptr)
  {                                 // Traverse the list and count the number of nodes
    count++;                        // increment everytime as element is found
    current = current->nextElement; // pointing to current's nextElement
  }
  return count;
}

string EduLinkedList::reverse()
{
  EduLinkedListNode *previous = nullptr; // To keep track of the previous element, will be used in swapping links
  EduLinkedListNode *current = head;     // firstElement
  EduLinkedListNode *next = nullptr;

  // While Traversing the list, swap links
  while (current != nullptr)
  {
    next = current->nextElement;
    current->nextElement = previous;
    previous = current;
    current = next;
  }

  head = previous;   // pointing head to start of the list
  return elements(); // calling elements to return a string of values in list
}

void EduLinkedList::insertLoop()
{
  EduLinkedListNode *temp = head;
  // traversing to get to last element of the list
  while (temp->nextElement != nullptr)
  {
    temp = temp->nextElement;
  }
  temp->nextElement = head; // pointing last element to head of the list
}