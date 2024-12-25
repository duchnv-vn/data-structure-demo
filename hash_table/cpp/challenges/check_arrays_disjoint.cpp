#include <unordered_set>
#include <iostream>
using namespace std;

/*
    Given two arrays, determine whether or not they are disjoint.
 */
bool isDisjoint(int *arr1, int *arr2, int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            if (arr1[i] == arr2[j])
                return false;
        }
    }

    return true;
}