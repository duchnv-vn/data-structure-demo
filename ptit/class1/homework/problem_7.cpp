/*
 * Viết chương trình con đảo ngược các phần tử trong dãy A có n số.
 * Độ phức tạp thuật toán: O(n)
 * Tổng số bước thực hiện: 4n
 * Thời gian thực hiện: T(n) = O(n)
 */

#include <iostream>
using namespace std;

void reverseArr(const int *A, const int n, int *newArr) {
    for (int i = 0; i < n; i++) {
        newArr[i] = A[n - i - 1];
    }
}

int main() {
    const auto size = 10;
    const int originalArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << originalArr[i] << " ";
    }
    cout << endl;

    int reversedArr[size] = {0};
    reverseArr(originalArr, size, reversedArr);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << reversedArr[i] << " ";
    }
    cout << endl;

    return 0;
}
