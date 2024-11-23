#include <iostream>
#include "singly_linked_list.h"
using namespace std;

void print(int data)
{
    cout << data << " ";
}

int main()
{

    singly_linked_list<int> list(10); // Create list with one node (10)

    // Test insertion
    list.insert_to_head(5);
    list.insert_to_last(15);
    list.insert_by_index(1, 7); // Insert 7 at index 1
    list.forEach(print);        // Expected: 5 7 10 15
    cout << endl;

    // Test update
    list.update_by_index(1, 8);        // Update index 1 to 8
    list.update_many_by_value(15, 20); // Update all 15s to 20
    list.forEach(print);               // Expected: 5 8 10 20
    cout << endl;

    // Test removal
    list.remove_head();      // Remove head
    list.remove_last();      // Remove last node
    list.remove_by_index(1); // Remove node at index 1
    list.forEach(print);     // Expected: 8
    cout << endl;

    // Test edge cases
    cout << "Search index 0: " << list.search_by_index(0) << endl;            // Expected: 8
    cout << "Remove last node (should fail): " << list.remove_head() << endl; // Expected: 0

    return 0;
}