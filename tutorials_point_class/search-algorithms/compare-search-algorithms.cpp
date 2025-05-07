#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// Binary Search
int binarySearch(const vector<int>& arr, int key) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key) return m;
        if (arr[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(const vector<int>& arr, int key) {
    int l = 0, r = arr.size() - 1;
    while (l <= r && key >= arr[l] && key <= arr[r]) {
        if (l == r) {
            if (arr[l] == key) return l;
            return -1;
        }
        int pos = l + ((double)(r - l) / (arr[r] - arr[l])) * (key - arr[l]);
        if (arr[pos] == key) return pos;
        if (arr[pos] < key) l = pos + 1;
        else r = pos - 1;
    }
    return -1;
}

// Jump Search
int jumpSearch(const vector<int>& arr, int key) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while (arr[prev] < key) {
        prev++;
        if (prev == min(step, n)) return -1;
    }

    if (arr[prev] == key) return prev;
    return -1;
}

void runAndMeasure(string label, int (*searchFunc)(const vector<int>&, int), const vector<int>& arr, int key) {
    auto start = high_resolution_clock::now();
    int idx = searchFunc(arr, key);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();

    cout << label << " | Index: " << idx << " | Time: " << duration << " ns" << endl;
}

int main() {
    vector<int> sizes = {1000, 10000, 1000000};
    for (int size : sizes) {
        cout << "=== Array size: " << size << " ===" << endl;
        vector<int> arr(size);
        iota(arr.begin(), arr.end(), 1); // fill with 1..size

        int key = arr[size / 2]; // search for the middle element

        runAndMeasure("Binary Search", binarySearch, arr, key);
        runAndMeasure("Interpolation Search", interpolationSearch, arr, key);
        runAndMeasure("Jump Search", jumpSearch, arr, key);

        cout << endl;
    }
}
