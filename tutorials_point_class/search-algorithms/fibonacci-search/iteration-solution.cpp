/*
Step 1 − Find the immediate Fibonacci number that is greater than or equal to the size of the input array. Then, also hold the two preceding numbers of the selected Fibonacci number, that is, we hold Fm, Fm-1, Fm-2 numbers from the Fibonacci Series.
Step 2 − Initialize the offset value as -1, as we are considering the entire array as the searching range in the beginning.
 */
#include <cmath>
#include <iostream>
using namespace std;

int fibonacciSearch(const int *arr, const int n, const int keyValue) {
    int fm{1}, fm_1{1}, fm_2{0};

    while (fm < n) {
        fm_2 = fm_1;
        fm_1 = fm;
        fm = fm_1 + fm_2;
    }

    int offset = -1;
    int range = n;
    while (fm > 1) {
        const int scanIndex = min(offset + fm_2, range - 1);

        if (keyValue == arr[scanIndex]) return scanIndex;

        if (keyValue > arr[scanIndex]) {
            offset = scanIndex;
            fm = fm_1;
            fm_1 = fm_2;
        } else {
            range = scanIndex;
            fm = fm_2;
            fm_1 -= fm_2;
        }

        fm_2 = fm - fm_1;
    }

    if (fm_1 && keyValue == arr[offset + 1])
        return offset + 1;

    return -1;
}

int main() {
    constexpr int n = 10;
    constexpr int arr[]{10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    constexpr auto keyValue = 33;

    const int keyIndex = fibonacciSearch(arr, n, keyValue);

    if (keyIndex != -1) {
        cout << "Found the value at index: " << keyIndex << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    return 0;
}
