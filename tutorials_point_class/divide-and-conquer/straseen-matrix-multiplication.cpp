#include  <iostream>
#include <vector>
using namespace std;

using Matrix = vector<vector<int> >;

void printMatrix(const Matrix &mat) {
    for (const auto &row: mat) {
        for (int x: row)
            cout << x << " ";
        cout << "\n";
    }
}

Matrix add(const Matrix &A, const Matrix &B) {
    const int n = A.size();
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

Matrix subtract(const Matrix &A, const Matrix &B) {
    const int n = A.size();
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

Matrix strassen(const Matrix &A, const Matrix &B) {
    const int n = A.size();

    if (n == 1) return {{A[0][0] * B[0][0]}};

    const int k = n / 2;
    Matrix A11(k, vector<int>{k}), A12(k, vector<int>{k}), A21(k, vector<int>{k}), A22(k, vector<int>{k});
    Matrix B11(k, vector<int>{k}), B12(k, vector<int>{k}), B21(k, vector<int>{k}), B22(k, vector<int>{k});

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    Matrix P1 = strassen(A11, subtract(B12, B22));
    Matrix P2 = strassen(add(A11, A12), B22);
    Matrix P3 = strassen(add(A21, A22), B11);
    Matrix P4 = strassen(A22, subtract(B21, B11));
    Matrix P5 = strassen(add(A11, A22), add(B11, B22));
    Matrix P6 = strassen(subtract(A12, A22), add(B21, B22));
    Matrix P7 = strassen(subtract(A11, A21), add(B11, B12));

    Matrix C11 = add(subtract(add(P5, P4), P2), P6);
    Matrix C12 = add(P1, P2);
    Matrix C21 = add(P3, P4);
    Matrix C22 = subtract(subtract(add(P5, P1), P3), P7);

    Matrix C(n, vector<int>(n));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }

    return C;
}

int main() {
    const Matrix A = {{1, 2}, {3, 4}};
    const Matrix B = {{5, 6}, {7, 8}};
    const Matrix C = strassen(A, B);

    cout << "Result:\n";
    printMatrix(C);

    return 0;
}
