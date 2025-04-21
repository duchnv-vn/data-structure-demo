#include <iostream>
using namespace std;

void linear_search(int a[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("The element is found at %d position", i);
            count = count + 1;
        }
    }
    if (count == 0)
        printf("The element is not present in the array");
}

int main() {
    const int n = 6;
    int key;

    int a[10] = {12, 44, 32, 18, 4, 10};
    key = 18;
    linear_search(a, n, key);

    key = 23;
    linear_search(a, n, key);
    return 0;
}
