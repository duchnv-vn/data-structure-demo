#include <iostream>
#include <vector>

template <typename T>
class MyQueue
{
public:
    std::vector<T> queue_list;
    int queue_size;

    MyQueue()
    {
        queue_size = 0;
    }

    bool isEmpty()
    {
        return queue_size == 0;
    }

    T front()
    {
        if (isEmpty())
        {
            // Assuming T() creates a default value for the type T
            return T(); // or throw an exception
        }
        return queue_list.front();
    }

    T rear()
    {
        if (isEmpty())
        {
            // Assuming T() creates a default value for the type T
            return T(); // or throw an exception
        }
        return queue_list.back();
    }

    int size()
    {
        return queue_size;
    }

    void enqueue(const T &value)
    {
        queue_size++;
        queue_list.push_back(value);
    }

    T dequeue()
    {
        if (isEmpty())
        {
            // Assuming T() creates a default value for the type T
            return T(); // or throw an exception
        }
        T front = queue_list.front();
        queue_list.erase(queue_list.begin());
        queue_size--;
        return front;
    }
};