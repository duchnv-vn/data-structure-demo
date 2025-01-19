/*
 * Viết CTC tạo ngẫu nhiên m số với miền giá trị từ 1..1000000 phân biệt khác nhau.
 * Độ phức tạp thuật toán: O(n)
 * Tổng số bước thực hiện:
 * Thời gian thực hiện: T(n) = O(n)
 *
 * Thời gian chạy chương trình thực tế:
 * 1000 numbers -> ~127 ms
 * 10000 numbers -> ~140 ms
 * 100000 numbers -> ~145 ms
 * 1000000 numbers -> ~150 ms
 */

#include <iostream>
#include <chrono>
using namespace std;

void generate_random_number_combination() {
    int m;
    cout << "Nhap m so ngau nhien muon lay ra: ";
    cin >> m;

    const auto beg = chrono::high_resolution_clock::now();

    const auto max = 1000000;
    const auto randomNums = new int[max + 1];

    // Sinh day so 0 - 1000000
    for (int i = 0; i <= max; i++) randomNums[i] = i;

    // Sap xep thu tu ngau nhien
    for (int i = 0; i <= max; i++) {
        srand(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count());
        const int randIdx = i + (rand() % (max - i + 1)); // sinh so ngau nhien trong khoang [i, max]
        const int temp = randomNums[i];
        randomNums[i] = randomNums[randIdx];
        randomNums[randIdx] = temp;
    }

    // Lay ra m so ngau nhien
    const auto arr = new int[m];
    for (int i = 0; i < m; i++) {
        arr[i] = randomNums[i];
    }

    const auto end = chrono::high_resolution_clock::now();
    const auto duration = chrono::duration_cast<chrono::milliseconds>(end - beg);
    cout << "Tong thoi gian thuc hien (ms) = " << duration.count() << endl;

    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] randomNums;
}

int main() {
    int test;
    cout << "Nhap so lan chay: ";
    cin >> test;
    while (test--) {
        generate_random_number_combination();
    }
}
