#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Stack
{
private:
    int capacity;
    int size;
    T *array;

public:
    Stack(int c)
    {
        capacity = c;
        array = new T[capacity];
        assert(array != nullptr);
        size = 0;
    };

    ~Stack() { delete[] array; };

    bool push(T value)
    {
        if (size + 1 > capacity)
        {
            cout << "STACK FULL" << endl;
            return false;
        }

        array[size++] = value;
        return true;
    };

    T pop() { return array[size--]; };

    bool isEmpty() const { return size == 0; };

    T getTop() { return size == 0 ? -1 : array[size - 1]; };
};

#endif // STACK_H
