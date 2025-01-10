#include "Queue.cpp"
#include "stack/cpp/challenges/Stack.cpp"
#include <iostream>
using namespace std;

MyQueue<int> ReverseK_2(MyQueue<int> queue, int k)
{
    if (k < 0 || queue.isEmpty() || k > queue.size())
        return queue;

    MyStack<int> stack{};
    for (int i = 0; i < k; i++)
        stack.push(queue.dequeue());

    while (!stack.isEmpty())
        queue.enqueue(stack.pop());

    for (int i = 0; i < queue.size() - k; i++)
        queue.enqueue(queue.dequeue());

    return queue;
}

MyQueue<int> ReverseK_1(MyQueue<int> queue, int k)
{
    if (k < 0 || queue.isEmpty() || k > queue.size())
        return queue;

    int currQueueSize = queue.size();
    int remainedSize = currQueueSize - k;
    int reverseArr[k];
    int remainedArr[remainedSize];
    for (int i = 0; i < k; i++)
        reverseArr[k - i - 1] = queue.dequeue();

    for (int i = 0; i < remainedSize; i++)
        remainedArr[i] = queue.dequeue();

    for (int i = 0; i < k; i++)
        queue.enqueue(reverseArr[i]);

    for (int i = 0; i < remainedSize; i++)
        queue.enqueue(remainedArr[i]);

    return queue;
}