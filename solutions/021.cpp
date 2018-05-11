#include <iostream>
#define N 10000

using namespace std;

int d(int n) {
    int sum = 1, i;
    for (i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (n/i != i) sum += n/i;
        }
    }
    return sum;
}

int solve() {
    int sum = 0;

    for (int n = 4; n <= N; n++) {
        int y = d(n);
        if (d(y) == n && y != n) sum += n;
    }

    return sum;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
