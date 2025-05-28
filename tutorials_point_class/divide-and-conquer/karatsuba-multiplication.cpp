#include <iostream>
#include <cmath>
using namespace std;

int get_size(long value) {
    int count = 0;
    while (value > 0) {
        count++;
        value /= 10;
    }
    return count;
}

long karatsuba(const long X, const long Y) {
    // Base Case
    if (X < 10 && Y < 10) return X * Y;

    // determine the size of X and Y
    int size = fmax(get_size(X), get_size(Y));
    if (size < 10) return X * Y;

    // rounding up the max length
    size = (size / 2) + (size % 2);
    const long multiplier = pow(10, size);
    const long b = X / multiplier;
    const long a = X - (b * multiplier);
    const long d = Y / multiplier;
    const long c = Y - (d * size);
    const long u = karatsuba(a, c);
    const long z = karatsuba(a + b, c + d);
    const long v = karatsuba(b, d);

    return u + ((z - u - v) * multiplier) + (v * static_cast<long>(pow(10, 2 * size)));
}

int main() {
    // two numbers
    constexpr long x = 145623;
    constexpr long y = 653324;
    cout << "The final product is: " << karatsuba(x, y) << endl;
    return 0;
}
