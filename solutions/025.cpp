#include <iostream>
#include <cmath>

using namespace std;

const double phi = (1+sqrt(5.0))/2.0;
const double log10_phi = log10(phi);
const double log10_s5_2 = log10(5.0)/2.0;

uint64_t digits(uint64_t n) {
    return floor(n*log10_phi-log10_s5_2)+1;
}

uint64_t find(uint64_t n, uint64_t a = 100, uint64_t b = 5000) {
    uint64_t m = (a+b) / 2;
    uint64_t d = digits(m);
    if (d < n) return find(n, m+1, b);
    else if (d > n) return find(n, a, m);
    while (digits(--m) == n);
    return m+1;
}

uint64_t solve() {
    uint64_t n = 1000;
    return find(n);
}

int main() {
    cout << solve() << "\n";
    return 0;
}
