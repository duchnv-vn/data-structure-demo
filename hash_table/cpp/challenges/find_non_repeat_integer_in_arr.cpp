#include <unordered_map>
#include <unordered_set>
using namespace std;

int FindFirstUnique(int nums[], int size)
{
    unordered_set<int> uniqueNums;
    for (int i = 0; i < size; i++)
    {
        if (uniqueNums.find(nums[i]) == uniqueNums.end())
            uniqueNums.insert({nums[i]});
    }

    return uniqueNums.size() > 0 ? *uniqueNums.begin() : -1;
}

int FindFirstUnique2(int nums[], int size)
{
    unordered_map<int, int> countMap;
    for (int i = 0; i < size; i++)
        countMap[nums[i]] += 1;

    for (auto &[fst, snd] : countMap)
    {
        if (snd == 1)
            return fst;
    }

    return -1;
}