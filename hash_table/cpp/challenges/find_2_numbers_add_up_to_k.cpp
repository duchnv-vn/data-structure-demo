#include <unordered_set>
#include <unordered_map>
using namespace std;

int *FindSum(int nums[], int value, int size)
{
    unordered_set<int> uniqueNums = {};
    for (int i = 0; i < size; i++)
    {
        auto remainer = value - nums[i];
        if (uniqueNums.find(remainer) != uniqueNums.end())
            return new int[2]{nums[i], remainer};

        uniqueNums.insert(nums[i]);
    }

    return nullptr;
}

int *FindSum2(int nums[], int value, int size)
{
    unordered_map<int, int *> sumMap;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
            sumMap[nums[i] + nums[j]] = (new int[2]{nums[i], nums[j]});
    }

    if (auto obj = sumMap.find(value); obj != sumMap.end())
        return obj->second;

    return nullptr;
}