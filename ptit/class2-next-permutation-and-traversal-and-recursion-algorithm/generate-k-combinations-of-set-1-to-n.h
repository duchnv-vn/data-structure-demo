// Bai toan 2: Duyet to hop chap k cua 1,2...,n
#include <iostream>
using namespace std;

#define K 3
#define N 5

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
    int arr[K]{0};
    for (int i = 0; i < K; i++) arr[i] = i + 1;

    bool OK = true;
    while (OK) {
        print_arr(arr, K);
        next_combination(arr, K, N, OK);
    }
}


void generate_combination(int com[], const int currIndex, const int prev) {
    if (currIndex >= K) {
        print_arr(com, K);
        return;
    }

    for (int i = prev + 1; i <= N - (K - 1) + currIndex; i++) {
        com[currIndex] = i;
        generate_combination(com, currIndex + 1, i);
    }
}

void problem_2_solution_2() {
    int arr[K]{0};
    generate_combination(arr, 0, 0);
}
