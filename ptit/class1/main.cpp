#include <iostream>
#include  <unordered_map>
using namespace std;

// Bai 3
void lietKeTanSuat(int *a, int n) {
    unordered_map<int, int> bangTanSuat;

    for (int i = 0; i < n; i++) {
        int so = a[i];
        if (bangTanSuat.find(so) != bangTanSuat.end()) {
            bangTanSuat[so] += 1;
        } else {
            bangTanSuat[so] = 1;
        }
    }

    for (auto so: bangTanSuat) {
        cout << "Tan suat xuat hien cua so " << so.first << ": " << so.second << endl;
    }
}
int main() {
}

// Bai 2
// int findMinIndex(int *arr, int size) {
//     auto minIndex = 0;
//
//     for (int i = 1; i < size; i++) {
//         if (arr[i] < arr[minIndex]) {
//             minIndex = i;
//         }
//     };
//
//     return minIndex;
// }
//
// int main() {
//     auto size = 4;
//     auto arr = new int[size]{9, 5, 3, 1};
//     auto minIndex = findMinIndex(arr, size);
//     cout << "min index : " << minIndex << endl;
// }

// Bai 1
// int findMin(int *arr, int size) {
//     auto min = arr[0];
//
//     for (int i = 1; i < size; i++) {
//         if (arr[i] < min) {
//             min = arr[i];
//         }
//     }
//
//     return min;
// }
//
// int main() {
//     auto size = 4;
//     auto arr = new int[size]{9, 5, 3, 1};
//     auto min = findMin(arr, size);
//     cout << "min: " << min << endl;
// }
