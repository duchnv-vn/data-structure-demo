#include <iostream>
using namespace std;

struct Node {
    float value;
    Node *next;

    explicit Node(const float v, Node *n = nullptr) : value(v), next(n) {
    }
};

void insertSorted(Node *&head, const float value) {
    const auto newNode = new Node(value);

    if (!head || value < head->value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next && value > current->next->value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(float input[], float output[], const int n) {
    Node *buckets[n] = {nullptr};

    for (int i = 0; i < n; i++) {
        const int idx = static_cast<int>(n * input[i]);
        insertSorted(buckets[idx], input[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        auto node = buckets[i];
        while (node) {
            output[count++] = node->value;
            node = node->next;
        }
    }
}

int main() {
    constexpr int n = 10;
    float input[n] = {0.78, 0.17, 0.93, 0.39, 0.26, 0.72, 0.21, 0.12, 0.33, 0.28};
    float output[n];

    bucketSort(input, output, n);

    cout << "Sorted array: ";
    for (const float num: output) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
