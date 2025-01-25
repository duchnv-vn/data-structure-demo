// Bai toan 1: Duyet chuoi nhi phan do dai n -> Sinh 2^n chuoi nhi nhan
#include <iostream>
using namespace std;

void print_binary(const int binary[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << binary[i] << " ";
    }
    cout << endl;
}

void next_bit_string(int binary[], const int size, bool &OK) {
    int i = size - 1;

    while (i >= 0 && binary[i] != 0) {
        binary[i] = 0;
        i--;
    }

    if (i >= 0) {
        binary[i] = 1;
    } else {
        OK = false;
    }
}

/*
    * Độ phức tạp:
    *   - Thời gian: O(2^n) vì có 2^n chuỗi nhị phân.
    *   - Không gian: O(n) cho việc lưu trữ chuỗi nhị phân.
*/
void problem_1_solution_1() {
    const int n = 4;
    int binary[n]{0};

    bool OK = true;
    while (OK) {
        print_binary(binary, n);
        next_bit_string(binary, n, OK);
    }
}

void generate_binary_string(string binary, const int n) {
    if (n == 0) {
        cout << binary << endl;
        return;
    }

    generate_binary_string(binary + "0 ", n - 1);
    generate_binary_string(binary + "1 ", n - 1);
}

/*
    * Độ phức tạp:
    *   - Thời gian: O(2^n) vì có 2^n chuỗi nhị phân.
    *   - Không gian: O(n) cho việc lưu trữ chuỗi nhị phân.
*/
void problem_1_solution_2() {
    const int n = 4;
    generate_binary_string("", n);
}
