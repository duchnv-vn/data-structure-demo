/*
* Tìm min của dãy số nguyên A có n số (int TimMin ( int *A, int n)).
*/

#include <iostream>
using namespace std;

int findMin(const int *A, const int n) {
    auto min = A[0];

    for (int i = 1; i < n; i++) {
        if (const auto currValue = A[i]; currValue < min) {
            min = currValue;
        }
    }

    return min;
}

int main() {
    const auto size = 6;
    const int numArr[] = {6, 3, 9, 2, 0, 7};

    const auto minNum = findMin(numArr, size);
    cout << "Min number: " << minNum << endl;

    return 0;
}
