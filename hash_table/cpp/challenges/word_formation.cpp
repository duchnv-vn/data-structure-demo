#include <unordered_map>
#include <string>
using namespace std;

bool IsFormationPossible(string words_array[], int size, string target)
{
    unordered_map<string, bool> combinedWordMap;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            combinedWordMap[words_array[i] + words_array[j]] = true;
            combinedWordMap[words_array[j] + words_array[i]] = true;
        }
    }

    return combinedWordMap.find(target) != combinedWordMap.end();
}