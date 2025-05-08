#include <iostream>
using namespace std;

void merge(int *arr, const int left, const int mid, const int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int *arr, const int left, const int right) {
    if (left >= right) return;

    const int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    const int n = 7;
    int arr[n] = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, n - 1);

    for (const int i: arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
