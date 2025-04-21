#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;

    explicit Node(const int v): value{v}, left{nullptr}, right{nullptr} {
    }
};

class BinaryTree {
};

void leastCostSearch() {
}

// Queue model - FIFO
void breadthFirstSearch() {
}

// Stack model - LIFO
void depthFirstSearch() {
}

void knapsackProblem() {
    const int N = 5, W = 10;
    int v[N] = {40, 50, 100, 95, 30};
    float w[N] = {2, 3.14, 1.98, 5, 3};
}

void insertNode(Node *(&node_ptr), const int v) {
    if (node_ptr == nullptr) {
        node_ptr = new Node{v};
    } else {
        node_ptr->value > v
            ? insertNode(node_ptr->left, v)
            : insertNode(node_ptr->right, v);
    }
}

void createBinaryTree(Node *(&root_ptr), int values[], const int N) {
    for (int i = 0; i < N; i++) {
        insertNode(root_ptr, values[i]);
    }
}

int main() {
    const int N = 5;
    int values[N] = {40, 50, 100, 95, 30};

    Node *root_ptr;
    createBinaryTree(root_ptr, values, N);
    return 0;
}
