#include <iostream>
using namespace std;

void countingSort(int input[], const int n, const int pos) {
    int max = (input[0] / pos) % 10;
    for (int i = 0; i < n; i++)
        if (const int digit = (input[i] / pos) % 10; digit > max) max = digit;

    const int countSize = max + 1;
    int count[countSize]{0};
    for (int i = 0; i < n; i++)
        count[(input[i] / pos) % 10]++;

    for (int i = 1; i < countSize; i++)
        count[i] += count[i - 1];

    int output[n];
    for (int i = n - 1; i >= 0; i--)
        output[(count[(input[i] / pos) % 10]--) - 1] = input[i];

    for (int i = 0; i < n; i++)
        input[i] = output[i];
}

void radixSort(int input[], const int n) {
    int max = input[0];
    for (int i = 0; i < n; i++)
        if (input[i] > max) max = input[i];

    for (int pos = 1; (max / pos) > 0; pos *= 10)
        countingSort(input, n, pos);
}

int main() {
    constexpr int n = 8;
    int arr[n] = {236, 15, 333, 27, 9, 108, 76, 498};

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (const int num: arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
