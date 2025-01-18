/*
* Cho số tự nhiên n. Đảo các chữ số trong n.
 * Độ phức tạp thuật toán: O(n)
 * Tổng số bước thực hiện (với d là số chữ số): 14d + 5
 * Thời gian thực hiện: T(d) = O(d)
 */

#include <iostream>
#include <vector>
using namespace std;

int reverseNumber(int n) {
    vector<int> numbers;
    int count = 0;

    while (n > 0) {
        numbers.push_back(n % 10);
        n /= 10;
        count++;
    }

    if (count == 0 || count == 1) return n;

    int reversedNum = 0;
    int placeValue = 1;
    for (int i = count - 1; i >= 0; i--) {
        reversedNum += numbers[i] * placeValue;
        placeValue *= 10;
    }

    return reversedNum;
}

int main() {
    const auto originNum = 94761;
    const auto reversedNum = reverseNumber(originNum);
    cout << "Reversed number: " << reversedNum << endl;

    return 0;
}
