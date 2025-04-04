#include <iostream>
#include <sstream>
#include "challenges/hash-table.h"
using namespace std;

int hashModular(int key, int size)
{
    return key % size; // modular of the key with the array size
}

int hashTruncation(int key)
{
    return key % 5000; // use key upto 2 digits
}

int hashFold(int key, int chunkSize)
{
    cout << "Key: " << key << endl;
    string strKey = std::to_string(key); // Convert integer into string for slicing
    int hashVal = 0, tempNum = 0;
    string temp;
    cout << "Chunks: ";
    // increment i to chunksize everytime
    for (int i = 0; i < strKey.length(); i += chunkSize)
    {
        temp = "";
        if (i + chunkSize <= strKey.length()) // check if chunksize is less than equal to key
        {
            for (int j = i; j < i + chunkSize; j++)
            {
                temp += strKey[j];
                cout << strKey[j];
            }
            cout << " ";
            // converting string to integer
            stringstream conv(temp);
            conv >> tempNum;
            hashVal = hashVal + tempNum; // adding sliced number to hashVal
        }
        else
        {
            for (int j = i; j <= strKey.length(); j++)
            {
                temp += strKey[j];
                cout << strKey[j];
            }
            // converting string to integer
            stringstream conv(temp);
            conv >> tempNum;
            hashVal = hashVal + tempNum; // adding sliced number to hashVal
        }
    }
    return hashVal;
}

int main()
{
    if (false)
    {
        int size = 8;
        int key = 89;
        int index = hashModular(key, size); // index will always stay between 0 and tableSize - 1
        cout << "The index for key " << key << " is " << index << endl;
    }

    if (false)
    {
        int key = 123456;
        int index = hashTruncation(key);
        cout << "The index for key " << key << " is " << index << endl;
    }

    if (false)
    {
        int key = 456789;
        int chunkSize = 2;
        cout << "Hash Key: " << hashFold(key, chunkSize) << endl;
    }

    // Define classes
    if (false)
    {
        auto object1 = new HashEntry{"key1", 10};
        // cout << "object1.key: " << object1->key << endl;
        // cout << "object1.value: " << object1->value << endl;

        auto table1 = new HashTable{10};
        cout << table1->isEmpty() << endl;
    }

    // Insertion in hash table
    if (false)
    {
        auto ht = new HashTable{3}; // making three buckets
        ht->insert("London", 2);
        ht->insert("London", 10);
        ht->insert("New York", 15);
        ht->insert("Tokyo", 7);
        ht->insert("Bangkok", 2);
        ht->insert("Beijing", 6);
        ht->insert("Islamabad", 9);
        ht->display();
    }

    // Resizing in a Hash Table
    if (false)
    {
        HashTable ht(4);
        ht.insert("London", 2);
        ht.insert("London", 10);
        ht.insert("New York", 15);
        ht.insert("Tokyo", 7);
        ht.insert("Bangkok", 2);
        ht.display();
        cout << "-------------" << endl;
        ht.resize(); // increase slots to 8
        ht.insert("Beijing", 6);
        ht.insert("Islamabad", 9);
        ht.insert("New Delhi", 17);
        ht.insert("Moscow", 12);
        ht.insert("Amsterdam", 5);
        ht.insert("Paris", 13);
        ht.display();
    }

    // Search in a Hash Table
    if (false)
    {
        HashTable ht(4);
        ht.insert("London", 2);
        ht.insert("London", 10);
        ht.insert("New York", 15);
        ht.insert("Tokyo", 7);
        ht.insert("Bangkok", 2);
        ht.insert("Beijing", 6);
        ht.insert("Islamabad", 9);

        cout << ht.search("London") << endl;
        cout << ht.search("Moscow") << endl;
        cout << ht.search("Islamabad") << endl;
    }

    // Deletion in Table
    if (false)
    {
        HashTable ht(2);
        ht.insert("London", 2);
        ht.insert("London", 10);
        ht.insert("New York", 15);
        ht.insert("Tokyo", 7);
        ht.insert("Bangkok", 2);
        ht.insert("Beijing", 6);
        ht.insert("Islamabad", 9);

        ht.display();
        cout << "-------------" << endl;
        ht.Delete("London");
        ht.display();
        cout << "-------------" << endl;
        ht.Delete("Moscow");
        ht.display();
        cout << "-------------" << endl;
        ht.Delete("Islamabad");
        ht.display();
    }

    // Complete Implementation
    if (true)
    {
        HashTable ht(4);
        ht.insert("London", 2);

        ht.insert("London", 10);
        ht.insert("New York", 15);
        ht.insert("Tokyo", 7);
        ht.insert("Bangkok", 2);
        ht.insert("Beijing", 6);
        ht.insert("Islamabad", 9);
        ht.insert("New Delhi", 17);
        ht.insert("Moscow", 12);
        ht.display();
        ht.resize();
        ht.display();
        ht.insert("Amsterdam", 5);
        ht.insert("Paris", 13);
        ht.insert("Istanbul", 19);
        ht.insert("Kuala Lumpur", 1);
        ht.insert("Jakarta", 8);
        ht.insert("Glasgow", 3);
        ht.insert("Seattle", 14);
        cout << ht.search("London") << endl;
        cout << ht.search("Moscow") << endl;
        cout << ht.search("Berlin") << endl;
        ht.display();
        ht.Delete("London");
        ht.display();
        ht.Delete("Moscow");
        ht.display();
        ht.Delete("Istanbul");
        ht.display();
    }

    return 0;
}