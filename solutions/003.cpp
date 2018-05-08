#include <iostream>

using namespace std;

bool is_prime(long n) {
    for (long i = 2; i*i < n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

long solve() {
    long N = 600851475143;
    long d, f;
    for (d = 2; d < N / 2; d++) {
        if (N % d == 0) {
            f = N / d;
            if (is_prime(f)) return f;
        }
    }
    return 0;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
