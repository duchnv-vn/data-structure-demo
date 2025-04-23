#include <cmath>
#include <iostream>
using namespace std;

int jumpSearch(const int *arr, const int n, const int b, const int keyValue, int i) {
    const int nextI = i + b;
    if (nextI >= n || keyValue < arr[nextI]) return i;
    return jumpSearch(arr, n, b, keyValue, nextI);
}

int main() {
    const int n = 10;
    const int arr[]{10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    const auto keyValue = 42;
    const int blockSize = static_cast<int>(sqrt(n));
    int keyIndex = -1;

    const int firstBlockIndex = jumpSearch(arr, n, blockSize, keyValue, 0);
    const int upperBound = firstBlockIndex + blockSize;
    for (int i = firstBlockIndex; i < (upperBound < n ? upperBound : n); i++) {
        if (keyValue == arr[i]) {
            keyIndex = i;
            break;
        }
    }

    if (keyIndex != -1) {
        cout << "Found the value at index: " << keyIndex << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    return 0;
}
