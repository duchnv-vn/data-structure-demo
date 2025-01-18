/*
* Liệt kê tần suất xuất hiện của các số trong dãy số nguyên A có n số, biết rằng Ai € [1..20].
*/

#include <iostream>
using namespace std;

void findDuplicate(const int *A, const int n) {
    int duplicateCount[21] = {0};

    for (int i = 0; i < n; i++) {
        duplicateCount[A[i]] += 1;
    }

    for (int i = 1; i < 21; i++) {
        cout << "Occurrence frequency of " << i << ": " << duplicateCount[i] << endl;
    }
}

int main() {
    const auto size = 10;
    const int numArr[] = {6, 3, 9, 2, 0, 7, 2, 6, 4, 6};
    findDuplicate(numArr, size);

    return 0;
}
