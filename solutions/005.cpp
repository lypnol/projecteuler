#include <iostream>

using namespace std;


// source https://en.wikipedia.org/wiki/Binary_GCD_algorithm
unsigned int gcd(unsigned int u, unsigned int v) {
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    for (shift = 0; ((u | v) & 1) == 0; ++shift) {
        u >>= 1;
        v >>= 1;
    }
    while ((u & 1) == 0) u >>= 1;
    do {
        while ((v & 1) == 0) v >>= 1;
        if (u > v) {
            unsigned int t = v; v = u; u = t;
        }
        v = v - u;
    } while (v != 0);
    return u << shift;

}

unsigned int lcm(unsigned int a, unsigned int b) {
    return a*b/gcd(a, b);
}

unsigned int lcm(unsigned int a[], size_t n, size_t i = 0) {
    if (n-i == 2) return lcm(a[i], a[i+1]);
    return lcm(a[i], lcm(a, n, i+1));
}

unsigned int solve() {
    size_t n = 20;
    unsigned int a[n];
    for (unsigned int i = 0; i <n; i++) a[i] = i+1;
    return lcm(a, n);
}

int main() {
    cout << solve() << "\n";
    return 0;
}
