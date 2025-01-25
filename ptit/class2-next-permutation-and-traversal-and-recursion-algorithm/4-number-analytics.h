// Bai toan 4: Phan tich so
#include <iostream>
using namespace std;

void problem_4_solution_1() {
    const int n = 5;

    for (int i = n; i > 0; i--) {
        int arr[i];

        int s = n;
        for (int j = 0; j < i; j++) {
            arr[j] = 1;
            s -= 1;
        }
        arr[i - 1] += s;

        print_arr(arr, i);
    }
}
