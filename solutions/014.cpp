#include <iostream>
#define N 1000000

using namespace std;

int solve() {
    uint64_t max = 0, max_n, i, c;
    int d[N] = {0};
    d[1] = 1;

    for (int n = N-1; n >= 0; n--) {
        if (d[n] == 0) {
            c = 0; i = n;
            while (i > 1) {
                if (i < N && d[i] != 0) break;
                c++;
                if (i % 2 == 0) i = i / 2;
                else i = i * 3 + 1;
            }
            d[n] = c + d[i];
        }
        if (d[n] > max) {
            max = d[n];
            max_n = n;
        }
    }

    return max_n;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
