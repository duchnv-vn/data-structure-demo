#include <cmath>
#include <iostream>
using namespace std;

int scanBlock(const int *arr, const int n, const int b, const int keyValue, int &i) {
    if (const int nextI = i + b; nextI >= n || keyValue < arr[nextI]) return i;

    i += b;
    return scanBlock(arr, n, b, keyValue, i);
}

int jumpSearch(const int *arr, const int n, const int keyValue) {
    const int blockSize = static_cast<int>(sqrt(n));
    int scanIndex = 0;
    scanBlock(arr, n, blockSize, keyValue, scanIndex);

    const int upperBound = scanIndex + blockSize;
    for (int i = scanIndex; i < (upperBound < n ? upperBound : n); i++)
        if (keyValue == arr[i]) return i;

    return -1;
}

int main() {
    constexpr int n = 10;
    constexpr int arr[]{10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    constexpr auto keyValue = 44;

    const int keyIndex = jumpSearch(arr, n, keyValue);

    if (keyIndex != -1) {
        cout << "Found the value at index: " << keyIndex << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    return 0;
}
