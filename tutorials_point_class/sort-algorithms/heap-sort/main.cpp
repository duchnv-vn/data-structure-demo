#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    const auto temp = a;
    a = b;
    b = temp;
}

void heapify(int heap[], const int n) {
    for (int i = n - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);

        int root = 0;
        int child;
        do {
            child = 2 * root + 1; // Formulate: find left node of root element

            if ((heap[child] < heap[child + 1]) && child < (i - 1)) child++;

            if (heap[root] < heap[child] && child < i) swap(heap[root], heap[child]);

            root = child;
        } while (child < i);
    }
}

void buildMaxHeap(int heap[], const int n) {
    for (int i = 1; i < n; i++) {
        int child = i;

        do {
            const int root = (child - 1) / 2; // Formulate: find root node
            if (heap[child] > heap[root]) swap(heap[child], heap[root]); // max-heap
            child = root;
        } while (child != 0);
    }

    cout << "Heap array: ";
    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
    cout << endl;

    heapify(heap, n);
}


int main() {
    constexpr int n = 5;
    int heap[n] = {4, 10, 3, 5, 1};

    buildMaxHeap(heap, n);

    cout << "Sorted array: ";
    for (const int i: heap)
        cout << i << " ";
    cout << endl;

    return 0;
}
