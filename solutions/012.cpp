#include <iostream>

using namespace std;

int solve() {
    int divisors = 0;
    uint64_t n = 1, u;
    while (divisors*2 < 500) {
        divisors = 0;
        u = n*(n+1)/2;
        for (uint64_t d = 1; d*d <= u; d++) {
            if (u % d == 0) divisors++;
        }
        n++;
    }
    return u;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
