#include <iostream>
using namespace std;

class twoStacks
{
private:
    int size;
    int *arr;
    int top1,
        top2;

public:
    // Initialize the two stacks here
    twoStacks(int n)
    {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    // Insert Value in First Stack
    void push1(int value)
    {
        if (top1 == top2 - 1)
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }

        arr[++top1] = value;
    }
    // Insert Value in Second Stack
    void push2(int value)
    {
        if (top2 == top1 + 1)
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }

        arr[--top2] = value;
    }
    // Return and remove top Value from First Stack
    int pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }

        auto popValue = arr[top1--];
        return popValue;
    }
    // Return and remove top Value from Second Stack
    int pop2()
    {
        if (top2 == size)
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }

        auto popValue = arr[top2++];
        return popValue;
    }
};

int main()
{
    const string calls[][10] = {
        {"TwoStacks", "push1", "push2", "pop2"},
        {"TwoStacks", "push1", "pop1", "push2", "pop2"},
        {"TwoStacks", "push1", "push2", "push1", "push2", "pop1", "pop2", "pop1"},
        {"TwoStacks", "push2", "pop2", "push2", "push1"},
        {"TwoStacks", "push1", "push1", "push2", "pop1"}};

    const int inputs[][10] = {
        {5, 10, 15, INT_MIN},
        {7, -4, INT_MIN, -6, INT_MIN},
        {5, 10, 20, 50, 30, INT_MIN, INT_MIN, INT_MIN},
        {10, 4, INT_MIN, 8, 10},
        {3, 10, 20, 30, INT_MIN}};

    for (int i = 0; i < sizeof(calls) / sizeof(calls[0]); i++)
    {
        cout << "Testcase " << i + 1 << ":" << endl;
        twoStacks stackObj(inputs[i][0]);

        for (int j = 1; j < sizeof(calls[i]) / sizeof(calls[i][0]); j++)
        {
            if (calls[i][j] == "push1")
            {
                stackObj.push1(inputs[i][j]);
            }
            else if (calls[i][j] == "push2")
            {
                stackObj.push2(inputs[i][j]);
            }
            else if (calls[i][j] == "pop1")
            {
                cout << "\tpop1 returns " << stackObj.pop1() << endl;
            }
            else if (calls[i][j] == "pop2")
            {
                cout << "\tpop2 returns " << stackObj.pop2() << endl;
            }
        }
        cout << string(50, '-') << endl;
    }

    return 0;
}