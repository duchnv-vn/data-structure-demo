#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<string>> TracePath(const vector<vector<string>> &paths)
{
    vector<vector<string>> correctPath = {};

    // Find head path
    for (const auto &outerPath : paths)
    {
        bool isHead = true;
        for (const auto &innerPath : paths)
        {
            if (outerPath[0] == innerPath[1])
            {
                isHead = false;
                break;
            }
        }

        if (isHead)
        {
            correctPath.push_back(outerPath);
            break;
        }
    }

    for (auto i = 0; i < paths.size(); i++)
    {
        for (const auto &path : paths)
        {
            if (correctPath.back()[1] == path[0])
                correctPath.push_back(path);
        }
    }

    return correctPath;
}
