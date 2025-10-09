#include <iostream>
#include <unordered_map>
using namespace std;

bool check_subset(const int a[], const int a_size, const int b[], const int b_size) {
    unordered_map<int, int> matching_map;

    const bool isAGreater = a >= b;
    const int *big_arr = isAGreater ? a : b;
    const int big_arr_size = isAGreater ? a_size : b_size;
    const int *small_arr = isAGreater ? b : a;
    const int small_arr_size = isAGreater ? b_size : a_size;

    for (int i = 0; i < small_arr_size; i++) {
        if (matching_map[small_arr[i]] == 0) matching_map[small_arr[i]] = 1;
    }

    for (int i = 0; i < big_arr_size; i++) {
        if (matching_map[big_arr[i]] == 1) matching_map[big_arr[i]]++;
    }

    bool isSubset = true;
    for (const auto [fst, snd]: matching_map) {
        if (snd == 1) {
            isSubset = false;
            break;
        }
    }

    return isSubset;
}

int main() {
    constexpr int arr1[] = {11, 1, 13, 21, 3, 7};
    constexpr int arr2[] = {11, 3, 7, 1};
    cout << "Result 1: " << check_subset(arr1, 6, arr2, 4) << endl;

    constexpr int arr3[] = {1, 2, 3, 4, 5, 6};
    constexpr int arr4[] = {1, 2, 4};
    cout << "Result 2: " << check_subset(arr3, 6, arr4, 3) << endl;

    constexpr int arr5[] = {10, 5, 5, 23, 19};
    constexpr int arr6[] = {19, 5, 3};
    cout << "Result 3: " << check_subset(arr5, 5, arr6, 3) << endl;

    return 0;
}
