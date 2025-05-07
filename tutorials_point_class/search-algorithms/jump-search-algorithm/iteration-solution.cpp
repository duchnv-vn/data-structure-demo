/*
Step 1 − If the size of the input array is n, then the size of the block is sqrt(n).
Step 2 − The key value to be searched is compared with the first value of block. Jump by increment with block size until the key value is smaller than the first value of current block.
Step 3 − Start linear search in the previous block to search key index.
Step 4 − If the element is found, the position is returned. If the element is not found, unsuccessful search is prompted.
*/

#include <cmath>
#include <iostream>
using namespace std;

int jumpSearch(const int *arr, const int n, const int keyValue) {
    const int lastIndex = n - 1;
    const int blockSize = static_cast<int>(sqrt(n));
    int prevFirstBlockIndex = 0;
    int currFirstBlockIndex = 0;

    while (currFirstBlockIndex < n && keyValue >= arr[currFirstBlockIndex]) {
        prevFirstBlockIndex = currFirstBlockIndex;
        currFirstBlockIndex += blockSize;

        if (currFirstBlockIndex >= n && keyValue > arr[lastIndex]) return -1;
    }

    if (currFirstBlockIndex >= n && keyValue == arr[lastIndex]) return lastIndex;

    for (int i = prevFirstBlockIndex; i < (currFirstBlockIndex < n ? currFirstBlockIndex : n); i++)
        if (keyValue == arr[i]) return i;

    return -1;
}

int main() {
    constexpr int n = 10;
    constexpr int arr[]{10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    constexpr auto keyValue = 26;
    const int keyIndex = jumpSearch(arr, n, keyValue);

    if (keyIndex != -1) {
        cout << "Found the value at index: " << keyIndex << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    return 0;
}
