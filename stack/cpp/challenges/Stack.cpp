#include <vector> // Include directive for std::vector

template <typename T>
class MyStack
{
private:
    std::vector<T> stack_list; // Declaration of std::vector with template type T
    int stack_size;

public:
    MyStack()
    {
        stack_size = 0;
    }

    bool isEmpty()
    {
        return stack_size == 0;
    }

    T peek()
    {
        if (isEmpty())
        {
            return -1; // Assuming -1 indicates an empty stack
        }
        return stack_list.back();
    }

    int size()
    {
        return stack_size;
    }

    void push(T value)
    {
        stack_size++;
        stack_list.push_back(value);
    }

    T pop()
    {
        if (isEmpty())
        {
            return -1; // Assuming -1 indicates an empty stack
        }
        T top = stack_list.back();
        stack_list.pop_back();
        stack_size--;
        return top;
    }
};