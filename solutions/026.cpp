#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Source https://en.wikipedia.org/wiki/Repeating_decimal
// and https://oeis.org/A000353
int solve() {
    for (int n = 999; n > 5; n--) {
        if (is_prime(n) &&
           (n % 40 == 7 || n % 40 == 19 || n % 40 == 23) &&
           is_prime((n-1)/2)) {
            return n;
        }
    }
    return 0;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
