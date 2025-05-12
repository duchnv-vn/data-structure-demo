#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    const auto temp = a;
    a = b;
    b = temp;
}

void shellSort(int *arr, const int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; j >= 0; j -= gap) {
                if (arr[j + gap] >= arr[j]) break;
                swap(arr[j + gap], arr[j]);
            }
        }
    }
}

int main() {
    const int n = 5;
    int arr[n] = {12, 19, 55, 2, 16};

    shellSort(arr, n);

    for (const int i: arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
