/*
 * Viết CTC tạo ngẫu nhiên m số với miền giá trị từ 1..1000000 phân biệt khác nhau.
 * Độ phức tạp thuật toán: O(n)
 * Tổng số bước thực hiện:
 * Thời gian thực hiện: T(n) = O(n)
 *
 * Thời gian chạy chương trình thực tế:
 * 1000 numbers -> 70 ms
 * 10000 numbers -> 75 ms
 * 100000 numbers -> 80 ms
 * 1000000 numbers -> 100 ms
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

void generateRandomNum(int *arr, const int n) {
    const auto minValue = 1;
    const auto maxValue = 1000000;
    const auto randomNums = new int [maxValue + 1];

    for (int i = minValue; i <= 1000000; i++) {
        randomNums[i] = i;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = randomNums[i];
    }

    delete [] randomNums;
}

int main() {
    const auto m = 100000;
    const auto arr = new int [m];

    const auto beg = chrono::high_resolution_clock::now();

    generateRandomNum(arr, m);

    const auto end = chrono::high_resolution_clock::now();
    const auto duration = chrono::duration_cast<chrono::milliseconds>(end - beg);
    cout << "Elapsed(ms) = " << duration.count() << endl;
    cout << "First number: " << arr[0] << endl;
    cout << "Last number: " << arr[m - 1] << endl;

    delete[] arr;
}
