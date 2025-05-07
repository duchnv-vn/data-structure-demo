#include <iostream>
using namespace std;

void swapping(int &a, int &b) {
    const auto temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *arr, const int n) {
    int pos = 0;

    while (pos < n - 1) {
        int min = arr[pos];
        int minPos = pos;
        for (int i = pos + 1; i < n; i++) {
            if (arr[i] < min) {
                minPos = i;
                min = arr[i];
            }
        }

        if (minPos != pos) swapping(arr[pos], arr[minPos]);

        pos++;
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
