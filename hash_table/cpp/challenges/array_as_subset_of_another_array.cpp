#include <unordered_set>
using namespace std;

bool IsSubset(int *arr1, int *arr2, int size1, int size2)
{
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            if (arr2[i] == arr1[j])
                break;

            if (j + 1 == size1)
                return false;
        }
    }

    return true;
}