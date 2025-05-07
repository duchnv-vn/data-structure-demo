#include <iostream>
using namespace std;

int main() {
    const auto n = 10;
    const int arr[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const auto keyValue = 3;

    int lo = 0;
    int hi = n - 1;
    int keyIndex = -1;

    while (lo <= hi) {
        if (lo == hi) {
            if (arr[lo] == keyValue) keyIndex = lo;
            break;
        }

        const auto midIndex = lo +( (hi - lo) / 2);
        const auto midValue = arr[midIndex];

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
