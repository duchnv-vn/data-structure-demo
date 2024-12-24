#include "hash-entry.h"

class HashTable
{
    int slots;
    int size;
    HashEntry **bucket;

public:
    HashTable(int s) : slots{s}, size{0}
    {
        bucket = new HashEntry *[s];
        for (int i = 0; i < s; i++)
            bucket[i] = nullptr;
    }

    bool insert(string k, int v)
    {
        int hashIndex = getIndex(k);

        if (bucket[hashIndex] == nullptr)
        {
            bucket[hashIndex] = new HashEntry{k, v};
        }
        else
        {
            auto temp = bucket[hashIndex];
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new HashEntry{k, v};
        }

        size++;
        return true;
    }

    // int search(string k) {}

    // bool Delete() {}

    bool resize()
    {
        slots *= 2;
        auto newBucket = new HashEntry *[slots];

        for (int i = 0; i < slots; i++)
            newBucket[i] = nullptr;

        for (int i = 0; i < slots / 2; i++)
        {

            auto currEntry = bucket[i];
            while (currEntry != nullptr)
            {
                auto newEntry = new HashEntry{currEntry->key, currEntry->value};
                int hashIndex = getIndex(currEntry->key);
                if (newBucket[hashIndex] == nullptr)
                {
                    newBucket[hashIndex] = newEntry;
                }
                else
                {
                    auto currChainLink = newBucket[hashIndex];
                    while (currChainLink->next != nullptr)
                        currChainLink = currChainLink->next;

                    currChainLink->next = newEntry;
                }

                auto tempEntry = currEntry;
                currEntry = currEntry->next;
                delete tempEntry;
            }
        }

        delete[] bucket;
        bucket = newBucket;
        return true;
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

    void display()
    {
        HashEntry *temp;
        for (int i = 0; i < slots; i++)
        {
            if (bucket[i] != NULL)
            {
                cout << "HashIndex : " << i << " ";
                temp = bucket[i];
                while (temp != NULL)
                {
                    cout << "(key = " << temp->key << " , value = " << temp->value << " )";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
};