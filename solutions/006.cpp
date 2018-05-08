#include <iostream>

using namespace std;

int solve() {
    int n = 100;
    return n*n*(n+1)*(n+1)/4-n*(n+1)*(2*n+1)/6;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
