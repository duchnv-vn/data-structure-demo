/*
* Tìm vị trí chứa giá trị min của dãy số nguyên A có n số.
*/

#include <iostream>
using namespace std;

int findMinIndex(const int *A, const int n) {
    auto minIndex = 0;
    auto minValue = A[0];

    for (int i = 1; i < n; i++) {
        if (const auto currValue = A[i]; currValue < minValue) {
            minIndex = i;
            minValue = currValue;
        }
    }

    return minIndex;
}

int main() {
    const auto size = 6;
    const int numArr[] = {6, 3, 9, 2, 0, 7};

    const auto minNum = findMinIndex(numArr, size);
    cout << "Min number index: " << minNum << endl;

    return 0;
}
