#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

bool FindSubZero_S1(int *arr, int size)
{
    unordered_map<int, bool> sumMap;

    for (auto i = 0; i < size; i++)
    {
        for (auto j = i; j < size; j++)
        {
            int sum = 0;
            for (auto k = i; k <= j; k++)
                sum += arr[k];
            sumMap[sum] = true;
        }
    }

    return sumMap.find(0) != sumMap.end();
}

bool FindSubZero_S2(int *arr, int size)
{
    for (auto i = 0; i < size; i++)
    {
        for (auto j = i; j < size; j++)
        {
            int sum = 0;
            for (auto k = i; k <= j; k++)
                sum += arr[k];

            if (sum == 0)
                return true;
        }
    }

    return false;
}