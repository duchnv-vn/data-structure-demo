#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<string>> TracePath_S1(const vector<vector<string>> &paths)
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

vector<vector<string>> TracePath_S2(const vector<vector<string>> &paths)
{
    unordered_map<string, string> pathMap;
    unordered_map<string, bool> isHeadMap;

    for (const auto &path : paths)
    {
        pathMap[path[0]] = path[1];
        isHeadMap[path[1]] = true;
    }

    string head;
    for (const auto &path : paths)
    {
        if (isHeadMap.find(path[0]) == isHeadMap.end())
        {
            head = path[0];
            break;
        }
    }

    vector<vector<string>> correctPath;
    while (pathMap.find(head) != pathMap.end())
    {
        string next = pathMap[head];
        correctPath.push_back({head, next});
        head = next;
    }

    return correctPath;
}