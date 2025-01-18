/*
 * Viết chương trình con đảo ngược các phần tử trong dãy A có n số.
 * Độ phức tạp thuật toán: O(n)
 * Tổng số bước thực hiện: 4n
 * Thời gian thực hiện: T(n) = O(n)
 */

#include <iostream>
using namespace std;

void reverseArr(const int &(int * A), int n) {
    int reversedArr[n];

    for (int i = 0; i < n; i++) {
        reversedArr[i] = **A[n - i - 1];
    }

    *A = reversedArr;
}

int main() {
    const auto size = 10;
    const int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArr(&arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
