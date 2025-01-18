// Bai toan 2: Duyet to hop chap k cua 1,2...,n
#include <iostream>
using namespace std;

void print_arr(const int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void next_combination(int arr[], const int k, const int n, bool &OK) {
    int i = k - 1;

    while (i >= 0 && arr[i] == (n - (k - 1) + i)) i--;

    if (i >= 0) {
        arr[i] += 1;

        for (int j = i + 1; j < k; j++) {
            arr[j] = arr[i] + j - i;
        }
    } else {
        OK = false;
    }
}

void problem_2_solution_1() {
    const int k = 3;
    const int n = 5;

    int arr[k]{0};
    for (int i = 0; i < k; i++) arr[i] = i + 1;

    bool OK = true;
    while (OK) {
        print_arr(arr, k);
        next_combination(arr, k, n, OK);
    }
}
