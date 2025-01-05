#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    Queue q;
    for (int i = 1; i <= 5; i++)
    {
        q.enqueue(i); // inserting data in queue
        q.showqueue();
    }

    cout << "getFront(): " << q.getFront() << endl;
    cout << "getTail(): " << q.getTail() << endl;
    cout << "getSize(): " << q.getSize() << endl;

    while (q.isEmpty() == false)
    {
        q.dequeue();
    }
    q.showqueue();

    return 0;
}