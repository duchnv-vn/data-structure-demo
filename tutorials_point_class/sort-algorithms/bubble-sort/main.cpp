#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    const auto temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, const int n) {
    for (int i = n - 1; i > 1; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    const int n = 5;
    int arr[n] = {12, 19, 55, 2, 16};

    bubbleSort(arr, n);

    for (const int i: arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
