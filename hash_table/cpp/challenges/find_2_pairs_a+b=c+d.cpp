#include <unordered_map>
using namespace std;

int **FindPairs(int nums[], int length)
{
    unordered_map<int, int> sumMap;
    unordered_map<int, int *> indexMap;

    int count = 0;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            sumMap[count] = nums[i] + nums[j];
            indexMap[count] = new int[2]{i, j};
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (sumMap[i] == sumMap[j])
            {
                int **result = new int *[2];
                result[0] = new int[2]{nums[indexMap[i][0]], nums[indexMap[i][1]]};
                result[1] = new int[2]{nums[indexMap[j][0]], nums[indexMap[j][1]]};
                return result;
            }
        }
    }

    return nullptr;
}