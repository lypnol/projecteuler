#include <iostream>

using namespace std;

bool is_prime(long n) {
    for (long i = 2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

long solve() {
    long n = 1;
    int found = 0;
    while (found < 10001) {
        n++;
        if (is_prime(n)) found++;
    }
    return n;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
