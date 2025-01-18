/*
 * Viết CTC kiểm tra số tự nhiên n có phải là số thuận nghịch hay không.
 * Độ phức tạp thuật toán: O(n)
 * Tổng số bước thực hiện: (15/2)n + 6
 * Thời gian thực hiện: T(n) = O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

void convertNumToArr(int n, vector<int> *arr) {
    while (n > 0) {
        arr->push_back(n % 10);
        n /= 10;
    }
}

bool checkSymmetry(int n) {
    if (n < 10)return true;

    auto isSym = true;
    vector<int> numArr;
    convertNumToArr(n, &numArr);

    const auto arrSize = numArr.size();
    const auto middleIndex = arrSize / 2;
    for (int i = 0; i < middleIndex; i++) {
        if (numArr[i] != numArr[arrSize - i - 1]) {
            isSym = false;
            break;
        }
    }

    return isSym;
}

int main() {
    const int num1 = 123454321;
    const bool isNum1Sym = checkSymmetry(num1);
    cout << "Is num 1 symmetrical: " << (isNum1Sym == 1 ? "true" : "false") << endl;

    const int num2 = 123453321;
    const bool isNum2Sym = checkSymmetry(num2);
    cout << "Is num 2 symmetrical: " << (isNum2Sym == 1 ? "true" : "false") << endl;

    const int num3 = 12343321;
    const bool isNum3Sym = checkSymmetry(num3);
    cout << "Is num 3 symmetrical: " << (isNum3Sym == 1 ? "true" : "false") << endl;

    const int num4 = 12344321;
    const bool isNum4Sym = checkSymmetry(num4);
    cout << "Is num 4 symmetrical: " << (isNum4Sym == 1 ? "true" : "false") << endl;

    return 0;
}
