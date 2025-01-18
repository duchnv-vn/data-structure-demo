/*
 * Viết CTC kiểm tra dãy A có n số nguyên có phải là dãy đối xứng hay không.
 * Độ phức tạp thuật toán: O(n)
 * Tổng số bước thực hiện: (5/2)n + 4
 * Thời gian thực hiện: T(n) = O(n)
 */

#include <iostream>
using namespace std;

bool checkSymmetry(const int *A, const int n) {
    auto isSym = true;
    const auto middleIndex = n / 2;

    for (int i = 0; i < middleIndex; i++) {
        if (A[i] != A[n - i - 1]) {
            isSym = false;
            break;
        }
    }

    return isSym;
}

int main() {
    const auto size1 = 7;
    const int arr1[] = {1, 2, 3, 5, 3, 2, 1};
    const auto isSymmArr1 = checkSymmetry(arr1, size1);
    cout << "Is Array 1 symmetrical: " << (isSymmArr1 == 1 ? "true" : "false") << endl;

    const auto size2 = 7;
    const int arr2[] = {1, 2, 3, 5, 2, 2, 1};
    const auto isSymmArr2 = checkSymmetry(arr2, size2);
    cout << "Is Array 2 symmetrical: " << (isSymmArr2 == 1 ? "true" : "false") << endl;

    const auto size3 = 6;
    const int arr3[] = {1, 2, 3, 2, 2, 1};
    const auto isSymmArr3 = checkSymmetry(arr3, size3);
    cout << "Is Array 3 symmetrical: " << (isSymmArr3 == 1 ? "true" : "false") << endl;

    const auto size4 = 6;
    const int arr4[] = {1, 2, 3, 3, 2, 1};
    const auto isSymmArr4 = checkSymmetry(arr4, size4);
    cout << "Is Array 4 symmetrical: " << (isSymmArr4 == 1 ? "true" : "false") << endl;

    return 0;
}
