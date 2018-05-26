#include <iostream>

using namespace std;

void get_digits(uint64_t n, uint64_t digits[]) {
    int k;
    for (k = 0; k < 6; k++) digits[k] = 0;
    k = 5;
    while (n > 0) {
        digits[k--] = n % 10;
        n = n / 10;
    }
}

uint64_t pow5(uint64_t d) {
    return d*d*d*d*d;
}

uint64_t solve() {
    uint64_t digits[6], sum = 0, p;
    uint64_t upperbound = pow5(9)*5;
    for (uint64_t i = 2; i <= upperbound; i++) {
        get_digits(i, digits);
        p = pow5(digits[0])+pow5(digits[1])+pow5(digits[2])+pow5(digits[3])+pow5(digits[4])+pow5(digits[5]);
        if (p == i) sum += i;
    }
    return sum;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
