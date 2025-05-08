#include <iostream>
using namespace std;

void insertionSort(int *arr, const int n) {
    for (int i = 0; i < n; i++) {
        const auto val = arr[i];

        int j = i;
        while (j > 0 && val < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = val;
    }
}

int main() {
    const int n = 5;
    int arr[n] = {12, 19, 55, 2, 16};

    insertionSort(arr, n);

    for (const int i: arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
