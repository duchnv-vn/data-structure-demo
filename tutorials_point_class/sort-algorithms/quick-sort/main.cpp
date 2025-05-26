#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    const auto temp = a;
    a = b;
    b = temp;
}

void quickSort(int arr[], const int left, const int right) {
    if (left >= right) return;

    const int pivot = (left + right) / 2;
    const int pivotValue = arr[pivot];

    int tempL = left, tempR = right;
    while (tempL < tempR) {
        if (arr[tempL] < pivotValue) tempL++;
        if (arr[tempR] > pivotValue) tempR--;

        swap(arr[tempL], arr[tempR]);

        tempL++;
        tempR--;
    }

    quickSort(arr, left, tempR);
    quickSort(arr, tempL, right);
}

int main() {
    constexpr int n = 8;
    int arr[n] = {236, 15, 333, 27, 9, 108, 76, 498};

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (const int num: arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
