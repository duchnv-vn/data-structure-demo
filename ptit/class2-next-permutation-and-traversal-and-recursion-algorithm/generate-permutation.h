// Bai toan 3: Duyet hoan vi cua 1,2...,n
#include <iostream>
using namespace std;

void next_permutation_2(int arr[], const int n, bool &OK) {
    int i = n - 1;

    while (i > 0 && arr[i] > arr[i - 1]) i--;

    if (i >= 0) {
        arr[i] += 1;
    } else {
        OK = false;
    }
}

void next_permutation(int arr[], const int n, bool &OK) {
    int i = n - 2;

    while (i >= 0 && arr[i] > arr[i + 1]) i--;

    if (i < 0) OK = false;

    int j = n - 1;
    while (arr[i] > arr[j]) j--;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    int k = i + 1, s = n - 1;
    while (arr[k] > arr[s]) s--;
    temp = arr[k];
    arr[k] = arr[s];
    arr[s] = temp;

    // int k = i + 1, s = n - 1;
    //
    // while (k <= s) {
    //     temp = arr[k];
    //     arr[k] = arr[s];
    //     arr[s] = temp;
    //
    //     k++;
    //     s--;
    // }
}

void problem_3_solution_1() {
    const int n = 3;
    int arr[n]{0};
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    bool OK = true;
    while (OK) {
        print_arr(arr, n);
        next_permutation(arr, n, OK);
    }
}


void generate_permutation_by_recurrsion(int arr[], const int n, const int currIndex) {
    if (currIndex + 1 == n) {
        print_arr(arr, n);
        return;
    }

    for (int i = currIndex; i < n; i++) {
        const auto temp = arr[currIndex];
        arr[currIndex] = arr[i];
        arr[i] = temp;

        generate_permutation_by_recurrsion(arr, n, currIndex + 1);
    }
}

// Backtracking
void problem_3_solution_2() {
    const int n = 3;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    generate_permutation_by_recurrsion(arr, n, 0);
}

void in_place_permutation(int arr[], const int n) {
    int stack[n], top = -1; // Stack để lưu trạng thái
    int i = 0;

    while (true) {
        if (i < n) {
            stack[++top] = i; // Đẩy trạng thái vào stack
            i++;
        } else {
            print_arr(arr, n); // In hoán vị
            i = stack[top--]; // Lùi lại trạng thái trước đó
            while (i >= n - 1 && top >= 0) {
                i = stack[top--];
            }
            if (i < n - 1) {
                swap(arr[i], arr[i + 1]);
                i++;
            } else {
                break; // Kết thúc
            }
        }
    }
}

// In-place Permutations
void problem_3_solution_3() {
    const int n = 3;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    in_place_permutation(arr, n);
}
