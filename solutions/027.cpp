#include <iostream>

using namespace std;

bool is_prime(int64_t n) {
    if (n <= 1) return false;
    for (int64_t i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int64_t successive_primes(int64_t a, int64_t b) {
    int64_t n = 0;
    while (is_prime(n*n+a*n+b)) n++;
    return n;
}

int64_t solve() {
    int64_t max = 0, p;
    for (int64_t a = -999; a <= 999; a++) {
        for (int64_t b = -1000; b <= 1000; b++) {
            int64_t succ = successive_primes(a, b);
            if (succ > max) {
                p = a*b;
                max = succ;
            }
        }
    }

    return p;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
