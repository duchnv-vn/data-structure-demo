#include <iostream>
#include <cstdlib>
#include "queue/cpp/queue.h"
using namespace std;

string *findBin(int n)
{
    string *result = new string[n];

    for (int i = 1; i <= n; i++)
    {
        Queue binaryNumber = {};

        auto decimal = i;
        while (decimal > 0)
        {
            binaryNumber.enqueue(decimal % 2);
            decimal = decimal / 2;
        }

        while (!binaryNumber.isEmpty())
        {
            result[i - 1] = to_string(binaryNumber.getFront()) + result[i - 1];
            binaryNumber.dequeue();
        }
    }

    return result;
}