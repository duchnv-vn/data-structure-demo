#include <iostream>
#include <unordered_map>
using namespace std;

bool check_disjoint(const int a[], const int a_size, const int b[], const int b_size) {
    unordered_map<int, int> matching_map;

    for (int i = 0; i < a_size; i++) matching_map[a[i]] = 1;

    for (int i = 0; i < b_size; i++) if (matching_map[b[i]] == 1) return false;

    return true;
}

int main() {
    constexpr int arr1[] = {12, 34, 11, 9, 3};
    constexpr int arr2[] = {2, 1, 3, 5};
    cout << "Result 1: " << check_disjoint(arr1, 5, arr2, 4) << endl;

    constexpr int arr3[] = {12, 34, 11, 9, 3};
    constexpr int arr4[] = {7, 2, 1, 5};
    cout << "Result 2: " << check_disjoint(arr3, 6, arr4, 4) << endl;

    return 0;
}
