#include "hash-entry.h"

class HashTable
{
    int slots;
    int size;
    HashEntry *bucket;

public:
    HashTable()
    {
        bucket = new HashEntry{};
        slots = 10;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getIndex(string k)
    {
        int key = 0;
        for (int i = 0; i < k.length(); i++)
            key = 37 * key + k[i];

        if (key < 0)
            key *= -1;

        return key % slots;
    }
};