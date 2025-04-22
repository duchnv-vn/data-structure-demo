/*
1. Start searching data from a list with the lowest (lo) and the highest (hi) index
2. If lo == hi or arr[lo] == arr [hi], check if key value == arr[lo] then return key index as lo, otherwise stop the search
3. Find middle index by interpolation formula
4. If  key value == middle value then return key index as middle index
5. If key value > middle value then dividing list to search in higher sub-list by assigning lo as middle index + 1
6. If key value < middle value then dividing list to search in lower sub-list by assigning hi as middle index - 1
*/

#include <iostream>
using namespace std;

int middleProbingFormula(const int *arr, const int lo, const int hi, const int keyValue) {
    return lo + (((hi - lo) * (keyValue - arr[lo])) / (arr[hi] - arr[lo]));
}

int main() {
    const int n = 10;
    const int arr[]{10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    const auto keyValue = 42;

    int lo = 0;
    int hi = n - 1;
    int keyIndex = -1;

    while (lo <= hi) {
        if (lo == hi || arr[lo] == arr[hi]) {
            if (arr[lo] == keyValue) keyIndex = lo;
            break;
        }

        const int midIndex = middleProbingFormula(arr, lo, hi, keyValue);
        const int midValue = arr[midIndex];

        if (keyValue == midValue) {
            keyIndex = midIndex;
            break;
        }

        if (keyValue > midValue) {
            lo = midIndex + 1;
        } else {
            hi = midIndex - 1;
        }
    }

    if (keyIndex != -1) {
        cout << "Found the value at index: " << keyIndex << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    return 0;
}
