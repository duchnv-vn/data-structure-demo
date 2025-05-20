#include <cmath>
#include <iostream>
using namespace std;

void scanBlock(const int *arr, const int n, const int keyValue, int &i, int &k) {
    const int jumpSize = pow(2, k);

    if (const int nextI = i + jumpSize; nextI >= n || keyValue < arr[nextI]) return;

    i += jumpSize;
    k += 1;
    return scanBlock(arr, n, keyValue, i, k);
}

int exponentialSearch(const int *arr, const int n, const int keyValue) {
    int scanIndex = 0;
    int k = 0;
    scanBlock(arr, n, keyValue, scanIndex, k);

    const int jumpSize = pow(2, k);
    const int upperBound = scanIndex + jumpSize;
    for (int i = scanIndex; i < (upperBound < n ? upperBound : n); i++)
        if (keyValue == arr[i]) return i;

    return -1;
}

int main() {
    constexpr int n = 10;
    constexpr int arr[]{10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    constexpr auto keyValue = 35;
    const int keyIndex = exponentialSearch(arr, n, keyValue);

    if (keyIndex != -1) {
        cout << "Found the value at index: " << keyIndex << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    return 0;
}
