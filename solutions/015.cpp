#include <iostream>

using namespace std;

uint64_t solve() {
    int n = 21;
    uint64_t d[n][n];
    for (int i = 0; i < n; i++) {
        d[0][i] = 1;
        d[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            d[i][j] = d[i-1][j]+d[i][j-1];
        }
    }
    return d[n-1][n-1];
}

int main() {
    cout << solve() << "\n";
    return 0;
}
