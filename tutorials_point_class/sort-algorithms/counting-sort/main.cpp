#include <iostream>
using namespace std;

void countingSort(const int input[], int output[], const int n) {
    int maxValue = input[0];
    for (int i = 1; i < n; i++)
        if (input[i] > maxValue)maxValue = input[i];

    const int occurrencesSize = maxValue + 1;
    int occurrences[occurrencesSize]{0};
    for (int i = 0; i < n; i++) occurrences[input[i]] += 1;

    for (int i = 1; i < occurrencesSize; i++) occurrences[i] += occurrences[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        const int num = input[i];
        cout << "num: " << num << " | " << occurrences[num] << endl;
        output[occurrences[num] - 1] = num;
        occurrences[num] -= 1;
    }
}

int main() {
    constexpr int n = 5;
    const int input[n] = {12, 32, 44, 8, 16};
    int output[n];

    countingSort(input, output, n);

    cout << "Sorted array: ";
    for (const int i: output)
        cout << i << " ";
    cout << endl;

    return 0;
}
