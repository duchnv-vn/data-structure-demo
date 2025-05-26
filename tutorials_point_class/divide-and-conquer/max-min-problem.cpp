#include  <iostream>
using namespace std;

struct Result {
    int min;
    int max;
};

Result findMinMax(const int arr[], const int low, const int high) {
    if (low >= high) return {.min = arr[low], .max = arr[high]};


    Result result{};
    if (low + 1 >= high) {
        if (arr[low] > arr[high]) {
            result.min = arr[high];
            result.max = arr[low];
        } else {
            result.min = arr[low];
            result.max = arr[high];
        }

        return result;
    }


    const int mid = (low + high) / 2;
    const auto [leftMin, leftMax] = findMinMax(arr, low, mid);
    const auto [rightMin, rightMax] = findMinMax(arr, mid + 1, high);

    result.min = leftMin < rightMin ? leftMin : rightMin;
    result.max = leftMax > rightMax ? leftMax : rightMax;

    return result;
}

int main() {
    constexpr int n = 8;
    const int arr[n] = {236, 15, 333, 27, 9, 108, 76, 498};

    const auto [min,max] = findMinMax(arr, 0, n - 1);

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;

    return 0;
}
