#include <iostream>

using namespace std;

bool is_prime(uint64_t n) {
    for (uint64_t i = 2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

uint64_t solve() {
    uint64_t N = 2000000;
    uint64_t sum = 0;
    for (uint64_t n = 2; n < N; n++) {
        if (is_prime(n)) sum += n;
    }
    return sum;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
