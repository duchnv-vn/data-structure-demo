/*
 * Tìm 1 số trong dãy n số nguyên A có giá trị gần bằng với số nguyên x nhất (xét theo giá trị tuyệt đối).
 * Độ phức tạp thuật toán: O(n)
 * Tổng số bước thực hiện: 10n + 3
 * Thời gian thực hiện: T(n) = O(n)
 */

#include <iostream>
using namespace std;

int findClosestNumber(const int *A, const int n, const int x) {
    auto closestNum = A[0];
    auto gap = abs(x - closestNum);

    for (int i = 1; i < n; i++) {
        const auto currValue = A[i];

        if (const auto currGap = abs(x - currValue); currGap < gap) {
            closestNum = currValue;
            gap = currValue;
        }
    }

    return closestNum;
}

int main() {
}
