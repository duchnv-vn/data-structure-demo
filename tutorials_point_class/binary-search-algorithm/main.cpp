/*
Step 1 − Select the middle item in the array and compare it with the key value to be searched. If it is matched, return the position of the median.
Step 2 − If it does not match the key value, check if the key value is either greater than or less than the median value.
Step 3 − If the key is greater, perform the search in the right sub-array; but if the key is lower than the median value, perform the search in the left sub-array.
Step 4 − Repeat Steps 1, 2 and 3 iteratively, until the size of sub-array becomes 1.
Step 5 − If the key value does not exist in the array, then the algorithm returns an unsuccessful search.
*/

#include <iostream>
using namespace std;

int binarySearch(const int *arr, const int left, const int right, const int keyValue) {
    if (left == right) return arr[left] == keyValue ? left : -1;

    const auto index = left + ((right - left) / 2);
    const auto pivot = arr[index];

    if (keyValue == pivot) return index;

    if (keyValue > pivot) return binarySearch(arr, index + 1, right, keyValue);

    return binarySearch(arr, left, index - 1, keyValue);
}

int main() {
    const int n = 10;
    const int arr[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const auto keyValue = 3;

    const int index = binarySearch(arr, 0, n - 1, keyValue);

    if (index != -1) {
        cout << "Found the value at index: " << index << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    return 0;
}
