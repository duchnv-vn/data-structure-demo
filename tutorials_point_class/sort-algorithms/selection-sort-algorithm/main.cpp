#include <iostream>
using namespace std;

void swapping(int &a, int &b) {
    const auto temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *arr, const int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = arr[i];
        int minPos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                minPos = j;
                min = arr[j];
            }
        }

        if (minPos != i) swapping(arr[i], arr[minPos]);
    }
}

int main() {
    const int n = 5;
    int arr[n] = {12, 19, 55, 2, 16};

    selectionSort(arr, n);

    for (const int i: arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
