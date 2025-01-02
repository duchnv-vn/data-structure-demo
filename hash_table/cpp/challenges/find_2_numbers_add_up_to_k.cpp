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
        {
            auto result = new int[2]{nums[i], remainer};
            return result;
        }

        uniqueNums.insert(nums[i]);
    }

    return nullptr;
}