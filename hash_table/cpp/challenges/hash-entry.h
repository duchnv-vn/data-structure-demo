#include <iostream>
using namespace std;

class HashEntry
{
public:
    string key;
    int value;
    HashEntry *next;

    HashEntry(string k = "", int v = -1, HashEntry *n = nullptr) : key{k}, value{v}, next{n} {};
};