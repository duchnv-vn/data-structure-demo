#include <iostream>

using namespace std;

bool findSumPair(const int *arr, const int n, const int target) {
    int firstPtr = 0;
    int secondPtr = n - 1;

    while (true) {
        if (firstPtr == secondPtr) return false;

        const auto sum = arr[firstPtr] + arr[secondPtr];

        if (sum == target) return true;
        if (sum < target) firstPtr++;
        if (sum > target) secondPtr++;
    }
}

int main() {
    constexpr int n = 4;
    constexpr int arr[] = {10, 20, 35, 50};
    constexpr int target = 70;
    const auto exist = findSumPair(arr, n, target);
    cout << "Exist: " << exist << endl;
    return 0;
}
