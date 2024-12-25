#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> FindSymmetric(int arr[][2], int size)
{
    unordered_map<int, int> ht;
    for (int i = 0; i < size; i++)
    {
        if (const auto it = ht.find(arr[i][0]); it == ht.end() || it->second != arr[i][1])
            ht.insert({arr[i][0], arr[i][1]});
    }

    vector<vector<int>> symPairs;
    for (auto it = ht.begin(); it != ht.end(); ++it)
    {
        auto it2 = ht.find(it->second);
        if (it2 != ht.end() && it2->second != it->second && it2->second == it->first)
        {
            symPairs.push_back(vector<int>{it->first, it->second});
            symPairs.push_back(vector<int>{it2->first, it2->second});
        }
    }

    return symPairs;
}

int main()
{
    if (true)
    {
        int input[][2] = {{1, 2}, {10, 6}, {4, 3}, {6, 10}, {5, 9}, {3, 4}, {9, 5}};
        vector<vector<int>> symPairs = FindSymmetric(input, 7);

        for (auto it = symPairs.begin(); it != symPairs.end(); ++it)
            cout << "First: " << it[0][0] << " | Second: " << it[0][1] << endl;
    }

    cout << "------------------------------------------" << endl;

    if (true)
    {
        int input[][2] = {{2, 2}, {4, 6}, {3, 3}, {6, 4}};
        vector<vector<int>> symPairs = FindSymmetric(input, 4);

        for (auto it = symPairs.begin(); it != symPairs.end(); ++it)
            cout << "First: " << it[0][0] << " | Second: " << it[0][1] << endl;
    }

    cout << "------------------------------------------" << endl;

    if (true)
    {
        int input[][2] = {{1, 1}};
        vector<vector<int>> symPairs = FindSymmetric(input, 1);

        for (auto it = symPairs.begin(); it != symPairs.end(); ++it)
            cout << "First: " << it[0][0] << " | Second: " << it[0][1] << endl;
    }

    return 0;
}
