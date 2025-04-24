#include <cmath>
#include <iostream>
using namespace std;

int exponentialSearch(const int *arr, const int n, const int keyValue) {
    const int lastIndex = n - 1;
    int prevScanIndex = 0;
    int scanIndex = 0;
    int k = 0;

    if (keyValue == arr[scanIndex]) return scanIndex;

    while (scanIndex < n && keyValue >= arr[scanIndex]) {
        prevScanIndex = scanIndex;
        const int jumpSize = pow(2, k);
        scanIndex += jumpSize;

        if (scanIndex >= n && keyValue > arr[lastIndex]) return -1;

        k++;
    }

    if (scanIndex >= n && keyValue == arr[lastIndex]) return lastIndex;

    for (int i = prevScanIndex; i < (scanIndex < n ? scanIndex : n); i++)
        if (keyValue == arr[i]) return i;

    return -1;
}

int main() {
    constexpr int n = 10;
    constexpr int arr[]{10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    constexpr auto keyValue = 31;
    const int keyIndex = exponentialSearch(arr, n, keyValue);

    if (keyIndex != -1) {
        cout << "Found the value at index: " << keyIndex << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    return 0;
}
